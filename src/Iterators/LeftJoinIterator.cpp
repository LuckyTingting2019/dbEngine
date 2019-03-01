//
//  LeftJoinIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "LeftJoinIterator.h"
LeftJoinIterator::LeftJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr) : JoinIterator(join_ptr) {}

bool LeftJoinIterator::hasNext() {
    if (!currentRows.empty()) {
        rightRow = currentRows.back();
        currentRows.pop_back();
        joinedRow = mergeRows(leftRow, rightRow);
        return true;
    } else if (leftStream -> hasNext()) {
        std::string leftValue;
        leftRow = leftStream -> next();
        leftValue = leftRow.get(leftCol_ptr -> findFullName());
        if (tableMap.find(leftValue) != tableMap.end()) {
            currentRows = tableMap.at(leftValue);
            rightRow = currentRows.back();
            currentRows.pop_back();
            joinedRow = mergeRows(leftRow, rightRow);
        } else {
            joinedRow = mergeRows(leftRow, getEmptyRow(rightRow, rightCol_ptr -> findFullName(), leftValue));
        }
        return true;
    }
    return false;
}


