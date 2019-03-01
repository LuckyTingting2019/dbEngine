//
//  IteratorBuilder.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/22/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef IteratorBuilder_h
#define IteratorBuilder_h

#include <stdio.h>
#include "iostream"
#include "AlgebraTree.h"
#include "Iterator.h"
#include "CSVIterator.h"
#include "JoinIterator.h"
#include "FilterIterator.h"
#include "Projection.h"
#include "ProjIterator.h"
#include "JoinIteratorBuilder.h"

class IteratorBuilder {
public:
    static std::shared_ptr<Iterator> build(const std::shared_ptr<algebra::AlgebraTree>& algebraTree);
};

#endif /* IteratorBuilder_h */
