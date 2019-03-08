//
//  PushDownConjunctivePredicates.hpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#ifndef PushDownConjunctivePredicates_hpp
#define PushDownConjunctivePredicates_hpp

#include <stdio.h>
#include "Relation.h"
#include "Rule.hpp"
#include "Filter.h"
#include "AlgebraTree.h"

class PushDownConjunctivePredicates : public Rule {
public:
    PushDownConjunctivePredicates(const std::shared_ptr<algebra::Relation>& relat_ptr);
    bool match() override;
    void convert() override;
    std::shared_ptr<algebra::Relation> process(std::shared_ptr<algebra::Relation>& relat_ptr);
    
private:
    std::unordered_map<std::string, std::shared_ptr<algebra::Filter>> filters;
    //std::shared_ptr<algebra::Relation> relat_ptr;
    std::shared_ptr<algebra::Relation> pushToSubTree(std::shared_ptr<algebra::AlgebraTree>& subTree);
};

#endif /* PushDownConjunctivePredicates_hpp */
