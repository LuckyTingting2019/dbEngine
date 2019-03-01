//
//  RightJoinIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "RightJoinIterator.h"
RightJoinIterator::RightJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr) : JoinIterator(join_ptr) {}

bool RightJoinIterator::hasNext() {
    if (!currentRows.empty()) {
        leftRow = currentRows.back();
        currentRows.pop_back();
        joinedRow = mergeRows(leftRow, rightRow);
        return true;
    } else {
        std::string rightValue;
        while (rightStream -> hasNext()) {
            rightRow = rightStream -> next();
            rightValue = rightRow.get(rightCol_ptr -> findFullName());
            if (tableMap.find(rightValue) != tableMap.end()) {
                currentRows = tableMap.at(rightValue);
                leftRow = currentRows.back();
                currentRows.pop_back();
                joinedRow = mergeRows(leftRow, rightRow);
            } else {
                joinedRow = mergeRows(rightRow, getEmptyRow(leftRow, leftCol_ptr -> findFullName(), rightValue));
            }
            return true;
        }
    }
    return false;
}
