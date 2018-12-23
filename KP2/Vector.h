#pragma once
#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

template <class T>
class Vector {
    private:
        T* array_;
        int size_;
    public:
        Vector();
        Vector(const int size);
        Vector(const int size, const T& element);
        Vector(const Vector& source);
        ~Vector();
        int getSize() const;
        void resize(int size);
        void reset();
        void push_back(const T& element);
        void setElement(int index, T& value);
        const T operator[](int index) const;
        const Vector* operator+=(Vector& vector);
        const Vector* operator-=(Vector& vector);
};

template <class T>
Vector<T>::Vector(){
    size_ = 0;
    array_ = 0;
}

template <class T>
Vector<T>::Vector(const int size){
    size_ = size;
    array_ = new T[size_];
    for (int i = 0; i < size_; i++) {
        array_ = 0;
    }
}

template <class T>
Vector<T>::Vector(const int size, const T& element){
    size_ = size;
    array_ = new T[size_];
    for (int i = 0; i < size_; i++){
        array_[i] = element;
    }
}

template <class T>
Vector<T>::Vector(const Vector& source){
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
int Vector<T>::getSize() const{
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
    int* newArray = new int[size];
    minSize = size;
    if (size_ < size) {
        minSize = size_;
    }
    for (int i = 0; i < minSize; i++) {
        newArray[i] = array_[i];
    }
    for (int i = minSize; i < size; i++) {
        newArray[size_] = 0;
    }
    if (array_ != 0) {
        delete [] array_;
    }
    array_ = newArray;
    size_ = size;
}

template <class T>
void Vector<T>::push_back(const T& element){
    int newSize = size_+1;
    resize(newSize);
    array_[size_-1] = element;
}

template <class T>
void Vector<T>::setElement(int index, T& value){
    array_[index] = value;
}

template <class T>
const T Vector<T>::operator[](int index) const{
    if (index < size_ && index >= 0){
        return array_[index];
    } else {
        throw "Error! Index is out of range!";
    }
}

template <class T>
const Vector<T>* Vector<T>::operator+=(Vector<T>& vector){
    if (size_ == vector.getSize()){
        for (int i = 0; i < size_; i++){
           array_[i] += vector[i];
        }
    } else {
        throw "Error! Sizes must be equal!";
    }
    return this;
}

template <class T>
const Vector<T>* Vector<T>::operator-=(Vector& vector){
    if (size_ == vector.getSize()){
        for (int i = 0; i < size_; i++){
            array_[i] -= vector[i];
        }
    } else {
        throw "Error! Sizes must be equal!";
    }
    return this;
}

#endif // VECTOR_H_INCLUDED
