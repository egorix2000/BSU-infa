#include "ExpressionValidator.h"
#include "RationalFractionOperation.h"
#include "DivisionByZeroException.h"

bool ExpressionValidator::validate(RationalFractionOperation operation) {
    bool isValid = true;
    if (operation.getRf1().getDenominator() == 0 ||
            operation.getRf2().getDenominator() == 0 ||
                operation.execute().getDenominator() == 0) {
        isValid = false;
        throw DivisionByZeroException();
    }
    return isValid;
}
