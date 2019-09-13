#ifndef LAB_LIST_H
#define LAB_LIST_H

#include <cstddef>
#include <ostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "Node.h"

template <class T>
class List {
private:
    size_t size_;
    Node<T> *head_;
    Node<T> *tail_;
public:
    List();
    List(const List<T>& source);
    List(List<T>&& source);
    List(std::initializer_list<T> args);
    ~List();
    size_t size();
    bool isEmpty();
    const Node<T>* front();
    const Node<T>* back();
    void clear();
    void pushBack(const T value);
    void pushFront(const T value);
    void popBack();
    void popFront();
    const size_t getSize();
    void setSize(size_t newSize);

    List<T>& operator+=(const List<T>& list);
    List<T>& operator=(const List<T>& source);
    List<T>& operator=(List<T>&& source);

    friend std::ostream& operator<<(std::ostream &stream, const List<T>& list);
    friend std::istream& operator>>(std::istream &stream, List<T>& list);
    friend const List<T>& operator+(const List<T>& left, const List<T>& right);
    friend bool operator==(const List<T>& left, const List<T>& right);
    friend bool operator!=(const List<T>& left, const List<T>& right);
    friend void swap(List<T>& firstList, List<T>& secondList);
};


#endif //LAB_LIST_H
