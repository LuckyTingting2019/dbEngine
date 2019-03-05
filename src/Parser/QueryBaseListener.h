
// Generated from Query.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "QueryListener.h"


namespace queryparser {

/**
 * This class provides an empty implementation of QueryListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  QueryBaseListener : public QueryListener {
public:

  virtual void enterSelect_stmt(QueryParser::Select_stmtContext * /*ctx*/) override { }
  virtual void exitSelect_stmt(QueryParser::Select_stmtContext * /*ctx*/) override { }

  virtual void enterColumns(QueryParser::ColumnsContext * /*ctx*/) override { }
  virtual void exitColumns(QueryParser::ColumnsContext * /*ctx*/) override { }

  virtual void enterColumn_alias(QueryParser::Column_aliasContext * /*ctx*/) override { }
  virtual void exitColumn_alias(QueryParser::Column_aliasContext * /*ctx*/) override { }

  virtual void enterColumn(QueryParser::ColumnContext * /*ctx*/) override { }
  virtual void exitColumn(QueryParser::ColumnContext * /*ctx*/) override { }

  virtual void enterRelation(QueryParser::RelationContext * /*ctx*/) override { }
  virtual void exitRelation(QueryParser::RelationContext * /*ctx*/) override { }

  virtual void enterJoin_operator(QueryParser::Join_operatorContext * /*ctx*/) override { }
  virtual void exitJoin_operator(QueryParser::Join_operatorContext * /*ctx*/) override { }

  virtual void enterJoin_condition(QueryParser::Join_conditionContext * /*ctx*/) override { }
  virtual void exitJoin_condition(QueryParser::Join_conditionContext * /*ctx*/) override { }

  virtual void enterJoin_type(QueryParser::Join_typeContext * /*ctx*/) override { }
  virtual void exitJoin_type(QueryParser::Join_typeContext * /*ctx*/) override { }

  virtual void enterTable(QueryParser::TableContext * /*ctx*/) override { }
  virtual void exitTable(QueryParser::TableContext * /*ctx*/) override { }

  virtual void enterAlias(QueryParser::AliasContext * /*ctx*/) override { }
  virtual void exitAlias(QueryParser::AliasContext * /*ctx*/) override { }

  virtual void enterExpr(QueryParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(QueryParser::ExprContext * /*ctx*/) override { }

  virtual void enterDistinct(QueryParser::DistinctContext * /*ctx*/) override { }
  virtual void exitDistinct(QueryParser::DistinctContext * /*ctx*/) override { }

  virtual void enterMul_div(QueryParser::Mul_divContext * /*ctx*/) override { }
  virtual void exitMul_div(QueryParser::Mul_divContext * /*ctx*/) override { }

  virtual void enterAdd_sub(QueryParser::Add_subContext * /*ctx*/) override { }
  virtual void exitAdd_sub(QueryParser::Add_subContext * /*ctx*/) override { }

  virtual void enterFunction(QueryParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(QueryParser::FunctionContext * /*ctx*/) override { }

  virtual void enterFunction_name(QueryParser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(QueryParser::Function_nameContext * /*ctx*/) override { }

  virtual void enterCompare_operator(QueryParser::Compare_operatorContext * /*ctx*/) override { }
  virtual void exitCompare_operator(QueryParser::Compare_operatorContext * /*ctx*/) override { }

  virtual void enterLiteral_value(QueryParser::Literal_valueContext * /*ctx*/) override { }
  virtual void exitLiteral_value(QueryParser::Literal_valueContext * /*ctx*/) override { }

  virtual void enterGroup_by(QueryParser::Group_byContext * /*ctx*/) override { }
  virtual void exitGroup_by(QueryParser::Group_byContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace queryparser
