//
//  JoinIterator.h
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/15/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef JoinIterator_h
#define JoinIterator_h

#include <stdio.h>
#include "Iterator.h"
#include "Join.h"
#include "Table.h"
#include "CSVIterator.h"
#include "Row.h"
#include "Utilities.h"

class JoinIterator : public Iterator {
public:
    JoinIterator(const std::shared_ptr<algebra::Join>& join_ptr);

    algebra::Row next() override;

protected:
    std::shared_ptr<algebra::Join> join_ptr;
    std::shared_ptr<Iterator> leftStream;
    std::shared_ptr<Iterator> rightStream;
    
    //join column of leftTable
    std::shared_ptr<algebra::Column> leftCol_ptr;
    //join column of rightTable
    std::shared_ptr<algebra::Column> rightCol_ptr;
    std::unordered_map<std::string, std::vector<algebra::Row>> tableMap;
    
    std::vector<algebra::Row> currentRows;
    algebra::Row leftRow;
    algebra::Row rightRow;
    algebra::Row joinedRow;
    
    
    void setTableMap(const std::shared_ptr<Iterator>& stream, const std::shared_ptr<algebra::Column>& col_ptr);
    void getJoinColumns(const std::shared_ptr<algebra::Table>& leftT_ptr, const std::shared_ptr<algebra::Table>& rightT_ptr);
    virtual algebra::Row mergeRows(const algebra::Row& left, const algebra::Row& right);
    algebra::Row getEmptyRow(const algebra::Row& row, const std::string& colFullName, const std::string& colValue);
};
#endif /* JoinIterator_h */
