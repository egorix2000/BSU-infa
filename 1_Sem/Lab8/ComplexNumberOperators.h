#pragma once
#ifndef COMPLEXNUMBEROPERATORS_H_INCLUDED
#define COMPLEXNUMBEROPERATORS_H_INCLUDED

#include "ComplexNumber.h"

class ComplexNumberOperators{
    public:
        static ComplexNumber* add(ComplexNumber& cn1, const ComplexNumber& cn2);
        static ComplexNumber* subtract(ComplexNumber& cn1, const ComplexNumber& cn2);
        static ComplexNumber* multiply(ComplexNumber& cn1, const ComplexNumber& cn2);
        static ComplexNumber* divide(ComplexNumber& cn1, const ComplexNumber& cn2);
        static int cmp(const ComplexNumber& cn1, const ComplexNumber& cn2);
};

#endif // COMPLEXNUMBEROPERATORS_H_INCLUDED
