//
//  BoolBinaryExpr.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "BoolBinaryExpr.h"
#include "Schema.h"
std::string algebra::BoolBinaryExpr::getType() {
    return this -> type;
}

std::string algebra::BoolBinaryExpr::findValue(const algebra::Row& row) {
    return std::to_string(evaluate(row));
}
std::string algebra::BoolBinaryExpr::findType() {
    return "bool";
}
std::string algebra::BoolBinaryExpr::findName() {
    return left -> findName() + " " + oper + " " + right -> findName();
}

algebra::BoolBinaryExpr::BoolBinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right) : algebra::BinaryExpr(left, oper, right) {}

bool algebra::BoolBinaryExpr::evaluate(const algebra::Row &row) {
    if (isLogicalOper()) {
        bool bl = std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(this -> left) -> evaluate(row);
        bool br = std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(this -> right) -> evaluate(row);
        return this -> oper == "AND" ? bl && br : bl || br;
    } else {
        return evaluateComparableBoolBinaryExpr(row);
    }
}

bool algebra::BoolBinaryExpr::evaluateComparableBoolBinaryExpr(const algebra::Row &row) {
    //means the operator is comparable operator
    //left could be literal (int, float, string), column (int, float, string), numericExpr (float, int), function(float, int)
    //right could be literal (int, float, string), column, numericExpr, function
    //But this compare method is only used in filter, so only column and literal are supported here. And one if column, one is literal
    
    std::string left = this -> left -> findValue(row);
    std::string right = this -> right -> findValue(row);
    std::string typel = this -> left -> findType();
    std::string typer = this -> right -> findType();
    std::string type;
    if (typel == typer) {
        type = typel;
    } else if (typel == "varchar" || typer == "varchar") {
        throw "Not comparable left and right value types: " + typel + ", " + typer;
    } else {
        type = "float";
    }
    if (left == "NULL" || right == "NULL") {
        return left == right;
    }
    int value = compare(left, right, type);
    if (oper == "=" || oper == "IS") {
        return value == 0;
    } else if (oper == "<>") {
        return value != 0;
    } else if (oper == ">") {
        return value > 0;
    } else if (oper == ">=") {
        return value >= 0;
    } else if (oper == "<") {
        return value < 0;
    } else if (oper == "<=") {
        return value <= 0;
    } else {
        throw "Unsupported operator: " + oper;
    }
}

int algebra::BoolBinaryExpr::compare(const std::string& left, const std::string& right, const std::string& type) {
    if (type == "varchar") {
        return left.compare(right);
    } else if (type == "int") {
        int left_i = std::stoi(left);
        int right_i = std::stoi(right);
        return left_i == right_i ? 0 : left_i < right_i ? -1 : 1;
    } else if (type == "float") {
        double left_d = std::stod(left);
        double right_d = std::stod(right);
        return left_d == right_d ? 0 : left_d < right_d ? -1 : 1;
    } else {
        throw "Unsupported data type in comparable boolean binary expression.";
    }
}

bool algebra::BoolBinaryExpr::isLogicalOper() {
    return this -> oper == "AND" || this -> oper == "OR";
}

bool algebra::BoolBinaryExpr::isSinglePredicate() {
    return !isLogicalOper();
}

bool algebra::BoolBinaryExpr::isConjunctiveAndSimple() {
    if (oper == "OR") {
        return false;
    } else if (oper == "AND") {
        bool res = false;
        if (left -> getType() == "BoolBinaryExpr") {
            res = std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(left) -> isConjunctiveAndSimple();
        } else {
            res = left -> isSimple();
        }
        if (right -> getType() == "BoolBinaryExpr") {
            res = res && std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(right) -> isConjunctiveAndSimple();
        } else {
            res = res && right -> isSimple();
        }
        return res;
    } else {
        return this -> isSimple();
    }
}
