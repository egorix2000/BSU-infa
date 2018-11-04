#pragma once
#ifndef COMPLEXNUMBERQUEUENODE_H_INCLUDED
#define COMPLEXNUMBERQUEUENODE_H_INCLUDED

#include "ComplexNumber.h"

class ComplexNumberQueueNode{
    public:
        ComplexNumber value;
        ComplexNumberQueueNode* next;

        ComplexNumberQueueNode();
        ComplexNumberQueueNode(const ComplexNumber& value);
        ComplexNumberQueueNode(const ComplexNumber& value, ComplexNumberQueueNode* next);
};

#endif // COMPLEXNUMBERQUEUENODE_H_INCLUDED
