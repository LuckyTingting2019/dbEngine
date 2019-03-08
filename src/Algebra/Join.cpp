//
//  Join.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/14/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Join.h"
std::string algebra::Join::toString() {
    std::stringstream ss;
    if (left -> getType() == "AlgebraTree") {
        ss << "\n\n(" << left -> toString() << ")\n";
    } else {
        ss << left -> toString();
    }
    ss << "\n" << joinType << " JOIN ";
    if (right -> getType() == "AlgebraTree") {
        ss << "\n\n(" << right -> toString() << ")\n";
    } else {
        ss << right -> toString();
    }
    if (joinCondition) {
        ss << "\nON " << joinCondition -> toString();
    }
    return ss.str();
}

algebra::Join::Join(const std::shared_ptr<algebra::Relation> left, const std::shared_ptr<algebra::Relation> right, const std::string& joinType) : left(left), right(right), joinType(joinType) {
    type = "Join";
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

void algebra::Join::setSchema() {
    //for natural join, the schema won't include table name in columns and columnTypes. The schema for columns is all left columns in order first, then right columns in order without common columns
    //setup name
    name = left -> getName() + "_" + joinType + "Join" + "_" + right -> getName();
    
    //setup columns and columnTypes
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
    //setup tables
    for (auto x : left -> getTables()) {
        tables.insert(x);
    }
    for (auto x : right -> getTables()) {
        tables.insert(x);
    }
}
