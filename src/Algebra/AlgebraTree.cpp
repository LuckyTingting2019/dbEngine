//
//  AlgebraTree.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "AlgebraTree.h"
#include "Table.h"
#include "Join.h"
#include "sstream"
#include "Schema.h"
#include "NumericBinaryExpr.h"
#include "BoolBinaryExpr.h"
#include "Sum.h"
#include "Avg.h"
#include "Count.h"
#include "Min.h"
#include "Max.h"
#include "Trees.h"
void algebra::AlgebraTree::getType() {
    std::cout << "This is an algebraTree." << std::endl;
}

algebra::AlgebraTree::AlgebraTree(queryparser::QueryParser::Select_stmtContext* tree) {
    if (tree -> group_by()) {
        hasGroupBy = true;
    }
    findRelation(tree);
    findProj(tree);
    findFilter(tree);
    findGroupBy(tree);
}

bool algebra::AlgebraTree::isSupportedFunction(const std::string& name) {
    return supFuncs.find(name) != supFuncs.end();
}

void algebra::AlgebraTree::findRelation(queryparser::QueryParser::Select_stmtContext *tree) {
    this -> relation_ptr = findRelation(tree -> relation());
}

std::shared_ptr<algebra::Relation> algebra::AlgebraTree::findRelation(queryparser::QueryParser::RelationContext* relat) {
    if (relat -> table()) {
        std::string tableName = relat -> table() -> Name() -> getText();
        algebra::Table table(tableName);
        if (relat -> AS()) {
            table.setAlias(relat -> alias() -> Name() -> getText());
        }
        Schema::addTable(table);
        return std::make_shared<algebra::Table>(table);
    } else if (relat -> join_operator()) {
        std::shared_ptr<algebra::Relation> left = findRelation(relat -> relation(0));
        std::shared_ptr<algebra::Relation> right = findRelation(relat -> relation(1));
        std::string joinType = findJoinType(relat -> join_operator() -> join_type());
        std::shared_ptr<algebra::Join> join_ptr = std::make_shared<algebra::Join>(left, right, joinType);
        if (relat -> AS()) {
            std::string alias = relat -> alias() -> Name() -> getText();
            join_ptr -> setAlias(alias);
            Schema::addTableAlias(alias, "any");
        }
        if (relat -> join_condition()) {
            join_ptr -> setCondition(std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(findExpr(relat -> join_condition() -> expr())));
        }
        if (joinType == "NATURAL") {
            Schema::setIsNaturalJoin(true);
        }
        return join_ptr;
    } else if (relat -> select_stmt()) {
        std::shared_ptr<algebra::AlgebraTree> algebraTree = std::make_shared<algebra::AlgebraTree>(relat -> select_stmt());
        if (relat -> AS()) {
            std::string alias = relat -> alias() -> Name() -> getText();
            algebraTree -> setAlias(alias);
            Schema::addTableAlias(alias, "any");
        }
        return algebraTree;
    } else {
        throw "Unsupported relation: " + relat -> getText();
    }
}

std::shared_ptr<algebra::Expression> algebra::AlgebraTree::findExpr(queryparser::QueryParser::ExprContext* expr) {
    std::string alias;
    if (expr -> literal_value()) {
        return findLiteralValue(expr -> literal_value());
    } else if (expr -> column()) {
        return findColumn(expr -> column());
    } else if (expr -> function()) {
        return findFunction(expr -> function());
    } else if (expr -> add_sub() || expr -> mul_div() || expr -> compare_operator() || expr -> AND() || expr -> OR()) {
        return findBinaryExpr(expr);
    } else {
        throw "Unrecongnized expression: " + expr -> getText();
    }
}

std::shared_ptr<algebra::LiteralValue> algebra::AlgebraTree::findLiteralValue(queryparser::QueryParser::Literal_valueContext* literal) {
    std::string value;
    std::string fieldType;
    if (literal -> NUMERIC_LITERAL()) {
        value = literal -> NUMERIC_LITERAL() -> getText();
        fieldType = value.find('.') == std::string::npos && value.find('e') == std::string::npos && value.find('E') == std::string::npos ? "int" : "float";
    } else if (literal -> STRING_LITERAL()) {
        value = literal -> STRING_LITERAL() -> getText();
        value = value.substr(1, value.length() - 2);
        fieldType = "varchar";
    } else {
        value = "NULL";
        fieldType = "NULL";
    }
    return std::make_shared<algebra::LiteralValue>(value, fieldType);
}

