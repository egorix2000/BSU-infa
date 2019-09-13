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
    T& operator* () const;
};


#endif //LAB_LISTITERATOR_H
