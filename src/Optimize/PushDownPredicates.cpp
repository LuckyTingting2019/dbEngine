//
//  PushDownPredicates.cpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#include "PushDownPredicates.hpp"
#include "PushDownConjunctivePredicates.hpp"
#include "AlgebraTree.h"
#include "Join.h"
PushDownPredicates::PushDownPredicates(const std::shared_ptr<algebra::Relation>& relat_ptr) : Rule(relat_ptr) {};

bool PushDownPredicates::match() {
    return relat_ptr -> getType() == "AlgebraTree";
}

void PushDownPredicates::convert() {
    if (!match()) {
        return;
    }
    //process its relation : find its relation's filters and push down
    std::shared_ptr<algebra::AlgebraTree> algeTree_ptr = std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr);
    algeTree_ptr -> setRelat(process(algeTree_ptr -> getRelat()));
    
    //process itself, get its filters and push down
    PushDownConjunctivePredicates rule(algeTree_ptr);
    rule.excute();
}
    
std::shared_ptr<algebra::Relation> PushDownPredicates::process(std::shared_ptr<algebra::Relation>& relat_ptr) {
    //if the relation is algebraTree, get its filters and push down
    if (relat_ptr -> getType() == "AlgebraTree") {
        PushDownConjunctivePredicates rule(std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr));
        rule.excute();
    //if the relation is join, process its left and right relation
    } else if (relat_ptr -> getType() == "Join") {
        std::shared_ptr<algebra::Join> join = std::dynamic_pointer_cast<algebra::Join>(relat_ptr);
        std::shared_ptr<algebra::Relation> left = join -> getLeft();
        std::shared_ptr<algebra::Relation> right = join -> getRight();
        join -> setLeft(process(left));
        join -> setRight(process(right));
    }
    //if the relation is a table, then no need to push down, so do nothing.
    return relat_ptr;
}
