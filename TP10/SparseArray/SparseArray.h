#ifndef LAB_SPARSEARRAY_H
#define LAB_SPARSEARRAY_H

#include <list>
#include "SA_item.h"

template <class T>
class SparseArray {
public:
    SparseArray(long length) : length_(length) {}
    T& operator [] (long index);
    void Show();
private:
    std::list< SA_item<T> > arr;
    long length_;
};

template <class T>
void SparseArray<T>::Show() {
    typename std::list< SA_item<T> >::iterator i = arr.begin();
    typename std::list< SA_item<T> >::iterator n = arr.end();

    for (i; i != n; i++) {
        std::cout << i->index << "\t" << i->info << std::endl;
    }
}

template <class T>
T& SparseArray<T>::operator [] (long index) {
    if ((index < 0) || (index > length_ - 1)) {
        std::cout << "Error of index: " << index << std::endl;
        SA_item<T> temp;
        return temp.info;
    }

    typename std::list< SA_item<T> >::iterator i = arr.begin();
    typename std::list< SA_item<T> >::iterator n = arr.end();

    for (i; i != n; i++) {
        if (index == i->index) {
            return i->info;
        }
    }

    arr.push_back(SA_item<T>(index, T()));
    i = arr.end();
    return (--i)->info;
}

#endif //LAB_SPARSEARRAY_H
