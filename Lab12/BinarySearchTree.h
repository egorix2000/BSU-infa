#pragma once
#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include <iostream>
#include "Node.h"
#include "NodeNotFoundException.h"

template <class T>
class BinarySearchTree {
    private:
        Node<T>* root;
    public:
        BinarySearchTree();
        BinarySearchTree(const T& rootValue);
        ~BinarySearchTree();
        Node<T>* getRoot();
        void setRoot(Node<T>* root);
        Node<T>* findMin(Node<T>* node);
        Node<T>* insert(const T& value, Node<T>* node);
        Node<T>* remove(const T& value, Node<T>* node);
        Node<T> search(const T& value, Node<T>* node) const;
        void reset(Node<T>* node);
        void clear(Node<T>* node);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
    root = 0;
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootValue) {
    Node<T>* root = new Node<T>(rootValue);
    this->root = root;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    if (root != 0) {
        delete root;
    }
    root = 0;
}

template <class T>
Node<T>* BinarySearchTree<T>::getRoot() {
    return root;
}

template <class T>
void BinarySearchTree<T>::setRoot(Node<T>* root) {
    this->root = root;
}

template <class T>
Node<T>* BinarySearchTree<T>::findMin(Node<T>* node) {
    if (node->getLeft() == 0) {
        return node;
    }
    return findMin(node->getLeft());
}

template <class T>
Node<T>* BinarySearchTree<T>::insert(const T& value, Node<T>* node) {
    if (root == 0) {
        root = new Node<T>(value);
        return root;
    }
    if (node == 0) {
        Node<T>* newNode = new Node<T>(value);
        return newNode;
    }
    else if (value < node->getValue()) {
        node->setLeft(insert(value, node->getLeft()));
    } else if (value > node->getValue()) {
        node->setRight(insert(value, node->getRight()));
    } else {
        node->setCounter(node->getCounter()+1);
    }
    return node;
}

template <class T>
Node<T>* BinarySearchTree<T>::remove(const T& value, Node<T>* node) {
    if (node == 0) {
        throw NodeNotFoundException();
    } else if (value < node->getValue()) {
        node->setLeft(remove(value, node->getLeft()));
    } else if (value > node->getValue()) {
        node->setRight(remove(value, node->getRight()));
    } else {
        if (node->getLeft() != 0 && node->getRight() != 0) {
            node->setValue(findMin(node->getRight())->getValue());
            node->setRight(remove(node->getValue(), node->getRight()));
        } else if (node->getLeft() != 0) {
            Node<T>* temp = node;
            node = node->getLeft();
            delete temp;
        } else {
            Node<T>* temp = node;
            node = node->getRight();
            delete temp;
        }
    }
    return node;
}

template <class T>
Node<T> BinarySearchTree<T>::search(const T& value, Node<T>* node) const {
    if (node == 0) {
        throw NodeNotFoundException();
    } else if (value == node->getValue()) {
        return Node<T> (node->getValue(), node->getCounter());
    } else if (value < node->getValue()) {
        return search(value, node->getLeft());
    } else {
        return search(value, node->getRight());
    }
}

template <class T>
void BinarySearchTree<T>::reset(Node<T>* node) {
    clear(node);
    root = 0;
}

template <class T>
void BinarySearchTree<T>::clear(Node<T>* node) {
    if (node != 0) {
        if (node->getLeft() != 0) {
            clear(node->getLeft());
        }
        if (node->getRight() != 0) {
            clear(node->getRight());
        }
        delete node;
        node = 0;
    }
}

#endif // BINARYSEARCHTREE_H_INCLUDED
