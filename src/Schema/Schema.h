//
//  Schema.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/20/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Schema_h
#define Schema_h

#include <stdio.h>
#include "Column.h"
#include "Expression.h"
#include "Table.h"

class Schema {
public:
    static bool getIsNaturalJoin();
    static void setIsNaturalJoin(bool isNaturalJoin);
    static void addTable(const algebra::Table& table);
    static const std::unordered_map<std::string, std::vector<algebra::Column>>& getColumns();
    static const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& getColType();
    
    static std::string findFullName(const std::string& name);
    static std::string findColType(const std::string& colName);
    static std::string findColType(const std::string& tableName, const std::string colName);
    static std::string findTableName(const std::string& colName);
    static std::string findMatchedName(const std::string& name);
    static std::string findMatchedName(const std::string& tableName, const std::string& colName);
    static std::string findMatchedName(const std::shared_ptr<algebra::Column>& col_ptr);
    static void updateToNaturalSchema();
    
    static void reset();
private:
    static bool isNaturalJoin;
    //key = tableName, value: key = simpleColName, value = type
    static std::vector<std::string> tables;
    static std::unordered_map<std::string, std::unordered_map<std::string, std::string>> tables_colType;
    //key = tableName, value = simpleColNames
    static std::unordered_map<std::string, std::vector<algebra::Column>> tables_columns;
    
};

#endif /* Schema_h */
