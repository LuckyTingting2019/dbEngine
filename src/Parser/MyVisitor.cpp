//
//  MyVisitor.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/5/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//
#include "MyVisitor.h"

antlrcpp::Any queryparser::MyVisitor::visitSelect_stmt(QueryParser::Select_stmtContext *ctx) {
    //children and parent
    std::vector<antlr4::tree::ParseTree*> children1;
    
    std::cout << "Children: " << std::endl;
    children1 = ctx -> children;
    for (std::vector<antlr4::tree::ParseTree*>::size_type i = 0; i != children1.size(); i++) {
        auto tmp = children1[i] -> getText();
        std::cout << tmp << std::endl;
        //SELECT
        //a
        //FROM
        //A
        std::cout << tmp.empty() << std::endl;
        std::cout << typeid(tmp).name() << std::endl;
        std::cout << typeid(children1[i]).name() << std::endl;
    }
    
    std::cout << "Parents: " << std::endl;
    auto *pare = ctx -> parent; //nullptr
    if (pare) {
        //std::cout << pare -> getText() << std::endl;
        //std::cout << pare -> toString() << std::endl;
    }
    
    //rule index
    std::cout << "rule index of select statement: ";
    std::cout << ctx -> getRuleIndex() << std::endl;
    /*
    //columns
    std::cout << "Columns: " << std::endl;
    std::vector<QueryParser::ColumnsContext*> columns = ctx -> columns();
    for (std::vector<QueryParser::ColumnContext*>::size_type i = 0; i != columns.size(); ++i) {
        std::cout << "rule index of columns " + std::to_string(i) + ":";
        std::cout << columns[i] -> getRuleIndex() << std::endl;
        
        //table
        std::cout << "table name" + std::to_string(i) + ":";
        QueryParser::TableContext* table = columns[i] -> table();
        
        std::cout << table << std::endl;
        if (table) {
            antlr4::tree::TerminalNode* leaf = table -> Name();
            std::cout << leaf -> toString() << std::endl;
            std::cout << leaf -> getText() << std::endl;
            std::cout << table -> getText() << std::endl;
            std::cout << table -> getRuleIndex() << std::endl;
            std::cout << table -> getStop() << std::endl;
            std::cout << table -> getStart() << std::endl;
        }
        
        //termialNode
        std::cout << "terminal nodes: " << std::endl;
        antlr4::tree::TerminalNode* leaf1 = columns[i] -> Name();
        std::cout << leaf1 -> toString() << std::endl;
        std::cout << leaf1 -> getText() << std::endl;
    }
    
    //tables
    std::vector<QueryParser::TableContext*> tables = ctx -> table();
    for (std::vector<QueryParser::TableContext*>::size_type i = 0; i != tables.size(); ++i) {
        std::cout << "rule index of tables " + std::to_string(i) + ":";
        std::cout << tables[i] -> getRuleIndex() << std::endl;
        
        //termialNode
        std::cout << "terminal nodes: " << std::endl;
        antlr4::tree::TerminalNode* leaf1 = tables[i] -> Name();
        std::cout << leaf1 -> toString() << std::endl;
        std::cout << leaf1 -> getText() << std::endl;
    }
     */
    return visitChildren(ctx);
}

antlrcpp::Any queryparser::MyVisitor::visitColumn(QueryParser::ColumnContext *ctx) {
    //children and parent
    std::vector<antlr4::tree::ParseTree*> children1;
    
    std::cout << "Children: " << std::endl;
    children1 = ctx -> children;
    for (std::vector<antlr4::tree::ParseTree*>::size_type i = 0; i != children1.size(); i++) {
        std::cout << children1[i] -> getText() << std::endl;
    }
    
    std::cout << "Parents: " << std::endl;
    auto *pare = ctx -> parent; //nullptr
    if (pare) {
        std::cout << pare -> getText() << std::endl;//SELECTaFROMA
        std::cout << pare -> toString() << std::endl;//[]
        std::cout << pare -> toStringTree() << std::endl;//(SELECTaFROMA; SELECT (a a) FROM (A A) ;)
    }
    
    //rule index
    std::cout << "rule index of column statement: ";
    std::cout << ctx -> getRuleIndex() << std::endl;
    
    //tables
    QueryParser::TableContext* table = ctx -> table();
    
    if (table) {
        std::cout << "rule index of tables:";
        std::cout << table -> getRuleIndex() << std::endl;
    }
    
    //termialNode
    std::cout << "terminal nodes: " << std::endl;
    antlr4::tree::TerminalNode* leaf1 = ctx -> Name();
    std::cout << leaf1 -> toString() << std::endl; //a
    std::cout << leaf1 -> getText() << std::endl; //a
    return visitChildren(ctx);
}

antlrcpp::Any queryparser::MyVisitor::visitTable(QueryParser::TableContext *ctx) {
    //children and parent
    std::vector<antlr4::tree::ParseTree*> children1;
    
    std::cout << "Children: " << std::endl;
    children1 = ctx -> children;
    for (std::vector<antlr4::tree::ParseTree*>::size_type i = 0; i != children1.size(); i++) {
        std::cout << children1[i] -> getText() << std::endl;
    }
    
    std::cout << "Parents: " << std::endl;
    auto *pare = ctx -> parent; //nullptr
    if (pare) {
        std::cout << pare -> getText() << std::endl;//SELECTaFROMA
        std::cout << pare -> toString() << std::endl;//[]
        std::cout << pare -> toStringTree() << std::endl;//(SELECTaFROMA; SELECT (a a) FROM (A A) ;)
    }
    
    //rule index
    std::cout << "rule index of select statement: ";
    std::cout << ctx -> getRuleIndex() << std::endl;
    
    //termialNode
    std::cout << "terminal nodes: " << std::endl;
    antlr4::tree::TerminalNode* leaf1 = ctx -> Name();
    std::cout << leaf1 -> toString() << std::endl;
    std::cout << leaf1 -> getText() << std::endl;
    return visitChildren(ctx);
}

