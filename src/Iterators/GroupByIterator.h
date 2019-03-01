//
//  GroupByIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef GroupByIterator_h
#define GroupByIterator_h

#include <stdio.h>
#include "GroupBy.h"
#include "Iterator.h"
#include "iterator"
class GroupByIterator : public Iterator {
public:
    GroupByIterator(std::shared_ptr<algebra::GroupBy> groupBy_ptr, std::shared_ptr<Iterator> downStream);
    
    bool hasNext() override;
    algebra::Row next() override;
    
private:
    std::shared_ptr<algebra::GroupBy> groupBy_ptr;
    std::shared_ptr<Iterator> downStream;
    
    std::unordered_map<std::string, std::vector<std::shared_ptr<algebra::Function>>> map;
    
    std::unordered_map<std::string, std::vector<std::shared_ptr<algebra::Function>>>::iterator iter;
    
    void buildMap();
    std::vector<std::shared_ptr<algebra::Function>> initFuncs(const algebra::Row& row);
    
};
#endif /* GroupByIterator_h */
