#pragma once
#ifndef OPERATOR_H_INCLUDED
#define OPERATOR_H_INCLUDED

#include "RationalFraction.h"

class Operator {
    public:
        virtual RationalFraction calculate(const RationalFraction& rf1, const RationalFraction& rf2) = 0;
};

#endif // OPERATOR_H_INCLUDED
