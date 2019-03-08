//
//  BinaryExpr.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "BinaryExpr.h"
#include "sstream"
std::string algebra::BinaryExpr::getType() {
    return this -> type;
}

std::unordered_set<std::string> algebra::BinaryExpr::getReferencedTables() {
    std::unordered_set<std::string> res;
    for (auto x : left -> getReferencedTables()) {
        res.insert(x);
    }
    for (auto x : right -> getReferencedTables()) {
        res.insert(x);
    }
    return res;
}

bool algebra::BinaryExpr::isSimple() {
    if (left -> isSimple() && right -> isSimple()) {
        std::unordered_set<std::string> leftTables = left -> getReferencedTables();
        std::unordered_set<std::string> rightTables = right -> getReferencedTables();
        if (leftTables.size() > 1 || rightTables.size() > 1) {
            return false;
        }
        if (leftTables.size() == 0 || rightTables.size() == 0) {
            return true;
        }
        return *leftTables.begin() == *rightTables.begin();
    }
    return false;
}

std::string algebra::BinaryExpr::findName() {
    return left -> findName() + " " + oper + " " + right -> findName();
}

//std::string algebra::BinaryExpr::toString() {
  //  std::stringstream ss;
    //ss << left -> toString() << " " << oper << " " << right -> toString();
    //return ss.str();
//}

algebra::BinaryExpr::BinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right) : left(left), oper(oper), right(right) {}

const std::shared_ptr<algebra::Expression>& algebra::BinaryExpr::getLeft() const {
    return left;
}
const std::shared_ptr<algebra::Expression>& algebra::BinaryExpr::getRight() const {
    return right;
}
const std::string& algebra::BinaryExpr::getOper() const {
    return oper;
}

void algebra::BinaryExpr::setLeft(const std::shared_ptr<algebra::Expression>& left) {
    this -> left = left;
}
void algebra::BinaryExpr::setRight(const std::shared_ptr<algebra::Expression>& right) {
    this -> right = right;
}
void algebra::BinaryExpr::setOper(const std::string& oper) {
    this -> oper = oper;
}
