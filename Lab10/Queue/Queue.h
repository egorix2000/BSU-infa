#pragma once
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Node.h"

template <class T>
class Queue{
    private:
        Node<T>* front;
        Node<T>* back;
    public:
        Queue();
        Queue(const T& firstElementValue);
        void pop_front();
        void push_back(const T& value);
        T getFront();
        T getBack();
        bool isEmpty();
        void reset();
        int getSize();

};

template <class T>
Queue<T>::Queue(){
    this->front = 0;
    this->back = 0;
}

template <class T>
Queue<T>::Queue(const T& firstElementValue){
    Node<T> *newFirstElement = new Node<T>(firstElementValue, 0);
    this->front = newFirstElement;
    this->back = newFirstElement;
}

template <class T>
int Queue<T>::getSize(){
    int queueSize = 0;
    Node<T>* current = this->front;
    while (current){
        queueSize++;
        current = current->next;
    }
    delete current;
    return queueSize;
}

template <class T>
void Queue<T>::pop_front(){
    if(this->front){
        this->front = this->front->next;
    }
}

template <class T>
void Queue<T>::push_back(const T& value){
    Node<T> *newBack = new Node<T>(value, 0);
    if (!this->front){ // newBack is the first element in queue
        this->front = newBack;
        this->back = newBack;
    } else {
        this->back->next = newBack;
        this->back = newBack;
    }
}

template <class T>
T Queue<T>::getFront(){
    return this->front->value;
}

template <class T>
T Queue<T>::getBack(){
    return this->back->value;
}

template <class T>
bool Queue<T>::isEmpty(){
    if (this->front){
        return false;
    } else {
        return true;
    }
}

template <class T>
void Queue<T>::reset(){
    this->front = 0;
    this->back = 0;
}

#endif // QUEUE_H_INCLUDED
