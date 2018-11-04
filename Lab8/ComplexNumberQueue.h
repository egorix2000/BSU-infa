#pragma once
#ifndef COMPLEXNUMBERQUEUE_H_INCLUDED
#define COMPLEXNUMBERQUEUE_H_INCLUDED

#include "ComplexNumberQueueNode.h"
#include "ComplexNumber.h"

class ComplexNumberQueue{
    private:
        ComplexNumberQueueNode* front;
        ComplexNumberQueueNode* back;
    public:
        ComplexNumberQueue();
        ComplexNumberQueue(const ComplexNumber& firstElement);
        void pop_front();
        void push_back(const ComplexNumber& cn);
        ComplexNumber getFront();
        ComplexNumber getBack();
        bool isEmpty();
        void reset();
        int getSize();

};

#endif // COMPLEXNUMBERQUEUE_H_INCLUDED
