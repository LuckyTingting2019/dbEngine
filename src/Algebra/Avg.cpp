//
//  Avg.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Avg.h"
std::string algebra::Avg::getType() {
    return this -> type;
}
algebra::Avg::Avg(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : algebra::Function(name, expr) {
    type = "AVG";
}

void algebra::Avg::update(const algebra::Row& row) {
    if (row.get(col_ptr -> findName()) == "NULL") {
        return;
    }
    count++;
    if (fieldType == "int") {
        sumi += std::stoi(row.get(col_ptr -> findName()));
    } else if (fieldType == "float") {
        sumd += std::stod(row.get(col_ptr -> findName()));
    } else {
        throw "Unsupported data type: " + fieldType + " for function: " + this -> type;
    }
}

//std::string algebra::Avg::findName() {
  //  return type + "(" + col_ptr -> findName() + ")";
//}

std::string algebra::Avg::findValue() {
    return count == 0 ? "NULL" : fieldType == "int" ? std::to_string(sumi / count) : std::to_string(sumd / count);
}

std::shared_ptr<algebra::Function> algebra::Avg::duplicate() {
    std::string newName = name;
    std::shared_ptr<algebra::Expression> newExpr = expr;
    return std::make_shared<algebra::Avg>(newName, newExpr);
}
