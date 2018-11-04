#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(){
    this->real = 0;
    this->imaginary = 0;
};

ComplexNumber::ComplexNumber(const ComplexNumber& sourse){
    this->real = sourse.real;
    this->imaginary = sourse.imaginary;
};

ComplexNumber::ComplexNumber(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
};
