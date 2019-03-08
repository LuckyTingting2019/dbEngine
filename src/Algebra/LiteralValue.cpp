//
//  LiteralValue.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "LiteralValue.h"
std::string algebra::LiteralValue::getType() {
    return this -> type;
}

std::string algebra::LiteralValue::findValue(const algebra::Row& row) {
    return this -> value;
}
std::string algebra::LiteralValue::findType() {
    return this -> fieldType;
}

std::string algebra::LiteralValue::findName() {
    return this -> value;
}

std::unordered_set<std::string> algebra::LiteralValue::getReferencedTables() {
    std::unordered_set<std::string> res;
    return res;
}

bool algebra::LiteralValue::isSimple() {
    return true;
}

algebra::LiteralValue::LiteralValue(const std::string& value, const std::string& fieldType) : value(value), fieldType(fieldType) {}

void algebra::LiteralValue::setFieldType(const std::string& fieldType) {
    this -> fieldType = fieldType;
}
void algebra::LiteralValue::setValue(const std::string& value) {
    this -> value = value;
}
const std::string& algebra::LiteralValue::getFieldType() const {
    return this -> fieldType;
}
const std::string& algebra::LiteralValue::getValue() const {
    return this -> value;
}
