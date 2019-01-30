#pragma once
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include "VectorOutOfRangeException.h"
#include "VectorPopException.h"

template <class T>
class Vector {
    private:
        T* array_;
        int size_;
    public:
        Vector();
        Vector(const int size);
        Vector(const Vector& source);
        ~Vector();
        int getSize() const;
        void resize(int size);
        void reset();
        void push_back(const T& element);
        void setElement(int index, T& value);
        void addElement(int index, const T& value);
        void deleteElement(int index);
        void pop();
        T& operator[](int index) const;
        void show() const;
};

template <class T>
Vector<T>::Vector() {
    size_ = 0;
    array_ = 0;
}

template <class T>
Vector<T>::Vector(const int size) {
    size_ = size;
    array_ = new T[size_];
}

template <class T>
Vector<T>::Vector(const Vector& source) {
    size_ = source.getSize();
    array_ = new T[size_];
    for (int i = 0; i < size_; i++) {
        array_[i] = source[i];
    }
}

template <class T>
Vector<T>::~Vector() {
    if (array_ != 0) {
        delete [] array_;
    }
}

template <class T>
int Vector<T>::getSize() const {
    return size_;
}

template <class T>
void Vector<T>::reset() {
    if (array_ != 0) {
        delete [] array_;
    }
    array_ = 0;
    size_ = 0;
}

template <class T>
void Vector<T>::resize(int size) {
    int minSize;
    T* newArray = new T[size];
    minSize = size;
    if (size_ < size) {
        minSize = size_;
    }

    for (int i = 0; i < minSize; i++) {
        newArray[i] = array_[i];
    }

    if (array_ != 0) {
        delete [] array_;
        array_ = 0;
    }

    array_ = newArray;
    size_ = size;
}

template <class T>
void Vector<T>::push_back(const T& element) {
    int newSize = size_+1;
    resize(newSize);
    array_[size_-1] = element;
}

template <class T>
void Vector<T>::setElement(int index, T& value) {
    array_[index] = value;
}

template <class T>
void Vector<T>::addElement(int index, const T& value) {
    int newSize = size_+1;
    resize(newSize);
    for (int i = size_-1; i > index; i--) {
        array_[i] = array_[i-1];
    }

    array_[index] = value;
}

template <class T>
void Vector<T>::pop() {
    if (size_ == 0) {
        throw VectorPopException();
    }
    int newSize = size_-1;
    resize(newSize);
}

template <class T>
void Vector<T>::deleteElement(int index) {
    if (index < size_ && index >= 0){
        int newSize = size_ - 1;
        for (int i = index; i < size_-1; i++) {
            array_[i] = array_[i+1];
        }
        resize(newSize);
    } else {
        throw VectorOutOfRangeException(0, size_, index);
    }
}

template <class T>
T& Vector<T>::operator[](int index) const {
    if (index < size_ && index >= 0){
        return array_[index];
    } else {
        throw VectorOutOfRangeException(0, size_, index);
    }
}

template <class T>
void Vector<T>::show() const {
    for (int i = 0; i < size_; i++) {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

#endif // VECTOR_H_INCLUDED
