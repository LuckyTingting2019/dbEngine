//
//  QueryOptimizer.hpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#ifndef QueryOptimizer_hpp
#define QueryOptimizer_hpp

#include <stdio.h>
#include "vector"
#include "Rule.hpp"
#include "Relation.h"
class QueryOptimizer {
public:
    QueryOptimizer(const std::shared_ptr<algebra::Relation>& root);
    
    void setRoot(const std::shared_ptr<algebra::Relation>& root);
    std::shared_ptr<algebra::Relation> optimize();
    
private:
    std::vector<std::shared_ptr<Rule>> rules;
    std::shared_ptr<algebra::Relation> root;
    void setRules();
};
#endif /* QueryOptimizer_hpp */
