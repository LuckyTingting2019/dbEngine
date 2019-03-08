//
//  Projection.hpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/6/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Projection_h
#define Projection_h

#include <stdio.h>
#include "Relation.h"
#include "string"
#include "vector"
#include "Table.h"
#include "Column.h"
#include "Function.h"

namespace algebra {
    
    class Projection {
    public:
        Projection(const std::vector<std::shared_ptr<algebra::Expression>>& columns);
        Projection(const std::vector<algebra::Column>& columns);
        Projection& operator=(const Projection&);
        
        const std::vector<std::shared_ptr<algebra::Expression>>& getColumns() const;
        void setColumns(const std::vector<std::shared_ptr<algebra::Expression>>& columns);

    private:
        //member of columns can be column or function or Numeric Binary Expression
        std::vector<std::shared_ptr<algebra::Expression>> columns;
        
        
    }; //class Projection
    
} //namespace algebra





#endif /* Projection_h */
