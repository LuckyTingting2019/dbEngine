//
//  Min.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Min_h
#define Min_h

#include <stdio.h>
#include "iostream"
#include "Function.h"

namespace algebra {
    class Min : public Function {
    public:
        std::string getType() override;
        std::string findName() override;
        
        Min(const std::string& name, const std::shared_ptr<algebra::Expression>& expr);
        
        void update(const algebra::Row& row) override;
        std::shared_ptr<algebra::Function> duplicate() override;
        std::string findValue() override;
        
    private:
        const std::string type = "MIN";
        int mini = INT_MAX;
        double mind = std::numeric_limits<double>::max();
        std::string mins = "";
        /*
         const std::string type = "Function";
         std::string name;
         std::shared_ptr<algebra::Expression> expr;
         
         std::shared_ptr<algebra::Column> col_ptr;
         std::string fieldType;
         */
    };
}
#endif /* Min_h */
