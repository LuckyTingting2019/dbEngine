//
//  FilterIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/12/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef FilterIterator_h
#define FilterIterator_h

#include <stdio.h>
#include "Filter.h"
#include "Row.h"
#include "CSVIterator.h"
#include "Iterator.h"

class FilterIterator : public Iterator {
public:
    FilterIterator(std::shared_ptr<algebra::Filter> filter_ptr, std::shared_ptr<Iterator> downStream);

    bool hasNext() override;
    algebra::Row next() override;
    
private:
    std::shared_ptr<algebra::Filter> filter;
    std::shared_ptr<Iterator> downStream;
    algebra::Row nextRow;
};
    



#endif /* FilterIterator_h */
