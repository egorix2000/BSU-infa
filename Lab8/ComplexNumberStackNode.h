#pragma once
#ifndef COMPLEXNUMBERSTACKNODE_H_INCLUDED
#define COMPLEXNUMBERSTACKNODE_H_INCLUDED

#include "ComplexNumber.h"

class ComplexNumberStackNode{
    public:
        ComplexNumber value;
        ComplexNumberStackNode* next;

        ComplexNumberStackNode();
        ComplexNumberStackNode(const ComplexNumber& value);
        ComplexNumberStackNode(const ComplexNumber& value, ComplexNumberStackNode* next);
};

#endif // COMPLEXNUMBERSTACKNODE_H_INCLUDED
