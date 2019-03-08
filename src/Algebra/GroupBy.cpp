//
//  GroupBy.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "GroupBy.h"
#include "NumericBinaryExpr.h"
#include <typeinfo>
#include "sstream"
const std::vector<std::shared_ptr<algebra::Expression>>& algebra::GroupBy::getColumns() const {
    return this -> columns;
}
const std::vector<std::shared_ptr<algebra::Function>>& algebra::GroupBy::getFuncs() const {
    return this -> funcs;
}
void algebra::GroupBy::setColumns(const std::vector<std::shared_ptr<algebra::Expression>>& columns) {
    this -> columns = columns;
}
void algebra::GroupBy::setFuncs(const std::vector<std::shared_ptr<algebra::Function>>& funcs) {
    this -> funcs = funcs;
}

void algebra::GroupBy::addColumn(const std::shared_ptr<algebra::Expression>& col) {
    if (typeid(*col).name() == typeid(algebra::Column).name() || typeid(*col).name() == typeid(algebra::NumericBinaryExpr).name()) {
        this -> columns.push_back(col);
    } else {
        throw "Unsupported group by column type: " + *(typeid(*col).name());
    }
    
}

void algebra::GroupBy::addFunc(const std::shared_ptr<algebra::Function>& func) {
    this -> funcs.push_back(func);
}

std::string algebra::GroupBy::toString() {
    std::stringstream ss;
    for (auto x : columns) {
        ss << x ->toString() << ", ";
    }
    std::string res = ss.str();
    res.pop_back();
    res.pop_back();
    return res;
}
