//
//  Rule.cpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#include "Rule.hpp"
Rule::Rule(const std::shared_ptr<algebra::Relation>& relat_ptr) : relat_ptr(relat_ptr){};

void Rule::excute() {
    if (match()) {
        convert();
    }
}