std::shared_ptr<algebra::Function> algebra::AlgebraTree::findFunction(queryparser::QueryParser::FunctionContext* func) {
    std::shared_ptr<algebra::Function> function;
    if (func -> function_name() -> SUM()) {
        function = std::make_shared<algebra::Sum>("SUM", findExpr(func -> expr(0)));
    } else if (func -> function_name() -> AVG()) {
        function = std::make_shared<algebra::Avg>("AVG", findExpr(func -> expr(0)));
    } else if (func -> function_name() -> COUNT()) {
        function = std::make_shared<algebra::Count>("COUNT", findExpr(func -> expr(0)));
    } else if (func -> function_name() -> MIN()) {
        function = std::make_shared<algebra::Min>("MIN", findExpr(func -> expr(0)));
    } else if (func -> function_name() -> MAX()) {
        function = std::make_shared<algebra::Max>("MAX", findExpr(func -> expr(0)));
    } else {
        throw "Unsupported function: " + func -> function_name() -> getText();
    }
    if (hasGroupBy) {
        if (!groupBy_ptr) {
            groupBy_ptr = std::make_shared<algebra::GroupBy>();
        }
        groupBy_ptr -> addFunc(function);
    }
    return function;
}

std::shared_ptr<algebra::Expression> algebra::AlgebraTree::findColumn(queryparser::QueryParser::ColumnContext* column) {
    std::string tableName;
    std::string colName;
    std::string colType;
    if (column -> Name()) {
        colName = column -> Name() -> getText();
        if (Schema::isNameExprAlias(colName)) {
            return Schema::getExprFromAlias(colName);
        }
    }
    if (column -> table()) {
        tableName = column -> table() -> Name() -> getText();
        if (Schema::isNameTableAlias(tableName)) {
            tableName = Schema::getTableNameFromAlias(tableName);
            if (tableName == "any") {
                tableName = Schema::findTableName(colName);
            }
        }
    } else {
        tableName = Schema::findTableName(colName);
    }
    colType = Schema::findColType(tableName, colName);
    //colType = Schema::findColType(colName);
    return std::make_shared<algebra::Column>(tableName, colName, colType);
}

std::shared_ptr<algebra::BinaryExpr> algebra::AlgebraTree::findBinaryExpr(queryparser::QueryParser::ExprContext* expr) {
    if (expr -> add_sub() || expr -> mul_div()) {
        return std::make_shared<algebra::NumericBinaryExpr>(findExpr(expr -> expr(0)), findOper(expr), findExpr(expr -> expr(1)));
    } else {
        return std::make_shared<algebra::BoolBinaryExpr>(findExpr(expr -> expr(0)), findOper(expr), findExpr(expr -> expr(1)));
    }
}

std::string algebra::AlgebraTree::findOper(queryparser::QueryParser::ExprContext* expr) {
    if (expr -> AND()) {
        return "AND";
    } else if (expr -> OR()) {
        return "OR";
    } else if (expr -> add_sub()) {
        if (expr -> add_sub() -> ADD()) {
            return "+";
        } else if (expr -> add_sub() -> SUB()) {
            return "-";
        } else {
            throw "unrecognized numeric operator: " + expr -> add_sub() -> getText();
        }
    } else if (expr -> mul_div()) {
        if (expr -> mul_div() -> MUL()) {
            return "*";
        } else if (expr -> mul_div() -> DIV()) {
            return "/";
        } else {
            throw "unrecognized numeric operator: " + expr -> mul_div() -> getText();
        }
    } else if (expr -> compare_operator()) {
        if (expr -> compare_operator() -> GTEQ()) {
            return ">=";
        } else if (expr -> compare_operator() -> NEQ()) {
            return "<>";
        } else if (expr -> compare_operator() -> EQ()) {
            return "=";
        } else if (expr -> compare_operator() -> LTEQ()) {
            return "<=";
        } else if (expr -> compare_operator() -> LT()) {
            return "<";
        } else if (expr -> compare_operator() -> GT()) {
            return ">";
        } else if (expr -> compare_operator() -> IS()) {
            return "IS";
        } else {
            throw "unrecognized compare operator: " + expr -> compare_operator() -> getText();
        }
    } else {
        throw "unrecognized operator: " + expr -> getText();
    }
}

