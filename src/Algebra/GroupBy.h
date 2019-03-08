//
//  GroupBy.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef GroupBy_h
#define GroupBy_h

#include <stdio.h>
#include "Column.h"
#include "Function.h"
#include "vector"

namespace algebra {
    class GroupBy {
    public:
        GroupBy() = default;
        const std::vector<std::shared_ptr<algebra::Expression>>& getColumns() const;
        const std::vector<std::shared_ptr<algebra::Function>>& getFuncs() const;
        void setColumns(const std::vector<std::shared_ptr<algebra::Expression>>& columns);
        void setFuncs(const std::vector<std::shared_ptr<algebra::Function>>& funcs);
        
        void addColumn(const std::shared_ptr<algebra::Expression>& col);
        void addFunc(const std::shared_ptr<algebra::Function>& func);
        
        std::string toString();
        
        
    private:
        std::vector<std::shared_ptr<algebra::Expression>> columns;
        std::vector<std::shared_ptr<algebra::Function>> funcs;
    };
}
#endif /* GroupBy_h */
