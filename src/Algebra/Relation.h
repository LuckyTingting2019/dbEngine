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
        virtual void getType();
        
        const std::string& getName () const ;
        const std::unordered_map<std::string, std::string>& getColumnTypes() const;
        const std::vector<algebra::Column>& getColumns() const;
        
        void setName(const std::string& name);
        void setColumnTypes(const std::unordered_map<std::string, std::string>& columnTypes);
        void setColumns(const std::vector<algebra::Column>& columns);
        
    protected:
        std::string name;
        std::unordered_map<std::string, std::string> columnTypes;
        std::vector<algebra::Column> columns;
        

    }; //class Relation
} //namespace algebra

#endif /* Relation_h */
