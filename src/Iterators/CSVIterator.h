//
//  CSVIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef CSVIterator_h
#define CSVIterator_h

#include <stdio.h>
#include <iostream>
#include "vector"
#include "string"
#include "Row.h"
#include "fstream"
#include "sstream"
#include "Iterator.h"
#include "Table.h"
#include "Utilities.h"

class CSVIterator : public Iterator {
public:
    CSVIterator() = default;
    CSVIterator(const std::shared_ptr<algebra::Table>& table);
    //CSVIterator& operator=(const CSVIterator&);
    
    //const std::shared_ptr<algebra::Relation>& getRelation() const override;
    void setTable(const std::shared_ptr<algebra::Table>& table);
    
    bool hasNext() override;
    algebra::Row next() override;
    
private:
    //vector<string> split(const string& s, char delimiter);

    std::shared_ptr<algebra::Table> table;
    std::ifstream file;
};
#endif /* CSVIterator_h */
