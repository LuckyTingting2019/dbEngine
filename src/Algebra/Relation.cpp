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

const std::string& algebra::Relation::getAlias() const {
    return alias;
}

const std::unordered_map<std::string, std::string>& algebra::Relation::getColumnTypes() const {
    return columnTypes;
}

const std::vector<algebra::Column>& algebra::Relation::getColumns() const {
    return columns;
}

const std::unordered_set<std::string>& algebra::Relation::getTables() const {
    return tables;
}

bool algebra::Relation::addTable(const std::string &name) {
    return tables.insert(name).second;
}

bool algebra::Relation::isInTables(const std::string &name) {
    return tables.find(name) != tables.end();
}

void algebra::Relation::setName(const std::string& name) {
    this -> name = name;
}

void algebra::Relation::setAlias(const std::string& alias) {
    this -> alias = alias;
}


void algebra::Relation::setColumnTypes(const std::unordered_map<std::string, std::string>& columnTypes) {
    this -> columnTypes = columnTypes;
}

void algebra::Relation::setColumns(const std::vector<algebra::Column>& columns) {
    this -> columns = columns;
}

std::string algebra::Relation::getType() {
    return type;
}
