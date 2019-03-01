//
//  Sum.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Sum.h"
#include "Column.h"
std::string algebra::Sum::getType() {
    return this -> type;
}
algebra::Sum::Sum(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : algebra::Function(name, expr) {
}

void algebra::Sum::update(const algebra::Row& row) {
    if (row.get(col_ptr -> findName()) == "NULL") {
        return;
    }
    if (fieldType == "int") {
        sumi += std::stoi(row.get(col_ptr -> findName()));
    } else if (fieldType == "float") {
        sumd += std::stod(row.get(col_ptr -> findName()));
    } else {
        throw "Unsupported data type: " + fieldType + " for function: " + this -> type;
    }
}

std::string algebra::Sum::findName() {
    return type + "(" + col_ptr -> findName() + ")";
}

std::string algebra::Sum::findValue() {
    return fieldType == "int" ? std::to_string(sumi) : std::to_string(sumd);
}

std::shared_ptr<algebra::Function> algebra::Sum::duplicate() {
    std::string newName = name;
    std::shared_ptr<algebra::Expression> newExpr = expr;
    return std::make_shared<algebra::Sum>(newName, newExpr);
}
