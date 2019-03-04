//
//  Function.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Function.h"
std::string algebra::Function::getType() {
    return this -> type;
}

std::string algebra::Function::findValue(const algebra::Row& row) {
    if (row.containsField(findName())) {
        return row.get(findName());
    } else if (row.containsField(getAlias())) {
        return row.get(getAlias());
    } else {
        throw "Expression with name: " + findName() + " and alias: " + getAlias() + " is not in the row.";
    }
    
}
std::string algebra::Function::findType() {
    return this -> fieldType;
}

algebra::Function::Function(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : name(name), expr(expr) {
    col_ptr = std::dynamic_pointer_cast<algebra::Column>(expr);
    fieldType = col_ptr -> getFieldType();
}

const std::string& algebra::Function::getName() const {
    return this -> name;
}
const std::shared_ptr<algebra::Expression>& algebra::Function::getExpr() const {
    return this -> expr;
}
void algebra::Function::setName(const std::string& name) {
    this -> name = name;
}
void algebra::Function::setExpr(const std::shared_ptr<algebra::Expression>& expr) {
    this -> expr = expr;
}
