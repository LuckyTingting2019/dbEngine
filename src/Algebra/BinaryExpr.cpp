//
//  BinaryExpr.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "BinaryExpr.h"
std::string algebra::BinaryExpr::getType() {
    return this -> type;
}

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
