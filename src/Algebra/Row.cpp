//
//  Row.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Row.h"
algebra::Row::Row() {}

algebra::Row::Row(const std::string& tableName) : tableName(tableName) {}

algebra::Row& algebra::Row::operator=(const Row& another) {
    this -> tableName = another.tableName;
    this -> fields.clear();
    for(auto const& x : another.fields) {
        this -> fields[x.first] = x.second;
    }
    return *this;
}

bool algebra::Row::put(const std::string& columnName, const std::string& value) {
    //if the key is already in the map, the insertion operation was not performed, false was returned.
    if (fields.find(columnName) == fields.end()) {
        fields[columnName] = value;
        return true;
    } else {
        return false;
    }
}

std::string algebra::Row::get(const std::string& columnName) const {
    //will throw std::out_of_range exception if no element with the specified key
    //always check containsField(fieldName) before call this function
    if (fields.find(columnName) == fields.end()) {
        std::cout << "The key: " << columnName << " is not in the row of table: " << tableName << ", an empty string was returned!" << std::endl;
        return "";
    } else {
        return fields.at(columnName);
    }
}

const std::unordered_map<std::string, std::string>& algebra::Row::getFields() const {
    return fields;
}

bool algebra::Row::containsField(const std::string& columnName) const {
    return fields.count(columnName) > 0;
}

//for debug
void algebra::Row::print() {
    for( auto const& x : fields )
    {
        std::cout << x.first << ':' << x.second << std::endl;
    }
}

const std::string& algebra::Row::getTableName() const {
    return tableName;
}

