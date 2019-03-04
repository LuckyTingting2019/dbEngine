
// Generated from Query.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryParser.h"


namespace queryparser {

/**
 * This interface defines an abstract listener for a parse tree produced by QueryParser.
 */
class  QueryListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterSelect_stmt(QueryParser::Select_stmtContext *ctx) = 0;
  virtual void exitSelect_stmt(QueryParser::Select_stmtContext *ctx) = 0;

  virtual void enterColumns(QueryParser::ColumnsContext *ctx) = 0;
  virtual void exitColumns(QueryParser::ColumnsContext *ctx) = 0;

  virtual void enterColumn_alias(QueryParser::Column_aliasContext *ctx) = 0;
  virtual void exitColumn_alias(QueryParser::Column_aliasContext *ctx) = 0;

  virtual void enterColumn(QueryParser::ColumnContext *ctx) = 0;
  virtual void exitColumn(QueryParser::ColumnContext *ctx) = 0;

  virtual void enterRelation(QueryParser::RelationContext *ctx) = 0;
  virtual void exitRelation(QueryParser::RelationContext *ctx) = 0;

  virtual void enterJoin_operator(QueryParser::Join_operatorContext *ctx) = 0;
  virtual void exitJoin_operator(QueryParser::Join_operatorContext *ctx) = 0;

  virtual void enterJoin_condition(QueryParser::Join_conditionContext *ctx) = 0;
  virtual void exitJoin_condition(QueryParser::Join_conditionContext *ctx) = 0;

  virtual void enterJoin_type(QueryParser::Join_typeContext *ctx) = 0;
  virtual void exitJoin_type(QueryParser::Join_typeContext *ctx) = 0;

  virtual void enterTable(QueryParser::TableContext *ctx) = 0;
  virtual void exitTable(QueryParser::TableContext *ctx) = 0;

  virtual void enterAlias(QueryParser::AliasContext *ctx) = 0;
  virtual void exitAlias(QueryParser::AliasContext *ctx) = 0;

  virtual void enterExpr(QueryParser::ExprContext *ctx) = 0;
  virtual void exitExpr(QueryParser::ExprContext *ctx) = 0;

  virtual void enterMul_div(QueryParser::Mul_divContext *ctx) = 0;
  virtual void exitMul_div(QueryParser::Mul_divContext *ctx) = 0;

  virtual void enterAdd_sub(QueryParser::Add_subContext *ctx) = 0;
  virtual void exitAdd_sub(QueryParser::Add_subContext *ctx) = 0;

  virtual void enterFunction(QueryParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(QueryParser::FunctionContext *ctx) = 0;

  virtual void enterFunction_name(QueryParser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(QueryParser::Function_nameContext *ctx) = 0;

  virtual void enterCompare_operator(QueryParser::Compare_operatorContext *ctx) = 0;
  virtual void exitCompare_operator(QueryParser::Compare_operatorContext *ctx) = 0;

  virtual void enterLiteral_value(QueryParser::Literal_valueContext *ctx) = 0;
  virtual void exitLiteral_value(QueryParser::Literal_valueContext *ctx) = 0;

  virtual void enterGroup_by(QueryParser::Group_byContext *ctx) = 0;
  virtual void exitGroup_by(QueryParser::Group_byContext *ctx) = 0;


};

}  // namespace queryparser
