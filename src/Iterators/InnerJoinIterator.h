//
//  InnerJoinIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef InnerJoinIterator_h
#define InnerJoinIterator_h

#include <stdio.h>
#include "JoinIterator.h"
#include "Utilities.h"
#include "sstream"

class InnerJoinIterator : public JoinIterator {
public:
    InnerJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);
    bool hasNext() override;

};
#endif /* InnerJoinIterator_h */
