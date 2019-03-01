//
//  AlgebraTree.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef AlgebraTree_h
#define AlgebraTree_h

#include <stdio.h>
#include "Projection.h"
#include "QueryParser.h"
#include "Filter.h"
#include "Relation.h"
#include "Expression.h"
#include "LiteralValue.h"
#include "Function.h"
#include "BinaryExpr.h"
#include "unordered_set"
#include "GroupBy.h"
namespace algebra {
    
    class AlgebraTree : public Relation {
    public:
        AlgebraTree(queryparser::QueryParser::Select_stmtContext* tree);
        
        std::shared_ptr<algebra::Projection> proj_ptr; //for ProjIterator
        std::shared_ptr<algebra::Relation> relation_ptr; //for CSVIterator/JoinIterator
        std::shared_ptr<algebra::Filter> filter_ptr;  //for FilterIterator
        std::shared_ptr<algebra::GroupBy> groupBy_ptr; //for GroupByIterator
        
        void getType() override;
    private:
        const std::unordered_set<std::string> supFuncs = {"SUM", "AVG", "COUNT", "MAX", "MIN"};
        bool hasGroupBy;
        bool isSupportedFunction(const std::string& name);
        void findRelation(queryparser::QueryParser::Select_stmtContext* tree);
        std::shared_ptr<algebra::Relation> findRelation(queryparser::QueryParser::RelationContext* relat);
        std::string findJoinType(queryparser::QueryParser::Join_typeContext* typeContext);
        std::shared_ptr<algebra::Expression> findExpr(queryparser::QueryParser::ExprContext* expr);
        std::shared_ptr<algebra::LiteralValue> findLiteralValue(queryparser::QueryParser::Literal_valueContext* literal);
        std::shared_ptr<algebra::Function> findFunction(queryparser::QueryParser::FunctionContext* func);
        std::shared_ptr<algebra::Column> findColumn(queryparser::QueryParser::ColumnContext* column);
        std::shared_ptr<algebra::BinaryExpr> findBinaryExpr(queryparser::QueryParser::ExprContext* expr);
        std::string findOper(queryparser::QueryParser::ExprContext* expr);
        void findFilter(queryparser::QueryParser::Select_stmtContext* tree);
        void findProj(queryparser::QueryParser::Select_stmtContext* tree);
        void findGroupBy(queryparser::QueryParser::Select_stmtContext* tree);
        
        /* inherited from relation
        std::string name;
        std::unordered_map<std::string, std::string> columnTypes;
        std::vector<algebra::Column> columns;
         */
        
        //algebra::Filter findJoinCondition(queryparser::QueryParser::Join_conditionContext* JoinConContext);
        //findFilterOper(queryparser::QueryParser::Compare_operatorContext* operContext);
        //std::shared_ptr<algebra::Filter> findFilter(queryparser::QueryParser::ExprContext *expr);
        //std::shared_ptr<algebra::Filter> findSubFilter(queryparser::QueryParser::ExprContext* expr);
        //std::string findFilterValue(queryparser::QueryParser::Literal_valueContext* valueContext);
        //std::string findLeftOp(queryparser::QueryParser::ColumnContext* columnContext);
        //std::string findRightOp(queryparser::QueryParser::ExprContext* exprContext);
        
    };
    
} //namespace algebra



#endif /* AlgebraTree_h */
