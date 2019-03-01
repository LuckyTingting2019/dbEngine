//
//  NaturalJoinIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "NaturalJoinIterator.h"
NaturalJoinIterator::NaturalJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr) : JoinIterator(join_ptr) {
    tableNameL = join_ptr -> getLeft() -> getName();
    tableNameR = join_ptr -> getRight() -> getName();
    findCommonFields();
    setTableMap();
}

bool NaturalJoinIterator::hasNext() {
    if (!currentRows.empty()) {
        leftRow = currentRows.back();
        currentRows.pop_back();
        joinedRow = mergeRows(leftRow, rightRow);
        return true;
    } else {
        std::stringstream ss;
        std::string rightValue;
        while (rightStream -> hasNext()) {
            rightRow = rightStream -> next();
            for (auto x : commonFieldsSimple) {
                ss << rightRow.get(tableNameR + "." + x) << ",";
            }
            rightValue = ss.str();
            ss.str(std::string());
            if (tableMap.find(rightValue) != tableMap.end()) {
                currentRows = tableMap.at(rightValue);
                leftRow = currentRows.back();
                currentRows.pop_back();
                joinedRow = mergeRows(leftRow, rightRow);
                return true;
            }
        }
    }
    return false;
}

/*
Row NaturalJoinIterator::next() {
    return joinedRow;
}
*/

void NaturalJoinIterator::findCommonFields() {
    //std::string lcol;
    //std::string rcol;
    const std::vector<algebra::Column> rightCols = join_ptr -> getRight() -> getColumns();
    std::unordered_set<std::string> rightColSimpleName;
    for (auto x : rightCols) {
        rightColSimpleName.insert(x.getColumnName());
    }
    std::string col;
    for (auto x: join_ptr -> getLeft() -> getColumns()) {
        col = x.getColumnName();
        if (rightColSimpleName.find(col) != rightColSimpleName.end()) {
            commonFieldsSimple.push_back(col);
        }
    }
}

void NaturalJoinIterator::setTableMap() {
    algebra::Row current;
    std::stringstream ss;
    std::string key;
    while (leftStream -> hasNext()) {
        //build the key
        current = leftStream -> next();
        for (auto x : commonFieldsSimple) {
            ss << current.get(tableNameL + "." + x) << ",";
        }
        key = ss.str();
        ss.str(std::string());
        
        //build the value
        if (tableMap.find(key) != tableMap.end()) {
            tableMap.at(key).push_back(current);
        } else {
            std::vector<algebra::Row> rows;
            rows.push_back(current);
            tableMap[key] = rows;
        }
    }
}

algebra::Row NaturalJoinIterator::mergeRows(const algebra::Row& left, const algebra::Row& right) {
    algebra::Row row(left.getTableName() + join_ptr -> getJoinType() + "Join" + right.getTableName());
    for (auto x : left.getFields()) {
        row.put(Utilities::split(x.first, '.')[1], x.second);
    }
    for (auto x: right.getFields()) {
        row.put(Utilities::split(x.first, '.')[1], x.second);
    }
    return row;
};
/*
bool NaturalJoinIterator::isMatch(const Row& row1, const Row& row2) {
    for (auto x : commonFileds) {
        if (row1.get(x) != row2.get(x)) {
            return false;
        }
    }
    return true;
}
 */
