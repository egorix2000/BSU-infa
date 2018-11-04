#pragma once
#ifndef COMPLEXNUMBERSTACK_H_INCLUDED
#define COMPLEXNUMBERSTACK_H_INCLUDED

#include "ComplexNumber.h"
#include "ComplexNumberStackNode.h"


class ComplexNumberStack{
    private:
        ComplexNumberStackNode* top;
    public:
        ComplexNumberStack();
        ComplexNumberStack(const ComplexNumber& top);
        void pop();
        void push(const ComplexNumber& cn);
        ComplexNumber getTop();
        bool isEmpty();
        void reset();
        int getSize();
};

#endif // COMPLEXNUMBERSTACK_H_INCLUDED
