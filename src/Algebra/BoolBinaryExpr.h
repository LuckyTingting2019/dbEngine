//
//  BoolBinaryExpr.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef BoolBinaryExpr_h
#define BoolBinaryExpr_h

#include <stdio.h>
#include "iostream"
#include "Column.h"
#include "BinaryExpr.h"
#include "Row.h"
#include "LiteralValue.h"

namespace algebra {
    class BoolBinaryExpr : public BinaryExpr {
    
    public:
        std::string getType() override;
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        std::string findName() override;
        
        
        BoolBinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right);
        
        bool evaluate(const algebra::Row& row);
        bool isSinglePredicate();
        bool isConjunctiveAndSimple();

    private:
        const std::string type = "BoolBinaryExpr";
        //Oper can be logical or comparable type
        bool isLogicalOper();
        bool evaluate(const algebra::Row& row, const std::shared_ptr<algebra::Column>& col_ptr, const std::shared_ptr<algebra::LiteralValue>& literal_ptr);
        bool evaluateComparableBoolBinaryExpr(const algebra::Row& row);
                
        int compare(const std::string& left, const std::string& right, const std::string& type);
        /*
        std::shared_ptr<algebra::Expression> left;
        std::shared_ptr<algebra::Expression> right;
        std::string oper;
        */
    };
}
    
#endif /* BoolBinaryExpr_h */
