#pragma once
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Item.h"

class List {
    private:
        Item* head;
        Item* tail;
    public:
        List();
        List(char value);
        List(int value);
        void add(char value);
        void add(int value);
        Item* getHead();
        Item* getTail();
        void reset();
};

#endif // LIST_H_INCLUDED
