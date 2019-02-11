#ifndef LAB_SET_H
#define LAB_SET_H

#include <cmath>
#include "../Vector/Vector.h"
#include "SetDeleteException.h"
#include "SetOutOfRangeException.h"

template <class T>
class Set {
public:
    Set();
    ~Set();
    int getSize() const;
    void reset();
    void addElement(const T& value);
    void deleteElement(const T& value);
    int find(const T& value);
    T& operator[](int index) const;
    void show() const;
private:
    Vector<T>* vector_;
};

template <class T>
Set<T>::Set() {
    vector_ = new Vector<T>();
}

template <class T>
Set<T>::~Set() {
    delete vector_;
}

template <class T>
int Set<T>::getSize() const {
    return vector_->getSize();
}

template <class T>
void Set<T>::reset() {
    vector_->reset();
}

template <class T>
void Set<T>::addElement(const T& value) {
    if (vector_->getSize() == 0) {
        vector_->push_back(value);
    } else {
        int index = find(value);

        if (index == -1) {
            double left = 0;
            double right = vector_->getSize()-1;
            double middle;
            while (left < right) {
                middle = ceil((right - left) / 2.0) + left;
                if (value > vector_->operator[](middle)) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
            if (left > right) {
                left = right;
            }
            if (value > vector_->operator[](left)) {
                vector_->addElement(left + 1, value);
            } else {
                vector_->addElement(left, value);
            }
        }
    }
}

template <class T>
void Set<T>::deleteElement(const T& value) {
    int index = find(value);
    if (index == -1) {
        throw SetDeleteException();
    }
    vector_->deleteElement(index);
}

template <class T>
int Set<T>::find(const T& value) {
    double left = 0;
    double right = vector_->getSize()-1;
    double middle;
    while (left < right) {
        middle = ceil((right - left)/2.0) + left;
        if (value > vector_->operator[](middle)) {
            left = middle + 1;
        } else if (value < vector_->operator[](middle) ) {
            right = middle - 1;
        } else {
            return middle;
        }
    }
    if (left > right) {
        left = right;
    }
    if (value == vector_->operator[](left)) {
        return left;
    } else {
        return -1;
    }
}

template <class T>
T& Set<T>::operator[](int index) const {
    if (index < vector_->getSize() && index >= 0){
        return vector_->operator[](index);
    } else {
        throw SetOutOfRangeException(0, vector_->getSize(), index);
    }
}

template <class T>
void Set<T>::show() const {
    vector_->show();
}


#endif //LAB_SET_H
