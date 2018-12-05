#pragma once
#ifndef SUBTRACTION_H_INCLUDED
#define SUBTRACTION_H_INCLUDED

#include "Operator.h"
#include "RationalFraction.h"

class Subtraction : public Operator {
    public:
        RationalFraction calculate(const RationalFraction& rf1, const RationalFraction& rf2);
        char toChar();
};

#endif // SUBTRACTION_H_INCLUDED
