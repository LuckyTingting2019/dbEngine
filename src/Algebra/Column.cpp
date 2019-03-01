//
//  Column.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Column.h"
#include "Schema.h"
std::string algebra::Column::getType() {
    return this -> type;
}

std::string algebra::Column::findValue(const algebra::Row& row) {
    return row.get(findName());
}
std::string algebra::Column::findType() {
    return this -> fieldType;
}
std::string algebra::Column::findName() {
    return Schema::findMatchedName(tableName, columnName);
}

//algebra::Column::Column(const std::string& columnName) : columnName(columnName) {}

algebra::Column::Column(const std::string& tableName, const std::string& columnName)
: tableName(tableName)
, columnName(columnName) {}

algebra::Column::Column(const std::string& tableName, const std::string& columnName, const std::string& fieldType)
: tableName(tableName)
, columnName(columnName), fieldType(fieldType) {}

algebra::Column& algebra::Column::operator=(const Column& another) {
    this -> tableName = another.tableName;
    this -> columnName = another.tableName;
    this -> fieldType = another.fieldType;
    return *this;
}

bool algebra::Column::operator == (const algebra::Column& another) const {
    if (this == &another) {
        return true;
    }
    return this -> tableName == another.tableName && this -> columnName == another.columnName && this -> fieldType == another.fieldType;
}

const std::string& algebra::Column::getTableName() const {
    return tableName;
}

const std::string& algebra::Column::getColumnName() const {
    return columnName;
}

const std::string& algebra::Column::getFieldType() const {
    return fieldType;
}

void algebra::Column::setFieldType(const std::string& fieldType) {
    this -> fieldType = fieldType;
}

void algebra::Column::setTableName(const std::string& tableName) {
    this -> tableName = tableName;
}

void algebra::Column::setColumnName(const std::string &columnName) {
    this -> columnName = columnName;
}

std::string algebra::Column::findFullName() const {
    return tableName + "." + columnName;
}


