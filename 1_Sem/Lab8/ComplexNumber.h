#pragma once
#ifndef COMPLEXNUMBER_H_INCLUDED
#define COMPLEXNUMBER_H_INCLUDED

class ComplexNumber {
    public:
        double real;
        double imaginary;

        ComplexNumber();
        ComplexNumber(const ComplexNumber& cn);
        ComplexNumber(double real, double imaginary);
};

#endif // COMPLEXNUMBER_H_INCLUDED
