#ifndef LAB_VECTOREX_H
#define LAB_VECTOREX_H

#include "../Vector/Vector.h"

template <class T>
class Vectorex : public Vector<T> {
public:
    Vectorex() : Vector<T>() {}
    Vectorex(const int size) : Vector<T>(size) {}
    Vectorex(const Vector<T>& source) : Vector<T>(source) {}
    void push_front(const T& element);
};

template <class T>
void Vectorex<T>::push_front(const T& element) {
    Vector<T>::addElement(0, element);
}

#endif //LAB_VECTOREX_H
