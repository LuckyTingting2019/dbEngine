//
//  Expression.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Expression.h"
std::string algebra::Expression::getType() {
    return this -> type;
}

const std::string& algebra::Expression::getAlias() const {
    return alias;
}

void algebra::Expression::setAlias(const std::string& alias) {
    this -> alias = alias;
}
