//
//  LeftJoinIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef LeftJoinIterator_h
#define LeftJoinIterator_h

#include <stdio.h>
#include "JoinIterator.h"
class LeftJoinIterator : public JoinIterator {
public:
    LeftJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);
    bool hasNext() override;
    
};


#endif /* LeftJoinIterator_h */
