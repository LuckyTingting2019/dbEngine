//
//  NumericBinaryExpr.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef NumericBinaryExpr_h
#define NumericBinaryExpr_h

#include <stdio.h>
#include "iostream"
#include "BinaryExpr.h"
namespace algebra {
    class NumericBinaryExpr : public BinaryExpr {
    
    public:
        std::string getType() override;
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        //std::string findName() override;
        
        NumericBinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right);
        
    private:
        const std::string type = "NumericBinaryExpr";
        /*
        std::shared_ptr<algebra::Expression> left;
        std::shared_ptr<algebra::Expression> right;
        std::string oper;
        */
    };
}
#endif /* NumericBinaryExpr_h */
