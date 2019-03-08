//
//  Count.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Count.h"
std::string algebra::Count::getType() {
    return this -> type;
}
algebra::Count::Count(const std::string& name, const std::shared_ptr<algebra::Expression>& expr) : algebra::Function(name, expr) {
    type = "COUNT";
}

void algebra::Count::update(const algebra::Row& row) {
    if (row.get(col_ptr -> findName()) == "NULL") {
        return;
    }
    count++;
}

//std::string algebra::Count::findName() {
 //   return type + "(" + col_ptr -> findName() + ")";
//}

std::string algebra::Count::findValue() {
    return std::to_string(count);
}

std::shared_ptr<algebra::Function> algebra::Count::duplicate() {
    std::string newName = name;
    std::shared_ptr<algebra::Expression> newExpr = expr;
    return std::make_shared<algebra::Count>(newName, newExpr);
}
