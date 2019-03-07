//
//  Table.hpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Table_h
#define Table_h

#include <stdio.h>
#include "iostream"
#include <string>
#include "vector"
#include "fstream"
#include "unordered_map"
#include "Relation.h"

namespace algebra {

    class Table : public Relation {
    public:
        Table(){};
        Table(const std::string& name);
        Table& operator=(const Table&);
        /*
        inherited from Relation
        string& getName() override;
        unordered_map<string, string>& getColumnTypes() override;
        vector<algebra::Column>& getColumns() override;
        */
        std::string getTablePath() const;
    
    private:
        const std::string path = "data/";
        const std::string extension = ".txt";
        const std::string delimeter = "\t";
        void setSchema() override;
        /*
        inherited from Relation:
         std::string name;
         std::string alias;
         std::unordered_map<std::string, std::string> columnTypes;
         std::vector<algebra::Column> columns;
         std::unordered_set<std::string> tables;
         std::string type = "Relation";
        */
    }; //class Table
    
} // namespace algebra


#endif /* Table_h */
