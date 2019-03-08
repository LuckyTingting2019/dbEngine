//
//  Projection.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Projection.h"
algebra::Projection::Projection(const std::vector<std::shared_ptr<algebra::Expression>>& columns) : columns(columns) {}

algebra::Projection::Projection(const std::vector<algebra::Column>& cols) {
    for (auto x : cols) {
        columns.push_back(std::make_shared<algebra::Column>(x));
    }
}

algebra::Projection& algebra::Projection::operator=(const algebra::Projection& another){
    this -> columns.clear();
    for (auto x : another.columns) {
        this -> columns.push_back(x);
    }
    return *this;
}

const std::vector<std::shared_ptr<algebra::Expression>>& algebra::Projection::getColumns() const {
    return this -> columns;
}

void algebra::Projection::setColumns(const std::vector<std::shared_ptr<algebra::Expression>>& columns) {
    this -> columns = columns;
}




