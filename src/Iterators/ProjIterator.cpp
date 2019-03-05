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
#include "Distinct.hpp"

ProjIterator::ProjIterator(std::shared_ptr<algebra::Projection> proj, std::shared_ptr<Iterator> downStream) : proj(proj), downStream(downStream) {}

bool ProjIterator::hasNext() {
    algebra::Row row;
    algebra::Row res;
    std::string colName;
    if (Schema::getHasDistinct()) {
        if (proj -> getColumns().size() != 1) {
            throw "Incorrect number of projected columns with Distinct.";
        } else {
            //projection could be a column, a function, a distinct, or numeric binary expression
            std::shared_ptr<algebra::Expression> expr = proj -> getColumns()[0];
            if (typeid(*expr).name() == typeid(algebra::Distinct).name()) {
                std::shared_ptr<algebra::Distinct> dis = std::dynamic_pointer_cast<algebra::Distinct>(expr);
                while (downStream -> hasNext()) {
                    row = downStream -> next();
                    std::pair<bool, std::string> p = dis -> addToSet(row);
                    if (p.first) {
                        colName = dis -> findName();
                        res.put(colName, p.second);
                        nextRow = res;
                        return true;
                    }
                }
                return false;
            } else {
                bool ret = false;
                std::shared_ptr<algebra::Function> func = std::dynamic_pointer_cast<algebra::Function>(expr);
                std::shared_ptr<algebra::Distinct> dis = std::dynamic_pointer_cast<algebra::Distinct>(func -> getExpr());
                while (downStream -> hasNext()) {
                    ret = true;
                    row = downStream -> next();
                    std::pair<bool, std::string> p = dis -> addToSet(row);
                    if (p.first) {
                        func -> update(row);
                    }
                }
                res.put(func -> findName(), func -> findValue());
                nextRow = res;
                return ret;
            }
        }
    } else {
        if (downStream -> hasNext()) {
            row = downStream -> next();
            for(auto x : proj -> getColumns()) {
                colName = x -> findName();
                res.put(colName, x -> findValue(row));
            }
            nextRow = res;
            return true;
        } else {
            return false;
        }
    }
}

algebra::Row ProjIterator::next() {
    return nextRow;
}

void ProjIterator::print() {
    std::stringstream ss;
    std::string s;
    std::string name;
    ss << "  ";
    for (auto x : proj -> getColumns()) {
        name = x -> getAlias() == "" ? x -> findName() : x -> getAlias();
        ss << std::left;
        ss << std::setw(14);
        ss << name + ", ";
    }
    s = ss.str();
    while (s.at(s.length() - 1) != ',') {
        s.pop_back();
    }
    s.pop_back();
    std::cout << s << std::endl;
    
    ss.str(std::string());
    //cout << "After clear: " << ss.str() << endl;
    algebra::Row row;
    while(hasNext()) {
        row = next();
        ss << "  ";
        for(auto x : proj -> getColumns()) {
            ss << std::left;
            ss << std::setw(14);
            ss << row.get(x -> findName()) + ", ";
        }
        s = ss.str();
        while (s.at(s.length() - 1) != ',') {
            s.pop_back();
        }
        s.pop_back();
        std::cout << s << std::endl;
        ss.str(std::string());
    }
}


