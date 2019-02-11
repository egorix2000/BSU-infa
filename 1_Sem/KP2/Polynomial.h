#pragma once
#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "Vector.h"

template <class T>
class Polynomial {
    public:
        Polynomial();
        Polynomial(const int n);
        Polynomial(const Vector<T>& coefficients);
        Polynomial(const Polynomial& polynomial);
        ~Polynomial();
        int getDegree() const;
        Vector<T> getCoefficients() const;
        const Polynomial<T>* operator=(const Polynomial& polynomial);
        const Polynomial<T>* operator+=(const Polynomial& polynomial);
        const Polynomial<T>* operator-=(const Polynomial& polynomial);
        const T operator[] (int index);
        T getValue(const T key) const;
    private:
        int n_;
        Vector<T>* coefficients_;
};

template <class T>
Polynomial<T>::Polynomial(){
    n_ = 0;
    coefficients_ = new Vector<T>();
}

template <class T>
Polynomial<T>::Polynomial(const int n){
    n_ = n;
    coefficients_ = new Vector<T> (n);
}

template <class T>
Polynomial<T>::Polynomial(const Vector<T>& coefficients) {
    n_ = coefficients.getSize();
    coefficients_ = new Vector<T> (coefficients);
}

template <class T>
Polynomial<T>::Polynomial(const Polynomial<T>& polynomial) {
    n_ = polynomial.getDegree();
    coefficients_ = new Vector<T> (polynomial.getCoefficients());
}

template <class T>
Polynomial<T>::~Polynomial() {
    if (n_ != 0) {
        delete coefficients_;
    }
    n_ = 0;
}

template <class T>
int Polynomial<T>::getDegree() const {
    return n_;
}

template <class T>
Vector<T> Polynomial<T>::getCoefficients() const {
    return Vector<T> (*coefficients_);
}

template <class T>
const Polynomial<T>* Polynomial<T>::operator=(const Polynomial& polynomial) {
    n_ = polynomial.getDegree();
    coefficients_ = new Vector<T>(polynomial.getCoefficients());
    return this;
}

template <class T>
const Polynomial<T>* Polynomial<T>::operator+=(const Polynomial& polynomial) {
    Vector<T>* coefficientsAdd = new Vector<T> (polynomial.getCoefficients());
    if (n_ > polynomial.getDegree()) {
        coefficientsAdd->resize(n_);
        *coefficients_ += *coefficientsAdd;
    }
    else if (n_ < polynomial.getDegree()) {
        n_ = polynomial.getDegree();
        coefficients_->resize(n_);
        *coefficients_ += *coefficientsAdd;
    } else {
        *coefficients_ += *coefficientsAdd;
    }
    return this;
}

template <class T>
const Polynomial<T>* Polynomial<T>::operator-=(const Polynomial& polynomial) {
    Vector<T>* coefficientsAdd = new Vector<T> (polynomial.getCoefficients());
    if (n_ > polynomial.getDegree()){
        coefficientsAdd->resize(n_);
        *coefficients_ -= *coefficientsAdd;
    }
    else if (n_ < polynomial.getDegree()){
        n_ = polynomial.getDegree();
        coefficients_->resize(n_);
        *coefficients_ -= *coefficientsAdd;
    } else {
        *coefficients_ -= *coefficientsAdd;
    }
    return this;
}

template <class T>
const T Polynomial<T>::operator[](int index) {
    return (*coefficients_)[index];
}

template <class T>
T Polynomial<T>::getValue(const T key) const {
    T ans = 0;
    T poweredKey = 1;
    for (int i = 0; i < n_; i++) {
        ans += (coefficients_[i]*poweredKey);
        poweredKey *= key;
    }
    return ans;
}



#endif // POLYNOMIAL_H_INCLUDED
