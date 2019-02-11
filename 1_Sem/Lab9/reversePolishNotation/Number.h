#pragma once
#ifndef NUMBER_H_INCLUDED
#define NUMBER_H_INCLUDED

#include "Item.h"

class Number : public Item {
    private:
        int value;
    public:
        Number(int value, Item* previous, Item* next);
        int getValue();
        void setValue(int value);
        int calc();
};

#endif // NUMBER_H_INCLUDED