std::string algebra::AlgebraTree::findJoinType(queryparser::QueryParser::Join_typeContext* typeContext) {
    //std::cout << typeContext -> getText() << std::endl;
    std::string joinType;
    if (typeContext -> INNER()) {
        joinType = "INNER";
    } else if (typeContext -> LEFT()) {
        joinType = "LEFT";
    } else if (typeContext -> RIGHT()) {
        joinType = "RIGHT";
    } else if (typeContext -> NATURAL()) {
        joinType = "NATURAL";
    } else {
        std::cout << "Unsupported join type!!!" << std::endl;
    }
    return joinType;
}

void algebra::AlgebraTree::findFilter(queryparser::QueryParser::Select_stmtContext *tree) {
    if (tree -> WHERE()) {
        this -> filter_ptr = std::make_shared<algebra::Filter>(std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(findExpr(tree -> expr())));
    }
}

void algebra::AlgebraTree::findProj(queryparser::QueryParser::Select_stmtContext *tree) {
    std::vector<queryparser::QueryParser::Column_aliasContext *> colAliasContext = tree -> columns() -> column_alias();
    std::vector<std::shared_ptr<algebra::Expression>> columns;
    size_t num = colAliasContext.size();
    std::string alias;
    queryparser::QueryParser::ExprContext *expr;
    for (size_t i = 0; i < num; i++) {
        expr = colAliasContext[i] -> expr();
        //when there is a '*'
        if (expr -> column() && expr -> column() -> MUL()) {
            //when it is table.*
            if (expr -> column() -> table()) {
                std::string tableName = expr -> column() -> table() -> Name() -> getText();
                for (auto x: Schema::getColumns()) {
                    if (tableName == x.first) {
                        for (auto y : x.second) {
                            columns.push_back(std::make_shared<algebra::Column>(y));
                        }
                    }
                }
            } else {
                for (auto x : Schema::getColumns()) {
                    for (auto y : x.second) {
                        columns.push_back(std::make_shared<algebra::Column>(y));
                    }
                }
            }
        } else {
            std::shared_ptr<algebra::Expression> expr_result = findExpr(expr);
            if (colAliasContext[i] -> alias()) {
                alias = colAliasContext[i] -> alias() -> Name() -> getText();
                expr_result -> setAlias(alias);
                Schema::addExprAlias(alias, expr_result);
            }
            columns.push_back(expr_result);
        }
    }
    if (Schema::getIsNaturalJoin()) {
        Utilities::deduplicate(columns);
    }
    this -> proj_ptr = std::make_shared<algebra::Projection>(columns);
}

void algebra::AlgebraTree::findGroupBy(queryparser::QueryParser::Select_stmtContext *tree) {
    if (!tree -> group_by()) {
        return;
    }
    if (!groupBy_ptr) {
        groupBy_ptr = std::make_shared<algebra::GroupBy>();
    }
    std::vector<queryparser::QueryParser::Column_aliasContext *> colAliasContext = tree -> group_by() -> columns() -> column_alias();
    for (auto x : colAliasContext) {
        groupBy_ptr -> addColumn(findExpr(x -> expr()));
    }
    /*
    for (auto x : proj_ptr -> getColumns()) {
        std::shared_ptr<algebra::Function> func = std::dynamic_pointer_cast<algebra::Function>(x);
        if (func) {
            groupBy_ptr -> addFunc(func);
        }
    }
    */
}

