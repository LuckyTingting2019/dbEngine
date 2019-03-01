//
//  GroupByIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "GroupByIterator.h"
#include "Row.h"
#include "Utilities.h"
GroupByIterator::GroupByIterator(std::shared_ptr<algebra::GroupBy> groupBy_ptr, std::shared_ptr<Iterator> downStream) : groupBy_ptr(groupBy_ptr), downStream(downStream) {
    buildMap();
    iter = map.begin();
}

void GroupByIterator::buildMap() {
    algebra::Row row;
    while (downStream -> hasNext()) {
        //get current row
        row = downStream -> next();
        
        //build key of current row
        std::string key;
        for (auto x : groupBy_ptr -> getColumns()) {
            key += x -> findValue(row);
            key += ":";
        }
        key.pop_back();
        
        //check if key in the map
        //yes: update functions
        //no: add pair and update functions
        if (map.find(key) != map.end()) {
            for (auto x: map.at(key)) {
                x -> update(row);
            }
        } else {
            map[key] = initFuncs(row);
        }
    }
}

std::vector<std::shared_ptr<algebra::Function>> GroupByIterator::initFuncs(const algebra::Row& row) {
    std::vector<std::shared_ptr<algebra::Function>> funcs;
    for (auto x : groupBy_ptr -> getFuncs()) {
        funcs.push_back(x -> duplicate());
    }
    for (auto x : funcs) {
        x -> update(row);
    }
    return funcs;
}

bool GroupByIterator::hasNext() {
    return iter != map.end();
}

algebra::Row GroupByIterator::next() {
    algebra::Row row;
    std::vector<std::string> values = Utilities::split(iter -> first, ':');
    int i = 0;
    //add columns to the row
    for (auto x : groupBy_ptr -> getColumns()) {
        row.put(x -> findName(), values[i++]);
    }
    //add functions to the row
    for (auto x : iter -> second) {
        row.put(x -> findName(), x -> findValue());
    }
    iter++;
    return row;
}



