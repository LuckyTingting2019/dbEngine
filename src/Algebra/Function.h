//
//  Function.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Function_h
#define Function_h

#include <stdio.h>
#include "iostream"
#include "Expression.h"
#include "Row.h"
#include "Column.h"
namespace algebra {
    class Function : public Expression {
    public:
        std::string getType() override;
        //This is find the value in row, different from find the current value of the function.
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        std::string findName() override;
        std::unordered_set<std::string> getReferencedTables() override;
        bool isSimple() override;
        //std::string toString() override;
        
        Function(const std::string& name, const std::shared_ptr<algebra::Expression>& expr);
        
        const std::string& getName() const;
        const std::shared_ptr<algebra::Expression>& getExpr() const;
        void setName(const std::string& name);
        void setExpr(const std::shared_ptr<algebra::Expression>& expr);

        virtual void update(const algebra::Row& row) = 0;
        virtual std::shared_ptr<algebra::Function> duplicate() = 0;
        virtual std::string findValue() = 0;
        
        
    protected:
        std::string name;
        //expr here only support column
        std::shared_ptr<algebra::Expression> expr;
        
        std::shared_ptr<algebra::Column> col_ptr;
        std::string fieldType;

        std::string type = "Function";
        
    };
}
#endif /* Function_h */
