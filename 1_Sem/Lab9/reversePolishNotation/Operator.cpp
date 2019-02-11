#include <iostream>
#include "Operator.h"
#include "Number.h"

Operator::Operator(char value, Item* previous, Item* next){
    this->value = value;
    this->prev = previous;
    this->next = next;
}

int Operator::calc(){
    Item* firstNum = this->prev->getPrev();
    Item* secondNum = this->prev;
    Number* num = new Number(0, firstNum->getPrev(), this->next);
    int value1 = firstNum->getValue();
    int value2 = secondNum->getValue();
    switch (this->value){
        case '+':
            num->setValue(value1 + value2);
            break;
        case '*':
            num->setValue(value1 * value2);
            break;
        case '/':
            num->setValue(value1 / value2);
            break;
        case '-':
            num->setValue(value1 - value2);
            break;
        default:
            break;
    }
    if (this->next){
        this->next->setPrev(num);
    }
    if (firstNum->getPrev()){
        firstNum->getPrev()->setNext(num);
    }
    return num->getValue();
}
