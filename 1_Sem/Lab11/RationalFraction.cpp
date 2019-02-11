#include <string>
#include "RationalFraction.h"
#include "Math.h"

RationalFraction::RationalFraction() {
    numerator_ = 0;
    denominator_ = 0;
}

RationalFraction::RationalFraction(const RationalFraction& sourse) {
    numerator_ = sourse.getNumerator();
    denominator_ = sourse.getDenominator();
}

RationalFraction::RationalFraction(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
}

int RationalFraction::getDenominator() const{
    return denominator_;
}

RationalFraction* RationalFraction::setDenominator(int denominator) {
    denominator_ = denominator;
    return this;
}

int RationalFraction::getNumerator() const{
    return numerator_;
}

RationalFraction* RationalFraction::setNumerator(int numerator) {
    numerator_ = numerator;
    return this;
}

RationalFraction* RationalFraction::reduce() {
    int gcd = calcGcd(abs(numerator_), abs(denominator_));
    numerator_ /= gcd;
    denominator_ /= gcd;
    return this;
}

int RationalFraction::compare(const RationalFraction& rf) {
    int numerator = this->getNumerator() * rf.getDenominator() - this->getDenominator() * rf.getNumerator();
    int denominator = this->getDenominator() * rf.getDenominator();
    return numerator * denominator;
}

RationalFraction RationalFraction::operator+(const RationalFraction& rf) const{
    int numerator = numerator_ * rf.getDenominator() + denominator_ * rf.getNumerator();
    int denominator = denominator_ * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator-(const RationalFraction& rf) const{
    int numerator = numerator_ * rf.getDenominator() - denominator_ * rf.getNumerator();
    int denominator = denominator_ * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator*(const RationalFraction& rf) const{
    int numerator = numerator_ * rf.getNumerator();
    int denominator = denominator_ * rf.getDenominator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

RationalFraction RationalFraction::operator/(const RationalFraction& rf) const{
    int numerator = numerator_ * rf.getDenominator();
    int denominator = denominator_ * rf.getNumerator();
    RationalFraction rationalFraction (numerator, denominator);
    rationalFraction.reduce();
    return rationalFraction;
}

std::string RationalFraction::toString(){
    std::string s = std::to_string(numerator_);
    if (denominator_ != 1) {
        s += "/" + std::to_string(denominator_);
    }
    return s;
}
