#include "ComplexNumberQueue.h"
#include "ComplexNumberQueueNode.h"
#include "ComplexNumber.h"

ComplexNumberQueue::ComplexNumberQueue(){
    this->front = 0;
    this->back = 0;
}

ComplexNumberQueue::ComplexNumberQueue(const ComplexNumber& firstElement){
    ComplexNumberQueueNode *newFirstElement = new ComplexNumberQueueNode(firstElement);
    this->front = newFirstElement;
    this->back = newFirstElement;
}

int ComplexNumberQueue::getSize(){
    int stackSize = 0;
    ComplexNumberQueueNode* current = this->front;
    while (current){
        stackSize++;
        current = current->next;
    }
    delete current;
    return stackSize;
}

void ComplexNumberQueue::pop_front(){
    if(this->front){
        this->front = this->front->next;
    }
}

void ComplexNumberQueue::push_back(const ComplexNumber& cn){
    ComplexNumberQueueNode *newBack = new ComplexNumberQueueNode(cn);
    if (!this->front){ // newBack is the first element in queue
        this->front = newBack;
        this->back = newBack;
    } else {
        this->back->next = newBack;
        this->back = newBack;
    }
}

ComplexNumber ComplexNumberQueue::getFront(){
    return this->front->value;
}

ComplexNumber ComplexNumberQueue::getBack(){
    return this->back->value;
}

bool ComplexNumberQueue::isEmpty(){
    if (this->front){
        return false;
    } else {
        return true;
    }
}

void ComplexNumberQueue::reset(){
    this->front = 0;
    this->back = 0;
}
