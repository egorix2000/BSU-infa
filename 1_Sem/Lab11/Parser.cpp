#include <string>
#include <cctype>
#include <iostream>
#include "Parser.h"
#include "RationalFractionOperation.h"
#include "ExpressionException.h"
#include "Exception.h"
#include "RationalFraction.h"
#include "Sum.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Validator.h"

RationalFraction Parser::parseRationalFraction(std::string s) {
    char temp;
    int sign;
    bool hasSlash;
    RationalFraction rf;
    int numerator = 0;
    int denominator = 0;

    if (s.size() == 0) {
        throw ExpressionException();
    }

    sign = 1;
    if (s[0] == '-') {
        sign = -1;
        s.erase(0, 1);
    }

    hasSlash = false;
    for(int i = 0; i < s.size(); i++) {
        temp = s[i];
        if(isdigit(temp)) {
            if (!hasSlash) {
                numerator *= 10;
                numerator += (temp - '0');
            } else {
                denominator *= 10;
                denominator += (temp - '0');
            }
        } else if(!hasSlash && temp =='/') {
            hasSlash = true;
        } else {
            throw ExpressionException();
        }
    }
    numerator *= sign;

    if (!hasSlash){
        denominator = 1;
    }
    rf = RationalFraction(numerator, denominator);
    try{
        Validator::validateRationalFraction(rf);
    } catch (ExpressionException& e) {
        throw;
    }
    return rf;
}

RationalFractionOperation Parser::parse(std::string s) {
    RationalFraction rf1;
    RationalFraction rf2;
    std::string operatorType;
    Operator* op;
    RationalFractionOperation operation;

    size_t space1 = s.find(" ");
    size_t space2 = s.rfind(" ");

    if(space1 == std::string::npos) {
        rf1 = RationalFraction(this->parseRationalFraction(s));
        operatorType = '*';
        rf2 = RationalFraction(1, 1);
    } else if(space2 != space1) {
        rf1 = RationalFraction(this->parseRationalFraction(s.substr(0, space1)));
        operatorType = s.substr(space1 + 1, space2 - space1 - 1);
        rf2 = RationalFraction(this->parseRationalFraction(s.substr(space2 + 1, s.size() - space2 - 1)));
    } else {
        throw ExpressionException();
    }
    try{
        Validator::validateOperatorType(operatorType);
    } catch (Exception& e) {
        throw;
    }

    switch (operatorType[0]) {
        case '+':
            op = new Sum();
            break;
        case '-':
            op = new Subtraction();
            break;
        case '*':
            op = new Multiplication();
            break;
        case '/':
            op = new Division();
            break;
        default:
            throw ExpressionException();
            break;
    }
    operation = RationalFractionOperation(rf1, rf2, op);
    return operation;
}
