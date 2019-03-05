//
//  Distinct.hpp
//  db
//
//  Created by Tingting Fan on 3/4/19.
//  Copyright © 2019 Tingting Fan. All rights reserved.
//

#ifndef Distinct_hpp
#define Distinct_hpp

#include <stdio.h>
#include "Expression.h"
#include "vector"
#include "Row.h"
#include "Column.h"
namespace algebra {
    
    class Distinct : public Expression {
    public:
        std::string getType() override;
        
        std::string findValue(const algebra::Row& row) override;
        std::string findType() override;
        std::string findName() override;
        
        Distinct(const std::vector<std::shared_ptr<algebra::Column>>& cols);
        
        const std::vector<std::shared_ptr<algebra::Column>>& getCols() const;
        void setCols(const std::vector<std::shared_ptr<algebra::Column>>& cols);
        
        bool isDuplicate(const std::string& key);
        std::pair<bool, std::string> isDuplicate(const algebra::Row& row);
        bool addToSet(const std::string& key);
        std::string extracted(const algebra::Row &row);
        
        std::pair<bool, std::string> addToSet(const algebra::Row& row);
        
    private:
        std::vector<std::shared_ptr<algebra::Column>> cols;
        std::unordered_set<std::string> set;
        const std::string type = "DISTINCT";
    };
}



#endif /* Distinct_hpp */
