#include <iostream>
#include "RationalFraction.h"
#include "Math.h"

RationalFraction::RationalFraction(){
    this->numerator = 0;
    this->denominator = 0;
}

RationalFraction::RationalFraction(const RationalFraction& sourse){
    this->numerator = sourse.numerator;
    this->denominator = sourse.denominator;
}

RationalFraction::RationalFraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

int RationalFraction::getDenominator(){
    return this->denominator;
}

RationalFraction* RationalFraction::setDenominator(int denominator){
    this->denominator = denominator;
    return this;
}

int RationalFraction::getNumerator(){
    return this->numerator;
}

RationalFraction* RationalFraction::setNumerator(int numerator){
    this->numerator = numerator;
    return this;
}

RationalFraction* RationalFraction::reduce(){
    int gcd = calcGcd(this->numerator, this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
    return this;
}

RationalFraction* RationalFraction::operator+=(const RationalFraction& rf){
    this->numerator = this->numerator * rf.denominator + this->denominator * rf.numerator;
    this->denominator *= rf.denominator;
    this->reduce();
    return this;
}

RationalFraction* RationalFraction::operator*=(const RationalFraction& rf){
    this->numerator *= rf.numerator;
    this->denominator *= rf.denominator;
    this->reduce();
    return this;
}

RationalFraction* RationalFraction::operator/=(const RationalFraction& rf){
    this->numerator *= rf.denominator;
    this->denominator *= rf.numerator;
    this->reduce();
    return this;
}

int RationalFraction::compare(const RationalFraction& rf){
    int numerator = this->numerator * rf.denominator - this->denominator * rf.numerator;
    int denominator = this->denominator * rf.denominator;
    return numerator * denominator;
}

void RationalFraction::print(){
    std::cout << this->numerator << "/" << this->denominator << std::endl;
}
