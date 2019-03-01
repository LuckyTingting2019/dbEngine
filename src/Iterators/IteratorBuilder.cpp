//
//  IteratorBuilder.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/22/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "IteratorBuilder.h"
#include "GroupByIterator.h"
std::shared_ptr<Iterator> IteratorBuilder::build(const std::shared_ptr<algebra::AlgebraTree>& algebraTree) {
    std::shared_ptr<Iterator> downStream;
    std::shared_ptr<algebra::Table> table_ptr = std::dynamic_pointer_cast<algebra::Table>(algebraTree -> relation_ptr);
    std::shared_ptr<algebra::Join> join_ptr = std::dynamic_pointer_cast<algebra::Join>(algebraTree -> relation_ptr);
    std::shared_ptr<algebra::AlgebraTree> algebraTree_ptr = std::dynamic_pointer_cast<algebra::AlgebraTree>(algebraTree -> relation_ptr);
    if (table_ptr) {
        downStream = std::make_shared<CSVIterator>(table_ptr);
        //std::cout << "getCSV" << std::endl;
    } else if (join_ptr){
        downStream = JoinIteratorBuilder::buildJoinIterator(join_ptr);
    } else if (algebraTree_ptr) {
        downStream = IteratorBuilder::build(algebraTree_ptr);
    } else {
        throw "Unsupported relation.";
    }
    if (algebraTree -> filter_ptr) {
        downStream = std::make_shared<FilterIterator>(algebraTree -> filter_ptr, downStream);
    }
    //if goes to groupBy iterator, then the row will only contain function cols and cols that are used to run group by
    if (algebraTree -> groupBy_ptr) {
        downStream = std::make_shared<GroupByIterator>(algebraTree -> groupBy_ptr, downStream);
    }
    return std::make_shared<ProjIterator>(algebraTree -> proj_ptr, downStream);
}
