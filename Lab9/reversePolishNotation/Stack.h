#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Node.h"

template <class T>
class Stack{
    private:
        Node<T>* top;
    public:
        Stack();
        Stack(const T& top);
        void pop();
        void push(const T& value);
        T getTop();
        bool isEmpty();
        void reset();
        int getSize();
};

template <class T>
Stack<T>::Stack(){
    this->top = 0;
}

template <class T>
Stack<T>::Stack(const T& top){
    Node<T> *newTop = new Node<T>(top, 0);
    this->top = newTop;
}

template <class T>
int Stack<T>::getSize(){
    int stackSize = 0;
    Node<T>* current = this->top;
    while (current){
        stackSize++;
        current = current->next;
    }
    delete current;
    return stackSize;
}

template <class T>
void Stack<T>::pop(){
    if(this->top){
        this->top = this->top->next;
    }
}

template <class T>
void Stack<T>::push(const T& value){
    Node<T> *newTop = new Node<T>(value, this->top);
    this->top = newTop;
}

template <class T>
T Stack<T>::getTop(){
    return this->top->value;
}

template <class T>
bool Stack<T>::isEmpty(){
    if (this->top){
        return false;
    } else {
        return true;
    }
}

template <class T>
void Stack<T>::reset(){
    this->top = 0;
}

#endif // STACK_H_INCLUDED
