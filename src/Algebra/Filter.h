//
//  Filter.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/12/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Filter_h
#define Filter_h

#include <stdio.h>
#include "string"
#include "Row.h"
#include "Table.h"
#include "Relation.h"
#include "BoolBinaryExpr.h"

namespace algebra {

    class Filter {
    public:
        Filter();
        Filter(const std::shared_ptr<algebra::BoolBinaryExpr>& expr);
        Filter& operator=(const Filter&);
        
        const std::shared_ptr<algebra::BoolBinaryExpr>& getExpr() const;
        void setExpr(const std::shared_ptr<algebra::BoolBinaryExpr>& expr);
        
        bool evaluate(Row& row);
        
        std::unordered_map<std::string, std::shared_ptr<algebra::Filter>> partition();
        
        void AND(std::shared_ptr<algebra::Filter>& filter);
        
    private:
        std::shared_ptr<algebra::BoolBinaryExpr> expr;
        
        std::shared_ptr<algebra::Filter> makeFilter(const std::vector<std::shared_ptr<algebra::BoolBinaryExpr>>& list);
        void getLists(const std::shared_ptr<algebra::BoolBinaryExpr>& expr, std::unordered_map<std::string, std::vector<std::shared_ptr<algebra::BoolBinaryExpr>>>& lists);
    };

} //namespace algebra


#endif /* Filter_h */
