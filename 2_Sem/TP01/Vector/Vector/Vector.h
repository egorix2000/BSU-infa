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
        int vectorSize_;
        int arraySize_;
    public:
        Vector();
        Vector(const int size);
        Vector(const Vector& source);
        ~Vector();
        int getSize() const;
        void resizeArray(int size);
        void reset();
        void push_back(const T& element);
        void setElement(int index, T& value);
        void addElement(int index, const T& value);
        void pop();
        T& operator[](int index) const;
        void show() const;
};

template <class T>
Vector<T>::Vector() {
    vectorSize_ = 0;
    array_ = 0;
    arraySize_ = 0;
}

template <class T>
Vector<T>::Vector(const int size) {
    vectorSize_ = size;
    array_ = new T[size];
    arraySize_ = size;
}

template <class T>
Vector<T>::Vector(const Vector& source) {
    vectorSize_ = source.getSize();
    array_ = new T[vectorSize_];
    for (int i = 0; i < vectorSize_; i++) {
        array_[i] = source[i];
    }
    arraySize_ = vectorSize_;
}

template <class T>
Vector<T>::~Vector() {
    if (array_ != 0) {
        delete [] array_;
    }
}

template <class T>
int Vector<T>::getSize() const {
    return vectorSize_;
}

template <class T>
void Vector<T>::reset() {
    if (array_ != 0) {
        delete [] array_;
    }
    array_ = 0;
    vectorSize_ = 0;
    arraySize_ = 0;
}

template <class T>
void Vector<T>::resizeArray(int arraySize) {
    int minSize;
    T* newArray = new T[arraySize];
    minSize = arraySize;
    if (arraySize_ < arraySize) {
        minSize = arraySize_;
    }

    for (int i = 0; i < minSize; i++) {
        newArray[i] = array_[i];
    }

    if (array_ != 0) {
        delete [] array_;
    }

    array_ = newArray;
    arraySize_ = arraySize;
}

template <class T>
void Vector<T>::push_back(const T& element) {
    vectorSize_++;
    if (vectorSize_ >= arraySize_) {
        resizeArray(arraySize_*2+1);
    }
    array_[vectorSize_-1] = element;
}

template <class T>
void Vector<T>::setElement(int index, T& value) {
    array_[index] = value;
}

template <class T>
void Vector<T>::addElement(int index, const T& value) {
    vectorSize_++;
    if (vectorSize_ >= arraySize_) {
        resizeArray(arraySize_*2+1);
    }
    for (int i = vectorSize_-1; i > index; i--) {
        array_[i] = array_[i-1];
    }

    array_[index] = value;
}

template <class T>
void Vector<T>::pop() {
    if (vectorSize_ == 0) {
        throw VectorPopException();
    }
    vectorSize_--;
}

template <class T>
T& Vector<T>::operator[](int index) const {
    if (index < vectorSize_ && index >= 0){
        return array_[index];
    } else {
        throw VectorOutOfRangeException(0, vectorSize_, index);
    }
}

template <class T>
void Vector<T>::show() const {
    for (int i = 0; i < vectorSize_; i++) {
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

#endif // VECTOR_H_INCLUDED
