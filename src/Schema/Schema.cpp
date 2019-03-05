//
//  Schema.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/20/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Schema.h"
#include "Utilities.h"

bool Schema::isNaturalJoin = false;
std::unordered_map<std::string, std::unordered_map<std::string, std::string>> Schema::tables_colType;
std::unordered_map<std::string, std::vector<algebra::Column>> Schema::tables_columns;
std::unordered_map<std::string, std::string> Schema::tables_alias;
std::vector<std::string> Schema::tables;
std::unordered_map<std::string, std::shared_ptr<algebra::Expression>> Schema::expr_alias;
bool Schema::hasDistinct = false;

void Schema::addTable(const algebra::Table &table) {
    //setup tables
    Schema::tables.push_back(table.getName());
    //setup colTypes
    std::unordered_map<std::string, std::string> colTypes;
    for (auto x : table.getColumnTypes()) {
        colTypes[Utilities::split(x.first, '.')[1]] = x.second;
    }
    Schema::tables_colType[table.getName()] = colTypes;
    
    //setup columns
    std::vector<algebra::Column> columns;
    for (auto x : table.getColumns()) {
        columns.push_back(x);
    }
    Schema::tables_columns[table.getName()] = columns;
    
    //setup alias
    if (table.getAlias() != "") {
        Schema::tables_alias[table.getAlias()] = table.getName();
    }
}

bool Schema::getIsNaturalJoin() {
    return Schema::isNaturalJoin;
}

bool Schema::getHasDistinct() {
    return Schema::hasDistinct;
}

void Schema::setHasDistinct(bool hasDistinct) {
    Schema::hasDistinct = hasDistinct;
}

const std::unordered_map<std::string, std::vector<algebra::Column>>& Schema::getColumns() {
    return Schema::tables_columns;
}
const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& Schema::getColType() {
    return Schema::tables_colType;
}

const std::unordered_map<std::string, std::string>& Schema::getTablesAlias() {
    return Schema::tables_alias;
}

bool Schema::isNameTableAlias(const std::string& name) {
    return Schema::tables_alias.find(name) != Schema::tables_alias.end();
}

std::string Schema::getTableNameFromAlias(const std::string& alias) {
    return Schema::tables_alias.at(alias);
}

bool Schema::addTableAlias(const std::string& alias, const std::string& tableName) {
    if (isNameTableAlias(alias)) {
        return false;
    } else {
        Schema::tables_alias[alias] = tableName;
        return true;
    }
}

bool Schema::isNameExprAlias(const std::string& name) {
    return Schema::expr_alias.find(name) != Schema::expr_alias.end();
}

std::shared_ptr<algebra::Expression> Schema::getExprFromAlias(const std::string& alias) {
    return Schema::expr_alias.at(alias);
}

bool Schema::addExprAlias(const std::string& alias, const std::shared_ptr<algebra::Expression>& expr) {
    if (isNameExprAlias(alias)) {
        return false;
    } else {
        Schema::expr_alias[alias] = expr;
        return true;
    }
}

void Schema::setIsNaturalJoin(bool isNaturalJoin) {
    Schema::isNaturalJoin = isNaturalJoin;
}

std::string Schema::findFullName(const std::string& name) {
    std::string fullName;
    for (auto x : Schema::tables_colType) {
        if (x.second.find(name) != x.second.end()) {
            fullName = x.first + "." + name;
            break;
        }
    }
    return fullName;
}

std::string Schema::findColType(const std::string& colName) {
    std::string colType;
    for (auto x : Schema::tables_colType) {
        if (x.second.find(colName) != x.second.end()) {
            colType = x.second.at(colName);
        }
    }
    return colType;
}

std::string Schema::findTableName(const std::string& colName) {
    std::string tableName;
    for (auto x : Schema::tables_colType) {
        if (x.second.find(colName) != x.second.end()) {
            tableName = x.first;
        }
    }
    return tableName;
}
std::string Schema::findColType(const std::string& tableName, const std::string colName) {
    return Schema::tables_colType.at(tableName).at(colName);
}

std::string Schema::findMatchedName(const std::shared_ptr<algebra::Column>& col_ptr) {
    if(!isNaturalJoin) {
        return col_ptr -> getTableName() + "." + col_ptr -> getColumnName();
    } else {
        return col_ptr -> getColumnName();
    }
}


std::string Schema::findMatchedName(const std::string& name) {
    std::string matchedName = name;
    if (isNaturalJoin && name.find('.') != std::string::npos) {
        matchedName = Utilities::split(name, '.')[1];
    } else if (!isNaturalJoin && name.find('.') == std::string::npos) {
        matchedName = findFullName(name);
    }
    return matchedName;
}

std::string Schema::findMatchedName(const std::string& tableName, const std::string& colName) {
    if (isNaturalJoin) {
        return colName;
    } else {
        return tableName + "." + colName;
    }
}

void Schema::reset() {
    Schema::isNaturalJoin = false;
    Schema::hasDistinct = false;
    Schema::tables.clear();
    Schema::tables_colType.clear();
    Schema::tables_columns.clear();
}

void Schema::updateToNaturalSchema() {
    std::unordered_map<std::string, std::string> t1_colType = Schema::tables_colType.at(tables[0]);
    std::unordered_map<std::string, std::string> t2_colType = Schema::tables_colType.at(tables[1]);
    
    std::vector<algebra::Column> t1_col = Schema::tables_columns.at(tables[0]);
    std::vector<algebra::Column> t2_col = Schema::tables_columns.at(tables[1]);
    
    std::string tableName = Schema::tables[0] + "NATURALJoin" + Schema::tables[1];
    Schema::tables.clear();
    Schema::tables.push_back(tableName);
    
    Schema::tables_colType.clear();
    Schema::tables_columns.clear();
    std::unordered_map<std::string, std::string> colType;
    std::vector<algebra::Column> col;
    for (auto x : t1_colType) {
        colType[x.first] = x.second;
    }
    for (auto x : t1_col) {
        col.push_back(algebra::Column(tableName, x.getColumnName(), x.getFieldType()));
    }
    for (auto x : t2_col) {
        if (colType.find(x.getColumnName()) == colType.end()) {
            col.push_back(algebra::Column(tableName, x.getColumnName(), x.getFieldType()));
        }
    }
    for (auto x : t2_colType) {
        colType[x.first] = x.second;
    }
    Schema::tables_colType[tableName] = colType;
    Schema::tables_columns[tableName] = col;
}
