//
//  Iterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/12/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

#include <stdio.h>
#include "Row.h"
#include "Relation.h"

class Iterator {
public:
    //virtual const std::shared_ptr<algebra::Relation>& getRelation() const = 0;
    virtual bool hasNext() = 0;
    virtual algebra::Row next() = 0;
};
#endif /* Iterator_h */
