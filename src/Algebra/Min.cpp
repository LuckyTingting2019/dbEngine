//
//  Min.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Min.h"
#include "algorithm"
std::string algebra::Min::getType() {
    return this -> type;
}
algebra::Min::Min(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : algebra::Function(name, expr) {
    type = "MIN";
}

void algebra::Min::update(const algebra::Row& row) {
    if (row.get(col_ptr -> findName()) == "NULL") {
        return;
    }
    if (fieldType == "int") {
        mini = std::min(std::stoi(row.get(col_ptr -> findName())), mini);
    } else if (fieldType == "float") {
        mind = std::min(std::stod(row.get(col_ptr -> findName())), mind);
    } else if (fieldType == "varchar") {
        if (mins == "") {
            mins = row.get(col_ptr -> findName());
        } else {
            mins = std::min(row.get(col_ptr -> findName()), mins);
        }
    } else {
        throw "Unsupported data type: " + fieldType + " for function: " + this -> type;
    }
}

//std::string algebra::Min::findName() {
  //  return type + "(" + col_ptr -> findName() + ")";
//}

std::string algebra::Min::findValue() {
    if (fieldType == "varchar") {
        return mins == "" ? "NULL" : mins;
    } else if (fieldType == "int") {
        return mini == INT_MAX ? "NULL" : std::to_string(mini);
    } else {
        return mind == std::numeric_limits<double>::max() ? "NULL" : std::to_string(mind);
    }
}

std::shared_ptr<algebra::Function> algebra::Min::duplicate() {
    std::string newName = name;
    std::shared_ptr<algebra::Expression> newExpr = expr;
    return std::make_shared<algebra::Min>(newName, newExpr);
}
