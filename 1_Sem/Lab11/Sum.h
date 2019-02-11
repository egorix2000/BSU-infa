#pragma once
#ifndef SUM_H_INCLUDED
#define SUM_H_INCLUDED

#include "Operator.h"
#include "RationalFraction.h"

class Sum : public Operator {
    public:
        RationalFraction calculate(const RationalFraction& rf1, const RationalFraction& rf2);
        char toChar();
};

#endif // SUM_H_INCLUDED
