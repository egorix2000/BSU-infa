#include "RationalFraction.h"
#include "Math.h"

RationalFraction::RationalFraction() {
    this->numerator = 0;
    this->denominator = 0;
}

RationalFraction::RationalFraction(const RationalFraction& sourse) {
    this->numerator = sourse.getNumerator();
    this->denominator = sourse.getDenominator();
}

RationalFraction::RationalFraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

int RationalFraction::getDenominator() const{
    return this->denominator;
}

RationalFraction* RationalFraction::setDenominator(int denominator) {
    this->denominator = denominator;
    return this;
}

int RationalFraction::getNumerator() const{
    return this->numerator;
}

RationalFraction* RationalFraction::setNumerator(int numerator) {
    this->numerator = numerator;
    return this;
}

RationalFraction* RationalFraction::reduce() {
    int gcd = calcGcd(abs(this->numerator), abs(this->denominator));
    this->numerator /= gcd;
    this->denominator /= gcd;
    return this;
}

int RationalFraction::compare(const RationalFraction& rf) {
    int numerator = this->getNumerator() * rf.getDenominator() - this->getDenominator() * rf.getNumerator();
    int denominator = this->getDenominator() * rf.getDenominator();
    return numerator * denominator;
}

RationalFraction RationalFraction::operator+(const RationalFraction& rf) const{
    int numerator = this->numerator * rf.getDenominator() + this->denominator * rf.getNumerator();
    int denominator = this->denominator * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator-(const RationalFraction& rf) const{
    int numerator = this->numerator * rf.getDenominator() - this->denominator * rf.getNumerator();
    int denominator = this->denominator * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator*(const RationalFraction& rf) const{
    int numerator = this->numerator * rf.getNumerator();
    int denominator = this->denominator * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator/(const RationalFraction& rf) const{
    int numerator = this->numerator * rf.getDenominator();
    int denominator = this->denominator * rf.getNumerator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}
