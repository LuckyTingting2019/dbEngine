//
//  JoinIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/15/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "JoinIterator.h"
#include "AlgebraTree.h"
#include "IteratorBuilder.h"
void JoinIterator::init(const std::shared_ptr<algebra::Join> &join_ptr) {
    std::shared_ptr<algebra::Relation> left = join_ptr -> getLeft();
    std::shared_ptr<algebra::Relation> right = join_ptr -> getRight();
    leftStream = IteratorBuilder::build(left);
    rightStream = IteratorBuilder::build(right);
    if (join_ptr -> getCondition()) {
        getJoinColumns(left, right);
        if (join_ptr -> getJoinType() == "LEFT") {
            setTableMap(rightStream, rightCol_ptr);
        } else {
            setTableMap(leftStream, leftCol_ptr);
        }
    }
}

JoinIterator::JoinIterator(const std::shared_ptr<algebra::Join>& join_ptr) : join_ptr(join_ptr) {
    init(join_ptr);
}

void JoinIterator::getJoinColumns(const std::shared_ptr<algebra::Relation>& left, const std::shared_ptr<algebra::Relation>& right) {
    //find out the conditioned cols of the left table
    const std::shared_ptr<algebra::BoolBinaryExpr>& condition = join_ptr -> getCondition();
    const std::shared_ptr<algebra::Column>& leftCol = std::dynamic_pointer_cast<algebra::Column>(condition -> getLeft());
    const std::shared_ptr<algebra::Column>& rightCol = std::dynamic_pointer_cast<algebra::Column>(condition -> getRight());
    if (leftCol && rightCol) {
        if (left -> isInTables(leftCol -> getTableName())) {
            this -> leftCol_ptr = leftCol;
            this -> rightCol_ptr = rightCol;
        } else {
            this -> leftCol_ptr = rightCol;
            this -> rightCol_ptr = leftCol;
        }
    } else {
        std::cout << "Not supported join condition!" << std::endl;
    }
}

algebra::Row JoinIterator::next() {
    return joinedRow;
}


void JoinIterator::setTableMap(const std::shared_ptr<Iterator>& stream, const std::shared_ptr<algebra::Column>& col_ptr) {
    //initialize the left table into hashmap
    algebra::Row current;
    std::string value;
    while (stream -> hasNext()) {
        current = stream -> next();
        value = current.get(col_ptr -> findFullName());
        if (tableMap.find(value) != tableMap.end()) {
            tableMap.at(value).push_back(current);
        } else {
            std::vector<algebra::Row> rows;
            rows.push_back(current);
            tableMap[value] = rows;
        }
    }
}

algebra::Row JoinIterator::mergeRows(const algebra::Row &left, const algebra::Row &right) {
    algebra::Row row(left.getTableName() + join_ptr -> getJoinType() + "Join" + right.getTableName());
    for (auto x : left.getFields()) {
        row.put(x.first, x.second);
    }
    for (auto x: right.getFields()) {
        row.put(x.first, x.second);
    }
    return row;
}

algebra::Row JoinIterator::getEmptyRow(const algebra::Row& row, const std::string& colFullName, const std::string& colValue) {
    algebra::Row res(row.getTableName());
    for(auto x : row.getFields()) {
        if (x.first == colFullName)
        {
            res.put(x.first, colValue);
        } else {
            res.put(x.first, "NULL");
        }
    }
    return res;
}
