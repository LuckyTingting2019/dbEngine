//
//  NaturalJoinIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef NaturalJoinIterator_h
#define NaturalJoinIterator_h

#include <stdio.h>
#include "JoinIterator.h"
#include "Utilities.h"
#include "sstream"

class NaturalJoinIterator : public JoinIterator {
    //match based on all common columns. Return cartesian product if no common columns
public:
    NaturalJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);
    bool hasNext() override;
    
private:
    std::vector<std::string> commonFieldsSimple;
    std::string tableNameL;
    std::string tableNameR;
    
    void findCommonFields();
    void setTableMap();
    algebra::Row mergeRows(const algebra::Row& left, const algebra::Row& right) override;
    //bool isMatch(const Row& row1, const Row& row2);
};






#endif /* NaturalJoinIterator_h */
