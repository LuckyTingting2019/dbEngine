//
//  Column.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Column_h
#define Column_h

#include <stdio.h>
#include "Row.h"
#include <string>
#include "iostream"
#include "Expression.h"

namespace algebra {
    
    class Column : public Expression {
    public:
        std::string getType() override;
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        std::string findName() override;
        
        Column(){};
        //Column(const std::string& columnName);
        Column(const std::string& tableName, const std::string& columnName);
        Column(const std::string& tableName, const std::string& columnName, const std::string& fieldType);
        Column& operator=(const Column&);
        bool operator == (const algebra::Column& another) const;
        
        const std::string& getTableName() const;
        const std::string& getColumnName() const;
        const std::string& getFieldType() const;
        void setTableName(const std::string& tableName);
        void setColumnName(const std::string& columnName);
        void setFieldType(const std::string& fieldType);
        
        
        std::string findFullName() const;
        
    private:
        std::string tableName;
        std::string columnName;
        std::string fieldType;
        const std::string type = "Column";
        
    }; //class Column
    
} // namespace algebra





#endif /* Column_h */
