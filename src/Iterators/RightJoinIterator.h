//
//  RightJoinIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef RightJoinIterator_h
#define RightJoinIterator_h

#include <stdio.h>
#include "JoinIterator.h"
class RightJoinIterator : public JoinIterator {
public:
    RightJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);
    bool hasNext() override;
    
};
#endif /* RightJoinIterator_h */
