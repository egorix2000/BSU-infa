#include "Multiplication.h"
#include "RationalFraction.h"

RationalFraction Multiplication::calculate(const RationalFraction& rf1, const RationalFraction& rf2) {
    return RationalFraction(rf1 * rf2);
}

char Multiplication::toChar() {
    return '*';
}
