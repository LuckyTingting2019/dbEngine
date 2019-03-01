/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

/*
#include <iostream>
#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"

using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char **) {
  ANTLRInputStream input(u8"🍴 = 🍐 + \"😎\";(((x * π))) * µ + ∰; a + (x * (y ? 0 : 1) + z);");
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  TParser parser(&tokens);
  tree::ParseTree *tree = parser.main();

  std::cout << tree->toStringTree(&parser) << std::endl;

  return 0;
}
 */

#include <iostream>
#include <sstream>
#include "antlr4-runtime.h"
#include "QueryLexer.h"
#include "QueryParser.h"
#include "AlgebraTree.h"
#include "ProjIterator.h"
#include "IteratorBuilder.h"
//#include "MyVisitor.h"
//#include "Projection.h"
//#include "CSVIterator.h"
//#include "JoinIterator.h"
//#include "Row.h"
//#include "FilterIterator.h"
//#include "JoinIteratorBuilder.h"
//#include "Relation.h"
//#include "Table.h"


int main(int , const char **) {
    std::string exitString = "exit";
    //ANTLRInputStream input(u8" SELECT ID FROM STD ");
    
    std::cout << "Please input your SQL command: \n";
    std::cout << "> ";
    for (std::string line; getline(std::cin, line) && line != exitString;) {
        Schema::reset();
        antlr4::ANTLRInputStream input(line);
        queryparser::QueryLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        queryparser::QueryParser parser(&tokens);
        std::shared_ptr<algebra::AlgebraTree> algebraTree = std::make_shared<algebra::AlgebraTree>(parser.select_stmt());
        std::shared_ptr<ProjIterator> projIterator_ptr = std::dynamic_pointer_cast<ProjIterator>(IteratorBuilder::build(algebraTree));
        if (projIterator_ptr) {
            projIterator_ptr -> print();
        }
        std::cout << "> ";
    }
    
    /*
    string tmp = "test";
    Row row(tmp);
    while (csvIterator.hasNext()) {
        row = csvIterator.next();
        row.print();
    }
    
    
    tree::ParseTree *tree = parser.select_stmt();
    std::cout << tree->toStringTree(&parser) << std::endl;
 
    QueryParser::Select_stmtContext* tree1 = parser.select_stmt();
    queryparser::QueryBaseVisitor visitor;
    antlrcpp::Any result = visitor.visitSelect_stmt(tree1);
    std::cout << typeid(result).name()<<std::endl;
    
    QueryParser::Select_stmtContext* tree1 = parser.select_stmt();
    queryparser::MyVisitor visitor;
    antlrcpp::Any result = visitor.visitSelect_stmt(tree1);
     */
    return 0;
}
//to do: fix when select * from natural join, common columns are printed twice.
