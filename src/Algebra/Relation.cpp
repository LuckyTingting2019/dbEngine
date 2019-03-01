//
//  Relation.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Relation.h"
#include "iostream"
const std::string& algebra::Relation::getName() const {
    return name;
}

const std::unordered_map<std::string, std::string>& algebra::Relation::getColumnTypes() const {
    return columnTypes;
}

const std::vector<algebra::Column>& algebra::Relation::getColumns() const {
    return columns;
}

void algebra::Relation::setName(const std::string& name) {
    this -> name = name;
}

void algebra::Relation::setColumnTypes(const std::unordered_map<std::string, std::string>& columnTypes) {
    this -> columnTypes = columnTypes;
}

void algebra::Relation::setColumns(const std::vector<algebra::Column>& columns) {
    this -> columns = columns;
}

void algebra::Relation::getType() {
    std::cout << "This is a relation." << std::endl;
}
