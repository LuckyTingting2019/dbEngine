//
//  QueryOptimizer.cpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#include "QueryOptimizer.hpp"
#include "PushDownPredicates.hpp"
QueryOptimizer::QueryOptimizer(const std::shared_ptr<algebra::Relation>& root) : root(root){
    setRules();
}

void QueryOptimizer::setRoot(const std::shared_ptr<algebra::Relation>& root) {
    this -> root = root;
    setRules();
}

std::shared_ptr<algebra::Relation> QueryOptimizer::optimize() {
    for (auto x : rules) {
        x -> excute();
    }
    return root;
}

void QueryOptimizer::setRules() {
    rules.clear();
    rules.push_back(std::make_shared<PushDownPredicates>(root));
}
