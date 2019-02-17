#ifndef LAB_SINGLYLINKEDLISTITERATOR_H
#define LAB_SINGLYLINKEDLISTITERATOR_H

#include "Node.h"
#include "SinglyLinkedListIncrementException.h"

template <class T>
class SinglyLinkedListIterator {
private:
    Node<T>* current_;
public:
    SinglyLinkedListIterator();
    explicit SinglyLinkedListIterator(const Node<T>& current);
    SinglyLinkedListIterator(const SinglyLinkedListIterator& sourse);
    Node<T>* getCurrent() const;
    void setCurrent(const Node<T>& current);
    SinglyLinkedListIterator& operator++();

    SinglyLinkedListIterator& operator =(const SinglyLinkedListIterator& sourse);
    friend bool operator==(const SinglyLinkedListIterator& left, const SinglyLinkedListIterator& right) {
        return left.current_ == right.current_;
    }
    friend bool operator!=(const SinglyLinkedListIterator& left, const SinglyLinkedListIterator& right) {
        return left.current_ != right.current_;
    }
    T& operator * ();
};

template <class T>
SinglyLinkedListIterator<T>::SinglyLinkedListIterator() {
    current_ = 0;
};

template <class T>
SinglyLinkedListIterator<T>::SinglyLinkedListIterator(const SinglyLinkedListIterator& sourse) {
    current_ = sourse.getCurrent();
}

template <class T>
SinglyLinkedListIterator<T>::SinglyLinkedListIterator(const Node<T>& current) {
    current_ = const_cast< Node<T>* >(&current);
}

template <class T>
Node<T>* SinglyLinkedListIterator<T>::getCurrent() const {
    return current_;
}

template <class T>
void SinglyLinkedListIterator<T>::setCurrent(const Node<T>& current) {
    current_ = const_cast< Node<T>* >(&current);
}

template <class T>
SinglyLinkedListIterator<T>& SinglyLinkedListIterator<T>::operator++() {
    if (current_ == 0) {
        throw SinglyLinkedListIncrementException();
    } else {
        current_ = current_->next;
    }
    return *this;
}

template <class T>
SinglyLinkedListIterator<T>& SinglyLinkedListIterator<T>::operator =(const SinglyLinkedListIterator<T>& sourse) {
    current_ = sourse.current_;
    return *this;
}

template <class T>
T& SinglyLinkedListIterator<T>::operator * () {
    return current_->value;
}

#endif //LAB_SINGLYLINKEDLISTITERATOR_H
