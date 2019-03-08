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
#include "Distinct.hpp"
namespace algebra {
    
    class AlgebraTree : public Relation {
    public:
        AlgebraTree();
        AlgebraTree(queryparser::QueryParser::Select_stmtContext* tree);
        void setProj(const std::shared_ptr<algebra::Projection>& proj_ptr);
        void setRelat(const std::shared_ptr<algebra::Relation>& relation_ptr);
        void setFilter(const std::shared_ptr<algebra::Filter>& filter_ptr);
        void setGroupBy(const std::shared_ptr<algebra::GroupBy>& groupBy_ptr);
        
        std::shared_ptr<algebra::Projection>& getProj();
        std::shared_ptr<algebra::Relation>& getRelat();
        std::shared_ptr<algebra::Filter>& getFilter();
        std::shared_ptr<algebra::GroupBy>& getGroupBy();

    
    private:
        std::shared_ptr<algebra::Projection> proj_ptr; //for ProjIterator
        std::shared_ptr<algebra::Relation> relation_ptr; //for CSVIterator/JoinIterator
        std::shared_ptr<algebra::Filter> filter_ptr;  //for FilterIterator
        std::shared_ptr<algebra::GroupBy> groupBy_ptr; //for GroupByIterator
        
        const std::unordered_set<std::string> supFuncs = {"SUM", "AVG", "COUNT", "MAX", "MIN"};
        bool hasGroupBy;
        bool isSupportedFunction(const std::string& name);
        void findRelation(queryparser::QueryParser::Select_stmtContext* tree);
        std::shared_ptr<algebra::Relation> findRelation(queryparser::QueryParser::RelationContext* relat);
        std::string findJoinType(queryparser::QueryParser::Join_typeContext* typeContext);
        std::shared_ptr<algebra::Expression> findExpr(queryparser::QueryParser::ExprContext* expr);
        std::shared_ptr<algebra::LiteralValue> findLiteralValue(queryparser::QueryParser::Literal_valueContext* literal);
        std::shared_ptr<algebra::Function> findFunction(queryparser::QueryParser::FunctionContext* func);
        std::shared_ptr<algebra::Expression> findColumn(queryparser::QueryParser::ColumnContext* column);
        std::shared_ptr<algebra::BinaryExpr> findBinaryExpr(queryparser::QueryParser::ExprContext* expr);
        std::string findOper(queryparser::QueryParser::ExprContext* expr);
        std::shared_ptr<algebra::Distinct> findDistinct(queryparser::QueryParser::DistinctContext* dis);
        void findFilter(queryparser::QueryParser::Select_stmtContext* tree);
        void findProj(queryparser::QueryParser::Select_stmtContext* tree);
        void findGroupBy(queryparser::QueryParser::Select_stmtContext* tree);
        
        void setSchema() override;
        
        /* inherited from relation
         std::string name;
         std::string alias;
         std::unordered_map<std::string, std::string> columnTypes;
         std::vector<algebra::Column> columns;
         std::unordered_set<std::string> tables;
         std::string type = "Relation";
         */
        
    };
    
} //namespace algebra



#endif /* AlgebraTree_h */
