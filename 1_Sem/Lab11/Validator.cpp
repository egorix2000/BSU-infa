#include <string>
#include "Validator.h"
#include "RationalFraction.h"
#include "ExpressionException.h"
#include "DivisionByZeroException.h"

bool Validator::validateOperatorType(std::string type) {
    if (type.length() == 1) {
        return true;
    } else {
        throw ExpressionException();
    }
}

bool Validator::validateRationalFraction(const RationalFraction& rf) {
    if (rf.getDenominator() != 0) {
        return true;
    } else {
        throw DivisionByZeroException();
    }
}
