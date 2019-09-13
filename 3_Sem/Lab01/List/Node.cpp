#include "Node.h"

template <class T>
Node<T>::Node(const T& value, Node *prev, Node *next) {
    this->value_ = value;
    this->prev_ = prev;
    this->next_ = next;
};

template <class T>
Node<T>::~Node() {
    delete next_;
    delete prev_;
}

template <class T>
const Node<T>* Node<T>::getNext() {
    return next_;
};

template <class T>
const Node<T>* Node<T>::getPrev() {
    return prev_;
};

template <class T>
const T& Node<T>::getValue() {
    return value_;
};

template <class T>
void Node<T>::setNext(Node<T>* next) {
    next_ = next;
};

template <class T>
void Node<T>::setPrev(Node<T>* prev) {
    prev_ = prev;
};

template <class T>
void Node<T>::setValue(const T value) {
    value_ = value;
}