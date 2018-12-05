#ifndef RATIONALFRACTIONOPERATION_H_INCLUDED
#define RATIONALFRACTIONOPERATION_H_INCLUDED

#include <string>
#include "Operator.h"
#include "RationalFraction.h"

class RationalFractionOperation {
    public:
        RationalFractionOperation();
        RationalFractionOperation(const RationalFraction& rf1, const RationalFraction& rf2, Operator* op);
        RationalFractionOperation(const RationalFractionOperation& operation);
        RationalFraction execute();
        RationalFraction getRf1() const;
        RationalFraction getRf2() const;
        Operator* getOperator() const;
        std::string toString();

    private:
        RationalFraction rf1_;
        RationalFraction rf2_;
        Operator* op_;
};

#endif // RATIONALFRACTIONOPERATION_H_INCLUDED
