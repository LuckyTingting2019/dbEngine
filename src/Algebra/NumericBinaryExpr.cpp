//
//  NumericBinaryExpr.cpp
//  antlr4-cpp-demo
//
//  Created by Tingting Fan on 2/21/19.
//  Copyright © 2019 ANTLR4 Project. All rights reserved.
//

#include "NumericBinaryExpr.h"
std::string algebra::NumericBinaryExpr::getType() {
    return this -> type;
}

std::string algebra::NumericBinaryExpr::findValue(const algebra::Row& row) {
    if (row.containsField(findName())) {
        return row.get(findName());
    } else if (row.containsField(getAlias())) {
        return row.get(getAlias());
    }
    std::string leftV = left -> findValue(row);
    std::string rightV = right -> findValue(row);
    if (leftV == "NULL" || rightV == "NULL") {
        return "NULL";
    }
    std::string type = findType();
    std::string result;
    int lefti = 0;
    int righti = 0;
    double leftd = 0.0;
    double rightd = 0.0;
    if (type == "int") {
        lefti = std::stoi(leftV);
        righti = std::stoi(rightV);
    } else if (type == "float") {
        leftd = std::stod(leftV);
        rightd = std::stod(rightV);
    } else if (type == "varchar") {
        if (oper == "+") {
            return leftV + rightV;
        } else {
            throw "Unsupported operation for type varchar.";
        }
    } else {
        throw "Unsupported data type: " + type + " for numeric binary expression";
    }
    if (oper == "+") {
        result = std::to_string(type == "int" ? lefti + righti : leftd + rightd);
    } else if (oper == "-") {
        result = std::to_string(type == "int" ? lefti - righti : leftd - rightd);
    } else if (oper == "*") {
        result = std::to_string(type == "int" ? lefti * righti : leftd * rightd);
    } else if (oper == "/") {
        result = std::to_string(type == "int" ? lefti / righti : leftd / rightd);
    } else {
        throw "Unsupported operator: " + oper;
    }
    return result;
}
std::string algebra::NumericBinaryExpr::findType() {
    std::string typel = left -> findType();
    std::string typer = right -> findType();
    std::string type;
   if (typel == "varchar" || typer == "varchar") {
       type = "varchar";
        //throw "Not comparable left and right value types: " + typel + ", " + typer;
   } else  if (typel == typer) {
       type = typel;
   } else {
        type = "float";
    }
    return type;
}

std::string algebra::NumericBinaryExpr::findName() {
    return left -> findName() + " " + oper + " " + right -> findName();
}

algebra::NumericBinaryExpr::NumericBinaryExpr(const std::shared_ptr<algebra::Expression>& left, const std::string& oper, const std::shared_ptr<algebra::Expression>& right) : algebra::BinaryExpr(left, oper, right) {}


