//
//  JoinIteratorBuilder.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "JoinIteratorBuilder.h"
std::shared_ptr<JoinIterator> JoinIteratorBuilder::buildJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr) {
    const std::string joinType = join_ptr -> getJoinType();
    if (joinType == "NATURAL") {
        return std::make_shared<NaturalJoinIterator>(join_ptr);
    } else if (joinType == "INNER") {
        return std::make_shared<InnerJoinIterator>(join_ptr);
    } else if (joinType == "LEFT") {
        return std::make_shared<LeftJoinIterator>(join_ptr);
    } else {
        return std::make_shared<RightJoinIterator>(join_ptr);
    }
}
