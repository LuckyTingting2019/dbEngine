//
//  CSVIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "CSVIterator.h"
CSVIterator::CSVIterator(const std::shared_ptr<algebra::Table>& table) : table(table) {
    std::string fileName = table -> getTablePath();
    file.open(fileName);
    std::string line = "";
    getline(file, line);
}

bool CSVIterator::hasNext() {
    if (file.eof()) {
        file.close();
        return false;
    }
    return true;
}

algebra::Row CSVIterator::next() {
    std::string line;
    getline(file, line);
    algebra::Row row(table -> getName());
    std::vector<std::string> values = Utilities::split(line, ',');
    for (auto i = 0; i < (int) values.size(); i++) {
        row.put(table -> getColumns()[i].findFullName(), values[i]);
    }
    return row;
}



void CSVIterator::setTable(const std::shared_ptr<algebra::Table>& table) {
    this -> table = table;
}
/*
std::vector<std::string> CSVIterator::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        if (token[0] == '\xef') {
            token.erase(0, 3);
        }
        token.erase(token.find_last_not_of(" \n\t\r\f\v") + 1);
        tokens.push_back(token);
    }
    return tokens;
}
 const std::shared_ptr<algebra::Relation>& CSVIterator::getRelation() const {
 return this -> table;
 }
*/
