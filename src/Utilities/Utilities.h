//
//  Utilities.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/17/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef Utilities_h
#define Utilities_h

#include <stdio.h>
#include "vector"
#include "string"
#include "sstream"
#include "Expression.h"

class Utilities {
public:
    static std::vector<std::string> split(const std::string& input, const char& delimiter);
    static void deduplicate(std::vector<std::shared_ptr<algebra::Expression>>& cols);
};
#endif /* Utilities_h */
