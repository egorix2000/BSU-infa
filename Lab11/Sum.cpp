#include "Sum.h"
#include "RationalFraction.h"

RationalFraction Sum::calculate(const RationalFraction& rf1, const RationalFraction& rf2) {
    return RationalFraction(rf1 + rf2);
}
