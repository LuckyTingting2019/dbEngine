//
//  Sum.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Sum_h
#define Sum_h

#include <stdio.h>
#include "iostream"
#include "Function.h"
#include "Row.h"
#include "Column.h"

namespace algebra {
    class Sum : public Function {
    public:
        std::string getType() override;
        std::string findName() override;
        
        Sum(const std::string& name, const std::shared_ptr<algebra::Expression>& expr);
        
        void update(const algebra::Row& row) override;
        std::shared_ptr<algebra::Function> duplicate() override;
        std::string findValue() override;
        
    private:
        const std::string type = "SUM";
        int sumi = 0;
        double sumd = 0.0;
        
        /*
        std::string name;
        std::shared_ptr<algebra::Expression> expr;
         
        std::shared_ptr<algebra::Column> col_ptr;
        std::string fieldType;
        */
    };
}
#endif /* Sum_h */
