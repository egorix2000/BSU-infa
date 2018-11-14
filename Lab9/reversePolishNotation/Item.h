#pragma once
#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

class Item {
    protected:
        Item* prev;
        Item* next;

    public:
        virtual int calc() { return -1; };
        virtual int getValue() { return -1; };
        Item* getNext();
        Item* getPrev();
        void setNext(Item* next);
        void setPrev(Item* prev);
};

#endif // ITEM_H_INCLUDED
