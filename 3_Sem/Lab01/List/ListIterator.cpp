#include "ListIterator.h"

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
T& ListIterator<T>::operator*() const {
    return current_->getValue();
}