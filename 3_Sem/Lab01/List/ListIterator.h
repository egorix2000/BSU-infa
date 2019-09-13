#ifndef LAB_LISTITERATOR_H
#define LAB_LISTITERATOR_H

#include "Node.h"

template <class T>
class ListIterator {
private:
    Node<T>* current_;
public:
    ListIterator(const Node<T>* current);
    ListIterator<T>& operator++ ();
    ListIterator<T>& operator-- ();
    T& operator* ();
};


template <class T>
ListIterator<T>::ListIterator(const Node<T> *current) {
    current_ = current;
}

template <class T>
ListIterator<T>& ListIterator<T>::operator++() {
    current_ = current_->getNext();
    return *this;
}

template <class T>
ListIterator<T>& ListIterator<T>::operator--() {
    current_ = current_->getPrev();
    return *this;
}

template <class T>
T& ListIterator<T>::operator*() {
    return current_->getValue();
}

#endif //LAB_LISTITERATOR_H
