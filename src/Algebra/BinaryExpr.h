//
//  BinaryExpr.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef BinaryExpr_h
#define BinaryExpr_h

#include <stdio.h>
#include "iostream"
#include "Expression.h"

namespace algebra {
    class BinaryExpr : public Expression {
    public:
        std::string getType() override;
        std::unordered_set<std::string> getReferencedTables() override;
        bool isSimple() override;
        std::string findName() override;
        //std::string toString() override;
        
        BinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right);
        
        const std::shared_ptr<algebra::Expression>& getLeft() const;
        const std::shared_ptr<algebra::Expression>& getRight() const;
        const std::string& getOper() const;
        void setLeft(const std::shared_ptr<algebra::Expression>& left);
        void setRight(const std::shared_ptr<algebra::Expression>& right);
        void setOper(const std::string& oper);

    protected:
        std::shared_ptr<algebra::Expression> left;
        std::shared_ptr<algebra::Expression> right;
        std::string oper;
        
    private:
        const std::string type = "BinaryExpr";
        
        
    };
}

#endif /* BinaryExpr_h */
