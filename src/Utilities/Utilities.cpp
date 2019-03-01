//
//  Untilities.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/17/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Utilities.h"
#include "Column.h"
#include "unordered_set"
#include "iostream"
std::vector<std::string> Utilities::split(const std::string& input, const char& delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(input);
    while (getline(tokenStream, token, delimiter))
    {
        if (token[0] == '\xef') {
            token.erase(0, 3);
        }
        token.erase(token.find_last_not_of(" \n\t\r\f\v") + 1);
        tokens.push_back(token);
    }
    return tokens;
}

void Utilities::deduplicate(std::vector<std::shared_ptr<algebra::Expression>>& cols) {
    std::unordered_set<std::string> set;
    std::shared_ptr<algebra::Column> col;
    for (auto iter = cols.begin(); iter != cols.end(); iter++) {
        col = std::dynamic_pointer_cast<algebra::Column>(*iter);
        if (col && !set.insert(col -> getColumnName() + ":" + col -> getFieldType()).second) {
            iter = cols.erase(iter);
        }
    }
}
