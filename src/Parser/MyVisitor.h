//
//  MyVisitor.hpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/5/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#ifndef MyVisitor_h
#define MyVisitor_h

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "antlr4-runtime.h"
#include "QueryBaseVisitor.h"
namespace queryparser {
    
class MyVisitor : public QueryBaseVisitor {
        
    public:
        antlrcpp::Any visitSelect_stmt(QueryParser::Select_stmtContext *ctx) override;
        
        antlrcpp::Any visitColumn(QueryParser::ColumnContext *ctx) override;
        
        antlrcpp::Any visitTable(QueryParser::TableContext *ctx) override;
        
    };
    
}  // namespace queryparser

#endif
