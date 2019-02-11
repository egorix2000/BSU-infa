#include "List.h"
#include "Number.h"
#include "Operator.h"

List::List(){
    this->head = 0;
    this->tail = 0;
}

List::List(char value){
    Operator* op = new Operator(value, 0, 0);
    this->head = op;
    this->tail = op;
}

List::List(int value){
    Number* num = new Number(value, 0, 0);
    this->head = num;
    this->tail = num;
}

void List::add(char value){
    Operator* op = new Operator(value, 0, 0);
    if (this->head == 0){ // first element
        this->head = op;
        this->tail = op;
    } else {
        op->setPrev(this->tail);
        this->tail->setNext(op);
        this->tail = op;
    }
}

void List::add(int value){
    Number* num = new Number(value, 0, 0);
    if (this->head == 0){ // first element
        this->head = num;
        this->tail = num;
    } else {
        num->setPrev(this->tail);
        this->tail->setNext(num);
        this->tail = num;
    }
}

void List::reset(){
    this->head = 0;
}

Item* List::getHead(){
    return this->head;
}

Item* List::getTail(){
    return this->tail;
}
