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
        T getTop() const;
        bool isEmpty() const;
        void reset();
        int getSize() const;
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
int Stack<T>::getSize() const{
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
    Node<T>* temp = this->top;
    if(this->top){
        this->top = this->top->next;
    }
    delete temp;
}

template <class T>
void Stack<T>::push(const T& value){
    Node<T> *newTop = new Node<T>(value, this->top);
    this->top = newTop;
}

template <class T>
T Stack<T>::getTop() const{
    return this->top->value;
}

template <class T>
bool Stack<T>::isEmpty() const{
    return top == 0;
}

template <class T>
void Stack<T>::reset(){
    Node<T>* current = this->top;
    while (current){
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    this->top = 0;
}

#endif // STACK_H_INCLUDED