/*
algebra::Filter algebra::AlgebraTree::findJoinCondition(queryparser::QueryParser::Join_conditionContext* JoinConContext) {
    queryparser::QueryParser::ExprContext* expr = JoinConContext -> expr();
    queryparser::QueryParser::ColumnContext* column = expr -> expr(0) -> column();
    std::stringstream ss;
    ss << column -> table() -> Name() -> getText();
    ss << ".";
    ss << column -> Name() -> getText();
    std::string leftOp = ss.str();
    
    column = expr -> expr(1) -> column();
    ss.str(std::string());
    ss << column -> table() -> Name() -> getText();
    ss << ".";
    ss << column -> Name() -> getText();
    std::string rightOp = ss.str();
    
    std::string oper = findFilterOper(expr -> compare_operator());
    
    bool condition = true;
    Filter leaf(leftOp, oper, rightOp, condition);
    return leaf;
}


std::string algebra::AlgebraTree::findFilterOper(queryparser::QueryParser::Compare_operatorContext* operContext) {
    std::string oper = "";
    if (operContext -> GTEQ()) {
        oper = operContext -> GTEQ() -> getText();
    } else if (operContext -> NEQ()) {
        oper = operContext -> NEQ() -> getText();
    } else if (operContext -> EQ()) {
        oper = operContext -> EQ() -> getText();
    } else if (operContext -> LTEQ()) {
        oper = operContext -> LTEQ() -> getText();
    } else if (operContext -> LT()) {
        oper = operContext -> LT() -> getText();
    } else if (operContext -> GT()) {
        oper = operContext -> GT() -> getText();
    } else if (operContext -> IS()) {
        oper = operContext -> IS() -> getText();
    }
    return oper;
}

 std::shared_ptr<algebra::Filter> algebra::AlgebraTree::findFilter(queryparser::QueryParser::ExprContext *expr) {
 std::shared_ptr<algebra::Filter> root = std::make_shared<algebra::Filter>();
 if (expr -> AND()) {
 //cout << "Get And or OR" << endl;
 root -> setLeft(findFilter(expr -> expr(0)));
 root -> setRight(findFilter(expr -> expr(1)));
 if (expr -> AND()) {
 //cout << "Get AND" << endl;
 root -> setLogic("AND");
 } else {
 //cout << "Get OR" << endl;
 root -> setLogic("OR");
 }
 } else {
 //cout << "Get Leaf" << endl;
 root = findSubFilter(expr);
 }
 return root;
 }
 
 std::shared_ptr<algebra::Filter> algebra::AlgebraTree::findSubFilter(queryparser::QueryParser::ExprContext* expr) {
 std::string leftOp = findLeftOp(expr -> expr(0) -> column());
 std::string oper = findFilterOper(expr -> compare_operator());
 std::string rightOp = findRightOp(expr -> expr(1));
 bool condition = expr -> expr(1) -> column();
 std::shared_ptr<algebra::Filter> leaf = std::make_shared<algebra::Filter>(leftOp, oper, rightOp, condition, *this -> relation_ptr);
 return leaf;
 }
 
 std::string algebra::AlgebraTree:: findLeftOp(queryparser::QueryParser::ColumnContext* columnContext) {
 std::stringstream ss;
 if (columnContext -> table()) {
 ss << columnContext -> table() -> Name() -> getText();
 ss << "." << columnContext -> Name() -> getText();
 } else {
 ss << columnContext -> Name() -> getText();
 }
 return  schema.findMatchedName(ss.str());
 }
 
 std::string algebra::AlgebraTree::findRightOp(queryparser::QueryParser::ExprContext* exprContext) {
 if (exprContext -> column()) {
 return findLeftOp(exprContext -> column());
 } else {
 std::string value;
 queryparser::QueryParser::Literal_valueContext* valueContext = exprContext -> literal_value();
 if (valueContext -> NUMERIC_LITERAL()) {
 value = valueContext -> NUMERIC_LITERAL() -> getText();
 } else if (valueContext -> STRING_LITERAL()) {
 value = valueContext -> STRING_LITERAL() -> getText();
 value = value.substr(1, value.length() - 2);
 }
 return value;
 }
 }
 
 void algebra::AlgebraTree::findProj(queryparser::QueryParser::Select_stmtContext *tree) {
 queryparser::QueryParser::ColumnsContext* columnsContext = tree -> columns();
 std::vector<queryparser::QueryParser::ColumnContext *> columnContexts = columnsContext -> column();
 std::vector<std::string> columns;
 size_t num = columnContexts.size();
 std::string colText;
 for (size_t i = 0; i != num; i++) {
 colText = columnContexts[i] -> getText();
 if (colText.find('*') != std::string::npos) {
 if (colText.find('.') == std::string::npos) {//do not have table name
 for (std::string x : relation_ptr -> getColumns()) {
 columns.push_back(schema.findMatchedName(x));
 }
 } else {
 std::string tableName = Utilities::split(colText, '.')[0];
 for (auto x : schema.getColumns().at(tableName)) {
 columns.push_back(schema.findMatchedName(x));
 }
 }
 } else {
 columns.push_back(findLeftOp(columnContexts[i]));
 }
 }
 //columns should be copied to columns, so should exist even goes out of the current scope
 proj.setColumns(columns);
 proj.setRelation(*relation_ptr);
 }
*/
