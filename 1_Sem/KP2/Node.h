#pragma once
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node{
    public:
        T value;
        Node* next;
        Node(const T& value, Node* nextNode);
        ~Node();
};

template <class T>
Node<T>::~Node() {
    next = 0;
}

template <class T>
Node<T>::Node(const T& value, Node* nextNode) {
    this->value = value;
    this->next = nextNode;
};

#endif // NODE_H_INCLUDED
