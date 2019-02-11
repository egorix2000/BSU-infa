#include "ComplexNumberOperators.h"
#include "ComplexNumber.h"

ComplexNumber* ComplexNumberOperators::add(ComplexNumber& cn1, const ComplexNumber& cn2){
    cn1.real += cn2.real;
    cn1.imaginary += cn2.imaginary;
    return &cn1;
};

ComplexNumber* ComplexNumberOperators::subtract(ComplexNumber& cn1, const ComplexNumber& cn2){
    cn1.real -= cn2.real;
    cn1.imaginary -= cn2.imaginary;
    return &cn1;
};

ComplexNumber* ComplexNumberOperators::multiply(ComplexNumber& cn1, const ComplexNumber& cn2){
    cn1.real *= cn2.real;
    cn1.imaginary *= cn2.imaginary;
    return &cn1;
};

ComplexNumber* ComplexNumberOperators::divide(ComplexNumber& cn1, const ComplexNumber& cn2){
    cn1.real /= cn2.real;
    cn1.imaginary /= cn2.imaginary;
    return &cn1;
};

int ComplexNumberOperators::cmp(const ComplexNumber& cn1, const ComplexNumber& cn2){
    double length1 = cn1.real * cn1.real + cn1.imaginary * cn1.imaginary;
    double length2 = cn2.real * cn2.real + cn2.imaginary * cn2.imaginary;
    if (length1 > length2){
        return 1;
    } else if (length1 == length2){
        return 0;
    } else {
        return -1;
    }
}
