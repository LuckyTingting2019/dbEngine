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

std::unordered_map<std::string, std::shared_ptr<algebra::Filter>> algebra::Filter::partition() {
    std::unordered_map<std::string, std::shared_ptr<algebra::Filter>> res;
    if (!expr -> isConjunctiveAndSimple()) {
        return res;
    }
    std::unordered_map<std::string, std::vector<std::shared_ptr<algebra::BoolBinaryExpr>>> lists;
    getLists(this -> expr, lists);
    for (auto x : lists) {
        res[x.first] = makeFilter(x.second);
    }
    return res;
}
void algebra::Filter::getLists(const std::shared_ptr<algebra::BoolBinaryExpr>& expr, std::unordered_map<std::string, std::vector<std::shared_ptr<algebra::BoolBinaryExpr>>>& lists) {
    if (expr -> isSinglePredicate()) {
        std::string tableName = *(expr -> getReferencedTables().begin());
        if (lists.find(tableName) == lists.end()) {
            std::vector<std::shared_ptr<algebra::BoolBinaryExpr>> list;
            lists[tableName] = list;
        }
        lists.at(tableName).push_back(expr);
    } else {
        getLists(std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(expr -> getLeft()), lists);
        getLists(std::dynamic_pointer_cast<algebra::BoolBinaryExpr>(expr -> getRight()), lists);
    }
}
std::shared_ptr<algebra::Filter> algebra::Filter::makeFilter(const std::vector<std::shared_ptr<algebra::BoolBinaryExpr>>& list) {
    std::shared_ptr<algebra::BoolBinaryExpr> res;
    res = list.at(0);
    for (int i = 1; i < list.size(); i++) {
        res = std::make_shared<algebra::BoolBinaryExpr>(res, "AND", list.at(i));
    }
    return std::make_shared<algebra::Filter>(res);
}


void algebra::Filter::AND(std::shared_ptr<algebra::Filter>& filter) {
    if (filter == nullptr || filter -> getExpr() == nullptr) {
        return;
    }
    this -> expr = std::make_shared<algebra::BoolBinaryExpr>(this -> expr, "AND", filter -> getExpr());
}

std::string algebra::Filter::toString() {
    return expr -> toString();
}
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
