#ifndef LAB_VECTORITERATOR_H
#define LAB_VECTORITERATOR_H

#include "Vector.h"

template <class T>
class VectorIterator {
private:
    int currentPosition_;
    Vector<T>* vector_;
    bool isEnd_;
public:
    VectorIterator(const Vector<T>& vector);
    int getCurrentPosition() const;
    void moveToBegin();
    void moveToEnd();
    VectorIterator& operator++ ();
    VectorIterator& operator-- ();
    T& operator* () const;
    bool operator== (const VectorIterator<T>& iterator) const;
    bool operator!= (const VectorIterator<T>& iterator) const;
    operator bool() const;
};

template <class T>
VectorIterator<T>::VectorIterator(const Vector<T>& vector) {
    currentPosition_ = 0;
    vector_ = const_cast<Vector<char>*>(&vector);
    if (vector.getSize() != 0) {
        isEnd_ = true;
    } else {
        isEnd_ = false;
    }
}

template <class T>
int VectorIterator<T>::getCurrentPosition() const {
    return currentPosition_;
}

template <class T>
void VectorIterator<T>::moveToBegin(){
    currentPosition_ = -1;
}

template <class T>
void VectorIterator<T>::moveToEnd(){
    currentPosition_ = vector_->getSize();
}

template <class T>
VectorIterator<T>& VectorIterator<T>::operator++ () {
    currentPosition_++;
    if (currentPosition_ >= 0 && currentPosition_ < vector_->getSize()) {
        isEnd_ = false;
    } else {
        isEnd_ = true;
    }
    return *this;
}

template <class T>
VectorIterator<T>& VectorIterator<T>::operator-- () {
    currentPosition_--;
    if (currentPosition_ >= 0 && currentPosition_ < vector_->getSize()) {
        isEnd_ = false;
    } else {
        isEnd_ = true;
    }
    return *this;
}

template <class T>
T& VectorIterator<T>::operator* () const {
    return (*vector_)[currentPosition_];
}

template <class T>
bool VectorIterator<T>::operator== (const VectorIterator<T>& iterator) const {
    return currentPosition_ - iterator.getCurrentPosition() == 0 ? true : false;
}

template <class T>
bool VectorIterator<T>::operator!= (const VectorIterator<T>& iterator) const {
    return currentPosition_ - iterator.getCurrentPosition() == 0 ? false : true;
}

template <class T>
VectorIterator<T>::operator bool() const {
    return isEnd_;
}

#endif //LAB_VECTORITERATOR_H
