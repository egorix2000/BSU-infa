#ifndef LAB_ARRAY_H
#define LAB_ARRAY_H

#include "../SinglyLinkedList/SinglyLinkedList.h"
#include "../SinglyLinkedList/SinglyLinkedListIterator.h"

template <class T>
class Array : public SinglyLinkedList<T> {
public:
    Array() : SinglyLinkedList<T>() {}
    Array(const T& firstElementValue) : SinglyLinkedList<T>(firstElementValue) {}
    T& operator [](int index) const;
};

template <class T>
T& Array<T>::operator [](int index) const {
    SinglyLinkedListIterator<T> iterator (*SinglyLinkedList<T>::head_);
    for (int i = 0; i < index; i++) {
        ++iterator;
    }
    return *iterator;
}

#endif //LAB_ARRAY_H
