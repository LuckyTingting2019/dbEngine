//
//  AVG.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Avg_h
#define Avg_h

#include <stdio.h>
#include "iostream"
#include "Function.h"

namespace algebra {
    class Avg : public Function {
    public:
        std::string getType() override;
        std::string findName() override;
        
        Avg(const std::string& name, const std::shared_ptr<algebra::Expression>& expr);
        
        void update(const algebra::Row& row) override;
        std::shared_ptr<algebra::Function> duplicate() override;
        std::string findValue() override;
        
    private:
        const std::string type = "AVG";
        int sumi = 0;
        double sumd = 0.0;
        int count = 0;
        /*
         const std::string type = "Function";
         std::string name;
         std::shared_ptr<algebra::Expression> expr;
         
         std::shared_ptr<algebra::Column> col_ptr;
         std::string fieldType;
         */
    };
}


#endif /* Avg_h */
