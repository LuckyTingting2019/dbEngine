//
//  Distinct.cpp
//  db
//
//  Created by Tingting Fan on 3/4/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#include "Distinct.hpp"
#include "sstream"
#include "iomanip"
std::string algebra::Distinct::getType() {
    return this -> type;
}

std::string algebra::Distinct::findValue(const algebra::Row& row) {
    std::stringstream ss;
    std::string key;
    for (auto x : cols) {
        ss << std::left;
        ss << std::setw(10);
        ss << x -> findValue(row) + ", ";
    }
    key = ss.str();
    while (key.at(key.length() - 1) != ',') {
        key.pop_back();
    }
    key.pop_back();
    return key;
}

std::string algebra::Distinct::findType() {
    if (cols.size() == 1) {
        return cols[0] -> findType();
    } else {
        return "NULL";
    }
}

std::string algebra::Distinct::findName() {
    std::stringstream ss;
    std::string name;
    ss << type << " ";
    for (auto x : cols) {
        ss << x -> findName() + ", ";
    }
    name = ss.str();
    name.pop_back();
    name.pop_back();
    return name;
}

std::unordered_set<std::string> algebra::Distinct::getReferencedTables() {
    std::unordered_set<std::string> res;
    for (auto x : cols) {
        res.insert(x -> getTableName());
    }
    return res;
}

bool algebra::Distinct::isSimple() {
    return getReferencedTables().size() <= 1;
}

algebra::Distinct::Distinct(const std::vector<std::shared_ptr<algebra::Column>>& cols) : cols(cols) {}

const std::vector<std::shared_ptr<algebra::Column>>& algebra::Distinct::getCols() const {
    return cols;
}

void algebra::Distinct::setCols(const std::vector<std::shared_ptr<algebra::Column>>& cols) {
    this -> cols = cols;
}



bool algebra::Distinct::isDuplicate(const std::string& key) {
    return set.find(key) != set.end();
}

std::pair<bool, std::string> algebra::Distinct::isDuplicate(const algebra::Row& row) {
    std::string key = findValue(row);
    std::pair<bool, std::string> res(isDuplicate(key), key);
    return res;
}

bool algebra::Distinct::addToSet(const std::string& key) {
    return set.insert(key).second;
}

std::pair<bool, std::string> algebra::Distinct::addToSet(const algebra::Row& row) {
    std::string key = findValue(row);
    std::pair<bool, std::string> res(addToSet(key), key);
    return res;
}
