//
//  IteratorBuilder.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/22/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "IteratorBuilder.h"
#include "GroupByIterator.h"
std::shared_ptr<Iterator> IteratorBuilder::build(const std::shared_ptr<algebra::Relation>& relat_ptr) {
    if (relat_ptr -> getType() == "Table") {
        return std::make_shared<CSVIterator>(std::dynamic_pointer_cast<algebra::Table>(relat_ptr));
    } else if (relat_ptr -> getType() == "Join") {
        return JoinIteratorBuilder::buildJoinIterator(std::dynamic_pointer_cast<algebra::Join>(relat_ptr));
    } else if (relat_ptr -> getType() == "AlgebraTree") {
        return buildAlgebraTreeIterator(std::dynamic_pointer_cast<algebra::AlgebraTree>(relat_ptr));
    } else {
        throw "Unsupported relation.";
    }
}

std::shared_ptr<ProjIterator> IteratorBuilder::buildAlgebraTreeIterator(const std::shared_ptr<algebra::AlgebraTree> &algebraTree) {
    std::shared_ptr<Iterator> downStream;
    std::shared_ptr<algebra::Table> table_ptr = std::dynamic_pointer_cast<algebra::Table>(algebraTree -> getRelat());
    std::shared_ptr<algebra::Join> join_ptr = std::dynamic_pointer_cast<algebra::Join>(algebraTree -> getRelat());
    std::shared_ptr<algebra::AlgebraTree> algebraTree_ptr = std::dynamic_pointer_cast<algebra::AlgebraTree>(algebraTree -> getRelat());
    if (table_ptr) {
        downStream = std::make_shared<CSVIterator>(table_ptr);
        //std::cout << "getCSV" << std::endl;
    } else if (join_ptr){
        downStream = JoinIteratorBuilder::buildJoinIterator(join_ptr);
    } else if (algebraTree_ptr) {
        downStream = IteratorBuilder::buildAlgebraTreeIterator(algebraTree_ptr);
    } else {
        throw "Unsupported relation.";
    }
    if (algebraTree -> getFilter()) {
        downStream = std::make_shared<FilterIterator>(algebraTree -> getFilter(), downStream);
    }
    //if goes to groupBy iterator, then the row will only contain function cols and cols that are used to run group by
    if (algebraTree -> getGroupBy()) {
        downStream = std::make_shared<GroupByIterator>(algebraTree -> getGroupBy(), downStream);
    }
    return std::make_shared<ProjIterator>(algebraTree -> getProj(), downStream);
}
