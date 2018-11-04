#include "ComplexNumberStack.h"
#include "ComplexNumberStackNode.h"
#include "ComplexNumber.h"

ComplexNumberStack::ComplexNumberStack(){
    this->top = 0;
}

ComplexNumberStack::ComplexNumberStack(const ComplexNumber& top){
    ComplexNumberStackNode *newTop = new ComplexNumberStackNode(top);
    this->top = newTop;
}

int ComplexNumberStack::getSize(){
    int stackSize = 0;
    ComplexNumberStackNode* current = this->top;
    while (current){
        stackSize++;
        current = current->next;
    }
    delete current;
    return stackSize;
}

void ComplexNumberStack::pop(){
    if(this->top){
        this->top = this->top->next;
    }
}

void ComplexNumberStack::push(const ComplexNumber& cn){
    ComplexNumberStackNode *newTop = new ComplexNumberStackNode(cn, this->top);
    this->top = newTop;
}

ComplexNumber ComplexNumberStack::getTop(){
    return this->top->value;
}

bool ComplexNumberStack::isEmpty(){
    if (this->top){
        return false;
    } else {
        return true;
    }
}

void ComplexNumberStack::reset(){
    this->top = 0;
}
