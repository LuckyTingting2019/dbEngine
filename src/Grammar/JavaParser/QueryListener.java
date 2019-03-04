// Generated from Query.g4 by ANTLR 4.7.2
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link QueryParser}.
 */
public interface QueryListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link QueryParser#select_stmt}.
	 * @param ctx the parse tree
	 */
	void enterSelect_stmt(QueryParser.Select_stmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#select_stmt}.
	 * @param ctx the parse tree
	 */
	void exitSelect_stmt(QueryParser.Select_stmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#columns}.
	 * @param ctx the parse tree
	 */
	void enterColumns(QueryParser.ColumnsContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#columns}.
	 * @param ctx the parse tree
	 */
	void exitColumns(QueryParser.ColumnsContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#column_alias}.
	 * @param ctx the parse tree
	 */
	void enterColumn_alias(QueryParser.Column_aliasContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#column_alias}.
	 * @param ctx the parse tree
	 */
	void exitColumn_alias(QueryParser.Column_aliasContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#column}.
	 * @param ctx the parse tree
	 */
	void enterColumn(QueryParser.ColumnContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#column}.
	 * @param ctx the parse tree
	 */
	void exitColumn(QueryParser.ColumnContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#relation}.
	 * @param ctx the parse tree
	 */
	void enterRelation(QueryParser.RelationContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#relation}.
	 * @param ctx the parse tree
	 */
	void exitRelation(QueryParser.RelationContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#join_operator}.
	 * @param ctx the parse tree
	 */
	void enterJoin_operator(QueryParser.Join_operatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#join_operator}.
	 * @param ctx the parse tree
	 */
	void exitJoin_operator(QueryParser.Join_operatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#join_condition}.
	 * @param ctx the parse tree
	 */
	void enterJoin_condition(QueryParser.Join_conditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#join_condition}.
	 * @param ctx the parse tree
	 */
	void exitJoin_condition(QueryParser.Join_conditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#join_type}.
	 * @param ctx the parse tree
	 */
	void enterJoin_type(QueryParser.Join_typeContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#join_type}.
	 * @param ctx the parse tree
	 */
	void exitJoin_type(QueryParser.Join_typeContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#table}.
	 * @param ctx the parse tree
	 */
	void enterTable(QueryParser.TableContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#table}.
	 * @param ctx the parse tree
	 */
	void exitTable(QueryParser.TableContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#alias}.
	 * @param ctx the parse tree
	 */
	void enterAlias(QueryParser.AliasContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#alias}.
	 * @param ctx the parse tree
	 */
	void exitAlias(QueryParser.AliasContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(QueryParser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(QueryParser.ExprContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#mul_div}.
	 * @param ctx the parse tree
	 */
	void enterMul_div(QueryParser.Mul_divContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#mul_div}.
	 * @param ctx the parse tree
	 */
	void exitMul_div(QueryParser.Mul_divContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#add_sub}.
	 * @param ctx the parse tree
	 */
	void enterAdd_sub(QueryParser.Add_subContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#add_sub}.
	 * @param ctx the parse tree
	 */
	void exitAdd_sub(QueryParser.Add_subContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#function}.
	 * @param ctx the parse tree
	 */
	void enterFunction(QueryParser.FunctionContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#function}.
	 * @param ctx the parse tree
	 */
	void exitFunction(QueryParser.FunctionContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#function_name}.
	 * @param ctx the parse tree
	 */
	void enterFunction_name(QueryParser.Function_nameContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#function_name}.
	 * @param ctx the parse tree
	 */
	void exitFunction_name(QueryParser.Function_nameContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#compare_operator}.
	 * @param ctx the parse tree
	 */
	void enterCompare_operator(QueryParser.Compare_operatorContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#compare_operator}.
	 * @param ctx the parse tree
	 */
	void exitCompare_operator(QueryParser.Compare_operatorContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#literal_value}.
	 * @param ctx the parse tree
	 */
	void enterLiteral_value(QueryParser.Literal_valueContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#literal_value}.
	 * @param ctx the parse tree
	 */
	void exitLiteral_value(QueryParser.Literal_valueContext ctx);
	/**
	 * Enter a parse tree produced by {@link QueryParser#group_by}.
	 * @param ctx the parse tree
	 */
	void enterGroup_by(QueryParser.Group_byContext ctx);
	/**
	 * Exit a parse tree produced by {@link QueryParser#group_by}.
	 * @param ctx the parse tree
	 */
	void exitGroup_by(QueryParser.Group_byContext ctx);
}