//
//  ProjIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef ProjIterator_h
#define ProjIterator_h

#include <stdio.h>
#include "Projection.h"
#include "CSVIterator.h"
#include "iostream"
#include "Iterator.h"
#include "Schema.h"
#include "Row.h"

class ProjIterator : public Iterator {

public:
    ProjIterator(std::shared_ptr<algebra::Projection> proj, std::shared_ptr<Iterator> downStream);

    bool hasNext() override;
    algebra::Row next() override;
    void print();
    
private:
    std::shared_ptr<algebra::Projection> proj;
    std::shared_ptr<Iterator> downStream;
    algebra::Row nextRow;

};

#endif /* ProjIterator_h */
