//
//  Relation.hpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include <stdio.h>
#include "string"
#include "unordered_map"
#include "vector"
#include "Column.h"

namespace algebra {
    class Relation {
    public:
        std::string getType();
        const std::string& getName () const ;
        const std::unordered_map<std::string, std::string>& getColumnTypes() const;
        const std::vector<algebra::Column>& getColumns() const;
        const std::string& getAlias () const;
        const std::unordered_set<std::string>& getTables() const;
        
        bool addTable(const std::string& name);
        bool isInTables(const std::string& name);
        void setName(const std::string& name);
        void setColumnTypes(const std::unordered_map<std::string, std::string>& columnTypes);
        void setColumns(const std::vector<algebra::Column>& columns);
        void setAlias(const std::string& alias);
        
    protected:
        std::string name;
        std::string alias;
        std::unordered_map<std::string, std::string> columnTypes;
        std::vector<algebra::Column> columns;
        std::unordered_set<std::string> tables;
        std::string type = "Relation";
        virtual void setSchema() = 0;
        

    }; //class Relation
} //namespace algebra

#endif /* Relation_h */
