//
//  JoinIteratorBuilder.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/19/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef JoinIteratorBuilder_h
#define JoinIteratorBuilder_h

#include <stdio.h>
#include "JoinIterator.h"
#include "InnerJoinIterator.h"
#include "LeftJoinIterator.h"
#include "RightJoinIterator.h"
#include "NaturalJoinIterator.h"
#include "Join.h"
class JoinIteratorBuilder {
public:
    JoinIteratorBuilder() = default;
    static std::shared_ptr<JoinIterator> buildJoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);
};


#endif /* JoinIteratorBuilder_h */
