#pragma once
#ifndef RATIONALFRACTION_H_INCLUDED
#define RATIONALFRACTION_H_INCLUDED

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
    private:
        int numerator;
        int denominator;

};


#endif // RATIONALFRACTION_H_INCLUDED
