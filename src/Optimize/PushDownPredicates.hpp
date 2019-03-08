//
//  PushDownPredicates.hpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#ifndef PushDownPredicates_hpp
#define PushDownPredicates_hpp

#include <stdio.h>
#include "Relation.h"
#include "Rule.hpp"

class PushDownPredicates : public Rule {
    
public:
    PushDownPredicates(const std::shared_ptr<algebra::Relation>& relat_ptr);
    bool match() override;
    void convert() override;
    std::shared_ptr<algebra::Relation> process(std::shared_ptr<algebra::Relation>& relat_ptr);
    
    //std::shared_ptr<algebra::Relation> relat_ptr;
};
#endif /* PushDownPredicates_hpp */
