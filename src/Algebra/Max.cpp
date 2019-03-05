//
//  Max.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Max.h"
#include "algorithm"
std::string algebra::Max::getType() {
    return this -> type;
}
algebra::Max::Max(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : algebra::Function(name, expr) {
    type = "MAX";
}


void algebra::Max::update(const algebra::Row& row) {
    if (row.get(col_ptr -> findName()) == "NULL") {
        return;
    }
    if (fieldType == "int") {
        maxi = std::max(std::stoi(row.get(col_ptr -> findName())), maxi);
    } else if (fieldType == "float") {
        maxd = std::max(std::stod(row.get(col_ptr -> findName())), maxd);
    } else if (fieldType == "varchar") {
        if (maxs == "") {
            maxs = row.get(col_ptr -> findName());
        } else {
            maxs = std::max(row.get(col_ptr -> findName()), maxs);
        }
    } else {
        throw "Unsupported data type: " + fieldType + " for function: " + this -> type;
    }
}

//std::string algebra::Max::findName() {
  //  return type + "(" + col_ptr -> findName() + ")";
//}

std::string algebra::Max::findValue() {
    if (fieldType == "varchar") {
        return maxs == "" ? "NULL" : maxs;
    } else if (fieldType == "int") {
        return maxi == INT_MIN ? "NULL" : std::to_string(maxi);
    } else {
        return maxd == std::numeric_limits<double>::min() ? "NULL" : std::to_string(maxd);
    }
}

std::shared_ptr<algebra::Function> algebra::Max::duplicate() {
    std::string newName = name;
    std::shared_ptr<algebra::Expression> newExpr = expr;
    return std::make_shared<algebra::Max>(newName, newExpr);
}
