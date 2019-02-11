#pragma once
#ifndef OPERATOR_H_INCLUDED
#define OPERATOR_H_INCLUDED

#include "Item.h"

class Operator : public Item {
    private:
        char value;
    public:
        Operator(char value, Item* previous, Item* next);
        int calc();
};

#endif // OPERATOR_H_INCLUDED
