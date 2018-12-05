#pragma once
#ifndef MULTIPLICATION_H_INCLUDED
#define MULTIPLICATION_H_INCLUDED

#include "Operator.h"
#include "RationalFraction.h"

class Multiplication : public Operator {
    public:
        RationalFraction calculate(const RationalFraction& rf1, const RationalFraction& rf2);
};

#endif // MULTIPLICATION_H_INCLUDED
