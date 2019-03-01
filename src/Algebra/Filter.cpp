//
//  Filter.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/12/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Filter.h"
algebra::Filter::Filter() {};

algebra::Filter::Filter(const std::shared_ptr<algebra::BoolBinaryExpr>& expr) : expr(expr) {}

algebra::Filter& algebra::Filter::operator=(const Filter& another){
    this -> expr = another.expr;
    return *this;
}

const std::shared_ptr<algebra::BoolBinaryExpr>& algebra::Filter::getExpr() const {
    return this -> expr;
}
void algebra::Filter::setExpr(const std::shared_ptr<algebra::BoolBinaryExpr>& expr) {
    this -> expr = expr;
}

bool algebra::Filter::evaluate(algebra::Row& row) {
    return expr -> evaluate(row);
};

/*
bool algebra::Filter::evaluate(const std::string& leftValue, const std::string& rightValue) {
    if (oper == "=" || oper == "IS") {
        return leftValue == rightValue;
    } else if (oper == "<>") {
        return leftValue != rightValue;
    } else if (oper == "<=") {
        return leftValue <= rightValue;
    } else if (oper == "<") {
        return leftValue < rightValue;
    } else if (oper == ">=") {
        return leftValue >= rightValue;
    } else if (oper == ">") {
        return leftValue > rightValue;
    } else {
        std::cout << "Unsupported string comparsion operation!!" << std::endl;
        return false;
    }
}

//Probably the three functions can be combined using generics??
bool algebra::Filter::evaluate(std::string rowValue) {
    if (oper == "=" || oper == "IS") {
        return rowValue == rightOp;
    } else if (oper == "<>") {
        return rowValue != rightOp;
    } else if (oper == "<=") {
        return rowValue <= rightOp;
    } else if (oper == "<") {
        return rowValue < rightOp;
    } else if (oper == ">=") {
        return rowValue >= rightOp;
    } else if (oper == ">") {
        return rowValue > rightOp;
    } else {
        std::cout << "Unsupported string comparsion operation!!" << std::endl;
        return false;
    }
}

bool algebra::Filter::evaluate(int rowValue) {
    int _value = stoi(rightOp);
    if (oper == "=" || oper == "IS") {
        return rowValue == _value;
    } else if (oper == "<>") {
        return rowValue != _value;
    } else if (oper == "<=") {
        return rowValue <= _value;
    } else if (oper == "<") {
        return rowValue < _value;
    } else if (oper == ">=") {
        return rowValue >= _value;
    } else if (oper == ">") {
        return rowValue > _value;
    } else {
        std::cout << "Unsupported int comparsion operation!!" << std::endl;
        return false;
    }
}

bool algebra::Filter::evaluate(double rowValue) {
    double _value = stod(rightOp);
    if (oper == "=" || oper == "IS") {
        return rowValue == _value;
    } else if (oper == "<>") {
        return rowValue != _value;
    } else if (oper == "<=") {
        return rowValue <= _value;
    } else if (oper == "<") {
        return rowValue < _value;
    } else if (oper == ">=") {
        return rowValue >= _value;
    } else if (oper == ">") {
        return rowValue > _value;
    } else {
        std::cout << "Unsupported int comparsion operation!!" << std::endl;
        return false;
    }
}


const std::string& algebra::Filter::getLeftOp()  const {
    return this -> leftOp;
}
const std::string& algebra::Filter::getOper() const {
    return this -> oper;
}
const std::string& algebra::Filter::getRightOp() const {
    return this -> rightOp;
}
const std::string& algebra::Filter::getType() const {
    return this -> type;
}
const std::string& algebra::Filter::getLogic() const {
    return this -> logic;
}
const std::shared_ptr<algebra::Filter>& algebra::Filter::getLeft() const {
    return left;
}
const std::shared_ptr<algebra::Filter>& algebra::Filter::getRight() const {
    return right;
}


void algebra::Filter::setLeftOp(const std::string& leftOp) {
    this -> leftOp = leftOp;
}
void algebra::Filter::setOper(const std::string& oper) {
    this -> oper = oper;
}
void algebra::Filter::setRightOp(const std::string& rightOp) {
    this -> rightOp = rightOp;
}
void algebra::Filter::setType(const std::string& type) {
    this -> type = type;
}
void algebra::Filter::setCondition(bool condition) {
    this -> condition = condition;
}
void algebra::Filter::setLogic(const std::string& logic) {
    this -> logic = logic;
}
void algebra::Filter::setLeft(std::shared_ptr<Filter> left) {
    this -> left = left;
}
void algebra::Filter::setRight(std::shared_ptr<Filter> right) {
    this -> right = right;
}
algebra::Filter::Filter(const std::string& leftOp, const std::string& oper, const std::string& rightOp, bool condition) : leftOp(leftOp), oper(oper), rightOp(rightOp), condition(condition) {}

algebra::Filter::Filter(const std::string& leftOp, const std::string& oper, const std::string& rightOp, bool condition, const Relation& relation) : leftOp(leftOp), oper(oper), rightOp(rightOp), condition(condition) {
    this -> type = relation.getColumnTypes().at(leftOp);
}

algebra::Filter::Filter(std::shared_ptr<Filter> left, std::shared_ptr<Filter> right, std::string& logic) : left(left), right(right), logic(logic) {}
*/
