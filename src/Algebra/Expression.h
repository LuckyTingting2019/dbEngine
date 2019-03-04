//
//  Expression.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Expression_h
#define Expression_h

#include <stdio.h>
#include "string"
#include "Row.h"

namespace algebra {
    
    class Expression {
    public:
        virtual std::string getType();
        
        virtual std::string findValue(const algebra::Row& row) = 0;
        virtual std::string findType() = 0;
        virtual std::string findName() = 0;
        
        void setAlias(const std::string& alias);
        const std::string& getAlias() const;

    protected:
        std::string alias;
        
    private:
        const std::string type = "Expression";
    };
    
}
#endif /* Expression_h */
