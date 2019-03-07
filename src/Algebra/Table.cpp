//
//  Table.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "Table.h"

algebra::Table::Table(const std::string& name) {
    this -> name = name;
    type = "Table";
    setSchema();
}

algebra::Table& algebra::Table::operator=(const Table& another){
    if (this == &another) {
        return *this;
    } else {
        this -> name = another.name;
        this -> columnTypes.clear();
        for (auto x : another.columnTypes) {
            this -> columnTypes[x.first] = x.second;
        }
        this -> columns.clear();
        for (auto x : another.columns) {
            this -> columns.push_back(x);
        }
        return *this;
    }
}

std::string algebra::Table::getTablePath() const {
    std::string tablePath = path + name + ".csv";
    return tablePath;
}

void algebra::Table::setSchema() {
    const std::string fileName = path + name + extension;
    std::ifstream file(fileName);
    std::string line;
    size_t i;
    std::string colName;
    std::string colType;
    if (file.is_open()) {
        while (getline(file, line)) {
            i = line.find(delimeter);
            colName = line.substr(0, i);
            colType = line.substr(i + 1, line.length());
            columnTypes[name + "." + colName] = colType;
            columns.push_back(Column(name, colName, colType));
        }
        file.close();
    } else {
        std::cout << "Unable to open file!" << std::endl;
    }
    tables.insert(name);
}
