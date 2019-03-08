//
//  PushDownConjunctivePredicates.cpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#include "PushDownConjunctivePredicates.hpp"
#include "AlgebraTree.h"
#include "Table.h"
#include "Join.h"
PushDownConjunctivePredicates::PushDownConjunctivePredicates(const std::shared_ptr<algebra::Relation>& relat_ptr) : Rule(relat_ptr) {}

bool PushDownConjunctivePredicates::match() {
    if (relat_ptr -> getType() != "AlgebraTree") {
        return false;
    }
    std::shared_ptr<algebra::AlgebraTree> tree = std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr);
    std::string type = tree -> getRelat() -> getType();
    if (type != "Join" && type != "AlgebraTree") {
        return false;
    }
    if (tree -> getFilter() == nullptr) {
        return false;
    }
    filters = tree -> getFilter() -> partition();
    if (filters.size() == 0) {
        return false;
    }
    return true;
}
void PushDownConjunctivePredicates::convert() {
    std::shared_ptr<algebra::AlgebraTree> tree = std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr);
    tree -> setRelat(process(tree -> getRelat()));
    tree -> setFilter(nullptr);
}

std::shared_ptr<algebra::Relation> PushDownConjunctivePredicates::process(std::shared_ptr<algebra::Relation>& relat_ptr) {
    if (relat_ptr -> getType() == "Table") {
        std::shared_ptr<algebra::AlgebraTree> tree = std::make_shared<algebra::AlgebraTree>();
        tree -> setRelat(relat_ptr);
        tree -> setProj(std::make_shared<algebra::Projection>(relat_ptr -> getColumns()));
        tree -> setFilter(filters.at(relat_ptr -> getName()));
        return tree;
    } else if (relat_ptr -> getType() == "AlgebraTree") {
        std::shared_ptr<algebra::AlgebraTree> subTree = std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr);
        return pushToSubTree(subTree);
    } else if (relat_ptr -> getType() == "Join") {
        std::shared_ptr<algebra::Join> join = std::dynamic_pointer_cast<algebra::Join>(relat_ptr);
        std::shared_ptr<algebra::Relation> left = join -> getLeft();
        std::shared_ptr<algebra::Relation> right = join -> getRight();
        join -> setLeft(process(left));
        join -> setRight(process(right));
        return join;
    } else {
        throw "Unsupported relation.";
    }
}

std::shared_ptr<algebra::Relation> PushDownConjunctivePredicates::pushToSubTree(std::shared_ptr<algebra::AlgebraTree>& subTree) {
    std::shared_ptr<algebra::Relation> subRelat = subTree -> getRelat();
    if (subRelat -> getType() == "Table") {
        std::shared_ptr<algebra::Filter> subfilter = subTree -> getFilter();
        if (subfilter == nullptr) {
            subTree -> setFilter(filters.at(subRelat -> getName()));
        } else {
            subTree -> getFilter() -> AND(filters.at(subRelat -> getName()));
        }
    } else if (subRelat -> getType() == "Join" || subRelat -> getType() == "AlgebraTree") {
        subTree -> setRelat(process(subRelat));
    }
    return subTree;
}
