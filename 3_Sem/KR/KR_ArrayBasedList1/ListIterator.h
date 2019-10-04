#ifndef LAB_LISTITERATOR_H
#define LAB_LISTITERATOR_H

#include "List.h"

template <class T>
class List;

template <class U>
class ListIterator {
private:
    ListIterator() {}
    List<U>* list_;
    int index_;
public:
    ListIterator(List<U>* list);
    void next();
    bool hasNext();
    U& current();
};

template <class U>
ListIterator<U>::ListIterator(List<U>* list) {
    this->list_ = list;
    this->index_ = 0;
}

template <class U>
void ListIterator<U>::next() {
    index_++;
}

template <class U>
bool ListIterator<U>::hasNext() {
    return (index_ < list_->size_);
}

template <class U>
U& ListIterator<U>::current() {
    return list_->array_[index_];
}


#endif //LAB_LISTITERATOR_H
