#pragma once
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node{
    private:
        T value;
        Node<T>* left;
        Node<T>* right;
        int counter;
    public:
        Node();
        Node(const T& value);
        Node(const T& value, int counter);
        Node(const T& value, Node<T>* rightNode, Node<T>* leftNode, int counter);
        ~Node();
        Node(const Node<T>& source);
        T getValue() const;
        void setValue(const T& value);
        int getCounter() const;
        void setCounter(int counter);
        Node<T>* getRight() const;
        void setRight(Node<T>* right);
        Node<T>* getLeft() const;
        void setLeft(Node<T>* left);
};

template <class T>
Node<T>::Node() {
    this->value = 0;
    this->right = 0;
    this->left = 0;
    counter = 0;
}

template <class T>
Node<T>::Node(const T& value) {
    this->value = value;
    this->right = 0;
    this->left = 0;
    counter = 1;
}

template <class T>
Node<T>::Node(const T& value, int counter) {
    this->value = value;
    this->right = 0;
    this->left = 0;
    this->counter = counter;
}

template <class T>
Node<T>::Node(const T& value, Node<T>* rightNode, Node<T>* leftNode, int counter) {
    this->value = value;
    this->right = rightNode;
    this->left = leftNode;
    this->counter = counter;
}

template <class T>
Node<T>::~Node() {
    left = 0;
    right = 0;
}

template <class T>
T Node<T>::getValue() const{
    return value;
}

template <class T>
void Node<T>::setValue(const T& value) {
    this->value = value;
}

template <class T>
Node<T>* Node<T>::getRight() const{
    return right;
}

template <class T>
void Node<T>::setRight(Node<T>* right) {
    this->right = right;
}

template <class T>
Node<T>* Node<T>::getLeft() const{
    return left;
}

template <class T>
void Node<T>::setLeft(Node<T>* left) {
    this->left = left;
}

template <class T>
int Node<T>::getCounter() const {
    return counter;
}

template <class T>
void Node<T>::setCounter(int counter) {
    this->counter = counter;
}

#endif // NODE_H_INCLUDED
