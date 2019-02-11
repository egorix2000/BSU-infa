#pragma once
#ifndef VALIDATOR_H_INCLUDED
#define VALIDATOR_H_INCLUDED

#include <string>
#include "RationalFraction.h"

class Validator {
    public:
        static bool validateOperatorType(std::string type);
        static bool validateRationalFraction(const RationalFraction& rf);
};

#endif // VALIDATOR_H_INCLUDED
