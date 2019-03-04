//
//  ProjectionIterator.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/7/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "ProjIterator.h"
#include "NumericBinaryExpr.h"
#include "iomanip"

ProjIterator::ProjIterator(std::shared_ptr<algebra::Projection> proj, std::shared_ptr<Iterator> downStream) : proj(proj), downStream(downStream) {}

bool ProjIterator::hasNext() {
    return downStream -> hasNext();
}

algebra::Row ProjIterator::next() {
    algebra::Row row = downStream -> next();
    algebra::Row res(row.getTableName());
    std::string colName;
    //projection could be a column, a function, or numeric binary expression
    for(auto x : proj -> getColumns()) {
        colName = x -> findName();
        res.put(colName, x -> findValue(row));
        //std::cout << std::to_string(typeid(*x).name() == typeid(algebra::NumericBinaryExpr).name()) << std::endl;
        /*
        if (typeid(*x).name() == typeid(algebra::NumericBinaryExpr).name()) {
            res.put(colName, x -> findValue(row));
        } else {
            if (!row.containsField(colName)) {
                throw "Invalid Projection of Column: " + colName;
            } else {
                res.put(colName, row.get(colName));
            }
        }
        */
    }
    return res;
}

void ProjIterator::print() {
    std::stringstream ss;
    std::string s;
    std::string name;
    for (auto x : proj -> getColumns()) {
        name = x -> getAlias() == "" ? x -> findName() : x -> getAlias();
        ss << std::left;
        ss << std::setw(20);
        ss << name + ", ";
    }
    s = ss.str();
    s.pop_back();
    s.pop_back();
    std::cout << s << std::endl;
    
    ss.str(std::string());
    //cout << "After clear: " << ss.str() << endl;
    algebra::Row row;
    while(hasNext()) {
        row = next();
        for(auto x : proj -> getColumns()) {
            ss << std::left;
            ss << std::setw(20);
            ss << row.get(x -> findName()) + ", ";
        }
        s = ss.str();
        s.pop_back();
        s.pop_back();
        std::cout << s << std::endl;
        ss.str(std::string());
    }
}


