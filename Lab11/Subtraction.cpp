#include "Subtraction.h"
#include "RationalFraction.h"

RationalFraction Subtraction::calculate(const RationalFraction& rf1, const RationalFraction& rf2) {
    return RationalFraction(rf1 - rf2);
}
