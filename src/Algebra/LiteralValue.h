//
//  LiteralValue.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef LiteralValue_h
#define LiteralValue_h

#include <stdio.h>
#include "iostream"
#include "Expression.h"
namespace algebra {
    class LiteralValue : public Expression {
    public:
        std::string getType() override;
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        std::string findName() override;
        std::unordered_set<std::string> getReferencedTables() override;
        bool isSimple() override;
        
        LiteralValue(const std::string& value, const std::string& fieldType);
        
        void setFieldType(const std::string& fieldType);
        void setValue(const std::string& value);
        const std::string& getFieldType() const;
        const std::string& getValue() const;
        
    private:
        //type is numberic, string, or null
        std::string value;
        std::string fieldType;
        const std::string type = "LiteralValue";
    };
}

#endif /* LiteralValue_h */
