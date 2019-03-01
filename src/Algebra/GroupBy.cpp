//
//  GroupBy.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "GroupBy.h"
const std::vector<std::shared_ptr<algebra::Column>>& algebra::GroupBy::getColumns() const {
    return this -> columns;
}
const std::vector<std::shared_ptr<algebra::Function>>& algebra::GroupBy::getFuncs() const {
    return this -> funcs;
}
void algebra::GroupBy::setColumns(const std::vector<std::shared_ptr<algebra::Column>>& columns) {
    this -> columns = columns;
}
void algebra::GroupBy::setFuncs(const std::vector<std::shared_ptr<algebra::Function>>& funcs) {
    this -> funcs = funcs;
}

void algebra::GroupBy::addColumn(const std::shared_ptr<algebra::Column>& col) {
    this -> columns.push_back(col);
}

void algebra::GroupBy::addFunc(const std::shared_ptr<algebra::Function>& func) {
    this -> funcs.push_back(func);
}
