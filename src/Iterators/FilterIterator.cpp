//
//  FilterIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/12/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "FilterIterator.h"
FilterIterator::FilterIterator(std::shared_ptr<algebra::Filter> filter_ptr, std::shared_ptr<Iterator> downStream) : downStream(downStream) {
    filter = filter_ptr;
}

bool FilterIterator::hasNext() {
    while(this -> downStream -> hasNext()) {
        nextRow = this -> downStream -> next();
        if (this -> filter -> evaluate(nextRow)) {
            return true;
        }
    }
    return false;
}

algebra::Row FilterIterator::next() {
    return nextRow;
}
