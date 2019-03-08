//
//  Rule.hpp
//  db
//
//  Created by Tingting Fan on 3/7/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#ifndef Rule_hpp
#define Rule_hpp

#include <stdio.h>
#include "Relation.h"
class Rule {
public:
    Rule(const std::shared_ptr<algebra::Relation>& relat_ptr);
    void excute();
    virtual bool match() = 0;
    virtual void convert() = 0;
    
protected:
    std::shared_ptr<algebra::Relation> relat_ptr;
};
#endif /* Rule_hpp */
