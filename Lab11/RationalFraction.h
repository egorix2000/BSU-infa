#pragma once
#ifndef RATIONALFRACTION_H_INCLUDED
#define RATIONALFRACTION_H_INCLUDED

#include <string>

class RationalFraction {
    public:
        RationalFraction();
        RationalFraction(const RationalFraction& rf);
        RationalFraction(int numerator, int denominator);
        int getDenominator() const;
        RationalFraction* setDenominator(int denominator);
        int getNumerator() const;
        RationalFraction* setNumerator(int numerator);
        RationalFraction operator+(const RationalFraction& rf) const;
        RationalFraction operator-(const RationalFraction& rf) const;
        RationalFraction operator*(const RationalFraction& rf) const;
        RationalFraction operator/(const RationalFraction& rf) const;
        int compare(const RationalFraction& rf);
        RationalFraction* reduce();
        std::string toString();
    private:
        int numerator_;
        int denominator_;

};


#endif // RATIONALFRACTION_H_INCLUDED
