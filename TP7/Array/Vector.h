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
        ~Vector();
        int getSize();
        void resize(int size);
        void setElement(int index, T& value);
        const T& operator[](const int index);
        const Vector* operator*=(const T& coefficient);
        const Vector* operator/=(const T& coefficient);
        const Vector* operator+=(Vector& vector);
        const Vector* operator-=(Vector& vector);
        void print();
};

template <class T>
Vector<T>::Vector(){
    delete [] array_;
    size_ = 0;
    array_ = new T[size_];
}

template <class T>
Vector<T>::Vector(const int size){
    delete [] array_;
    size_ = size;
    array_ = new T[size_];
}

template <class T>
Vector<T>::Vector(const int size, const T& element){
    delete [] array_;
    size_ = size;
    array_ = new T[size_];
    for (int i = 0; i < size_; i++){
        array_[i] = element;
    }
}

template <class T>
Vector<T>::~Vector(){
    delete [] array_;
}

template <class T>
int Vector<T>::getSize(){
    return size_;
}

template <class T>
void Vector<T>::resize(int size){
    delete [] array_;
    size_ = size;
    array_ = new T[size_];
}

template <class T>
void Vector<T>::setElement(int index, T& value){
    array_[index] = value;
}

template <class T>
const T& Vector<T>::operator[](int index){
    if (index < size_ && index >= 0){
        return array_[index];
    } else {
        throw "Error! Index is out of range!";
    }
}

template <class T>
const Vector<T>* Vector<T>::operator*=(const T& coefficient){
    for (int i = 0; i < size_; i++){
        array_[i] *= coefficient;
    }
    return this;
}

template <class T>
const Vector<T>* Vector<T>::operator/=(const T& coefficient){
    for (int i = 0; i < size_; i++){
        array_[i] /= coefficient;
    }
    return this;
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

template <class T>
void Vector<T>::print(){
    for (int i = 0; i < size_; i++){
        std::cout << array_[i] << " ";
    }
    std::cout << std::endl;
}

#endif // VECTOR_H_INCLUDED
