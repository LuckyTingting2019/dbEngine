//
//  Row.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Row_h
#define Row_h

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include "unordered_set"

namespace algebra {

    class Row {
    public:
        Row();
        Row(const std::string& tableName);
        Row& operator=(const Row& another);

        bool put(const std::string& columnName, const std::string& value);
        std::string get(const std::string& columnName) const;
        const std::string& getTableName() const;
        const std::unordered_map<std::string, std::string>& getFields() const;
        bool containsField(const std::string& columnName) const;
        void print();
        
    private:
        std::unordered_map<std::string, std::string> fields;
        std::string tableName;
    };
}

#endif /* Row_h */
