//
//  Join.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/14/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Join.h"

algebra::Join::Join(const std::shared_ptr<algebra::Relation> left, const std::shared_ptr<algebra::Relation> right, const std::string& joinType) : left(left), right(right), joinType(joinType) {
    setSchema();
}

const std::shared_ptr<algebra::Relation>& algebra::Join::getLeft() const {
    return left;
}
const std::shared_ptr<algebra::Relation>& algebra::Join::getRight() const {
    return right;
}
const std::string& algebra::Join::getJoinType() const {
    return joinType;
}
    
const std::shared_ptr<algebra::BoolBinaryExpr>& algebra::Join::getCondition() const {
    return joinCondition;
}
void algebra::Join::setLeft(const std::shared_ptr<algebra::Relation>& left) {
    this -> left = left;
}
void algebra::Join::setRight(const std::shared_ptr<algebra::Relation>& right) {
    this -> right = right;
}
void algebra::Join::setJoinType(const std::string& joinType) {
    this -> joinType = joinType;
}
void algebra::Join::setCondition(const std::shared_ptr<algebra::BoolBinaryExpr>& condition) {
    this -> joinCondition = condition;
}

void algebra::Join::getType() {
    std::cout << "This is a Join." << std::endl;
}

void algebra::Join::setSchema() {
    //for natural join, the schema won't include table name in columns and columnTypes. The schema for columns is all left columns in order first, then right columns in order without common columns
    name = left -> getName() + joinType + "Join" + right -> getName();
    if (joinType == "NATURAL") {
        std::string tmp;
        for (auto x : left -> getColumns()) {
            columns.push_back(x);
        }
        for (auto x : left -> getColumnTypes()) {
            columnTypes[Utilities::split(x.first, '.')[1]] = x.second;
        }
        for (auto x : right -> getColumns()) {
            if (columnTypes.find(x.getColumnName()) == columnTypes.end()) {
                columns.push_back(x);
            }
        }
        for (auto x : right -> getColumnTypes()) {
            tmp = Utilities::split(x.first, '.')[1];
            if (columnTypes.find(tmp) == columnTypes.end()) {
                columnTypes[tmp] = x.second;
            }
        }
    } else {
        for (auto x : left -> getColumns()) {
            columns.push_back(x);
        }
        for (auto x : right -> getColumns()) {
            columns.push_back(x);
        }
        for (auto x : left -> getColumnTypes()) {
            columnTypes[x.first] = x.second;
        }
        for (auto x : right -> getColumnTypes()) {
            columnTypes[x.first] = x.second;
        }
    }
}
