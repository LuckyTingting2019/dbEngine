
// Generated from Query.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryParser.h"


namespace queryparser {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by QueryParser.
 */
class  QueryVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by QueryParser.
   */
    virtual antlrcpp::Any visitSelect_stmt(QueryParser::Select_stmtContext *context) = 0;

    virtual antlrcpp::Any visitColumns(QueryParser::ColumnsContext *context) = 0;

    virtual antlrcpp::Any visitColumn_alias(QueryParser::Column_aliasContext *context) = 0;

    virtual antlrcpp::Any visitColumn(QueryParser::ColumnContext *context) = 0;

    virtual antlrcpp::Any visitRelation(QueryParser::RelationContext *context) = 0;

    virtual antlrcpp::Any visitJoin_operator(QueryParser::Join_operatorContext *context) = 0;

    virtual antlrcpp::Any visitJoin_condition(QueryParser::Join_conditionContext *context) = 0;

    virtual antlrcpp::Any visitJoin_type(QueryParser::Join_typeContext *context) = 0;

    virtual antlrcpp::Any visitTable(QueryParser::TableContext *context) = 0;

    virtual antlrcpp::Any visitAlias(QueryParser::AliasContext *context) = 0;

    virtual antlrcpp::Any visitExpr(QueryParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitDistinct(QueryParser::DistinctContext *context) = 0;

    virtual antlrcpp::Any visitMul_div(QueryParser::Mul_divContext *context) = 0;

    virtual antlrcpp::Any visitAdd_sub(QueryParser::Add_subContext *context) = 0;

    virtual antlrcpp::Any visitFunction(QueryParser::FunctionContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(QueryParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitCompare_operator(QueryParser::Compare_operatorContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_value(QueryParser::Literal_valueContext *context) = 0;

    virtual antlrcpp::Any visitGroup_by(QueryParser::Group_byContext *context) = 0;


};

}  // namespace queryparser
