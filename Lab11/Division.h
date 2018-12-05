#pragma once
#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED

#include "Operator.h"
#include "RationalFraction.h"

class Division : public Operator {
    public:
        RationalFraction calculate(const RationalFraction& rf1, const RationalFraction& rf2);
};

#endif // DIVISION_H_INCLUDED
