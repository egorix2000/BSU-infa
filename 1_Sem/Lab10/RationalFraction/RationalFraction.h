#pragma once
#ifndef RATIONALFRACTION_H_INCLUDED
#define RATIONALFRACTION_H_INCLUDED

class RationalFraction {
    private:
        RationalFraction* reduce();
        int numerator;
        int denominator;

    public:
        RationalFraction();
        RationalFraction(const RationalFraction& rf);
        RationalFraction(int numerator, int denominator);
        int getDenominator() const;
        RationalFraction* setDenominator(int denominator);
        int getNumerator() const;
        RationalFraction* setNumerator(int numerator);
        RationalFraction* operator+=(const RationalFraction& rf);
        RationalFraction* operator*=(const RationalFraction& rf);
        RationalFraction* operator/=(const RationalFraction& rf);
        int compare(const RationalFraction& rf);
        void print();
};


#endif // RATIONALFRACTION_H_INCLUDED
