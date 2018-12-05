#pragma once
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <string>
#include "RationalFractionOperation.h"
#include "RationalFraction.h"

class Parser {
    public:
        RationalFractionOperation parse(std::string s);
        int strToInt(std::string s);
        RationalFraction parseRationalFraction(std::string s);
};

#endif // PARSER_H_INCLUDED
