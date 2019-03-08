//
//  Join.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/14/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Join_h
#define Join_h

#include <stdio.h>
#include "Relation.h"
#include "string"
#include "Filter.h"
#include "Utilities.h"
#include "BoolBinaryExpr.h"
namespace algebra {
    
    class Join : public Relation {
    public:
        std::string toString() override;
        
        Join(const std::shared_ptr<algebra::Relation> left, std::shared_ptr<algebra::Relation> right, const std::string& joinType);
        
        const std::shared_ptr<algebra::Relation>& getLeft() const;
        const std::shared_ptr<algebra::Relation>& getRight() const;
        const std::string& getJoinType() const;
        const std::shared_ptr<algebra::BoolBinaryExpr>& getCondition() const;
        
        void setLeft(const std::shared_ptr<algebra::Relation>& left);
        void setRight(const std::shared_ptr<algebra::Relation>& right);
        void setJoinType(const std::string& joinType);
        void setCondition(const std::shared_ptr<algebra::BoolBinaryExpr>& condition);
        
    private:
        std::shared_ptr<algebra::Relation> left;
        std::shared_ptr<algebra::Relation> right;
        std::string joinType;
        std::shared_ptr<algebra::BoolBinaryExpr> joinCondition;
        /*
         inherited from Relation:
         std::string name;
         std::string alias;
         std::unordered_map<std::string, std::string> columnTypes;
         std::vector<algebra::Column> columns;
         std::unordered_set<std::string> tables;
         std::string type = "Relation";
         */
        
        void setSchema() override;
    }; //class Join
    
} //namespace algebra
#endif /* Join_h */
