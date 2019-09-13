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
    size_t size() const;
    bool isEmpty() const;
    T& front() const;
    T& back() const;
    Node<T>* getHead() const;
    Node<T>* getTail() const;
    void clear();
    void pushBack(const T value);
    void pushFront(const T value);
    void popBack();
    void popFront();
    void setSize(size_t newSize);

    List<T>& operator+=(const List<T>& list);
    List<T>& operator=(const List<T>& source);
    List<T>& operator=(List<T>&& source);

    template <class K>
    friend std::ostream& operator<<(std::ostream &stream, const List<K>& list);
    template <class K>
    friend std::istream& operator>>(std::istream &stream, List<K>& list);
    template <class K>
    friend const List<K> operator+(const List<K>& left, const List<K>& right);
    template <class K>
    friend bool operator==(const List<K>& left, const List<K>& right);
    template <class K>
    friend bool operator!=(const List<K>& left, const List<K>& right);
    template <class K>
    friend void swap(List<K>& firstList, List<K>& secondList);
};


template <class T>
List<T>::List() {
    this->head_ = nullptr;
    this->tail_ = nullptr;
    size_ = 0;
}

template <class T>
List<T>::List(const List<T>& source) {
    this->head_ = nullptr;
    this->tail_ = nullptr;
    size_ = 0;
    Node<T>* current = source.getHead();
    while (current) {
        this->pushBack(current->getValue());
        current = current->getNext();
    }
    size_ = source.size();
}

template <class T>
List<T>::List(std::initializer_list<T> args) {
    this->head_ = nullptr;
    this->tail_ = nullptr;
    size_ = 0;
    typename std::initializer_list<T>::iterator it = args.begin();
    while(it != args.end()){
        this->pushBack(*it);
        it++;
    }
}

template <class T>
List<T>::List(List<T>&& source) {
    this->head_ = nullptr;
    this->tail_ = nullptr;
    size_ = 0;
    Node<T>* current = source.getHead();
    while (current) {
        this->pushBack(current->getValue());
        current = current->getNext();
    }
    size_ = source.size();
    source.clear();
}

template <class T>
List<T>::~List() {
    Node<T>* temp = head_;
    while(head_) {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
    }
    size_ = 0;
}

template <class T>
size_t List<T>::size() const {
    return size_;
}

template <class T>
bool List<T>::isEmpty() const {
    return size_ == 0;
}

template <class T>
T& List<T>::front() const {
    return head_->getValue();
}

template <class T>
T& List<T>::back() const {
    return tail_->getValue();
}

template <class T>
Node<T>* List<T>::getHead() const {
    return head_;
}

template <class T>
Node<T>* List<T>::getTail() const {
    return tail_;
}

template <class T>
void List<T>::clear() {
    Node<T>* temp = head_;
    while(head_) {
        temp = temp->getNext();
        delete head_;
        head_ = temp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template <class T>
void List<T>::pushBack(const T value) {
    Node<T>* newNode;
    if (size_ == 0) {
        newNode = new Node<T>(value, nullptr, nullptr);
        head_ = newNode;
        tail_ = newNode;
    } else {
        newNode = new Node<T>(value, tail_, nullptr);
        tail_->setNext(newNode);
        tail_ = newNode;
    }
    size_++;
}


template <class T>
void List<T>::pushFront(const T value) {
    Node<T>* newNode;
    if (size_ == 0) {
        newNode = new Node<T>(value, nullptr, nullptr);
        head_ = newNode;
        tail_ = newNode;
    } else {
        newNode = new Node<T>(value, nullptr, head_);
        head_->setPrev(newNode);
        head_ = newNode;
    }
    size_++;
}

template <class T>
void List<T>::popBack() {
    Node<T>* temp;
    if (size_ == 1) {
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        temp = tail_;
        tail_ = tail_->getPrev();
        tail_->setNext(nullptr);
        delete temp;
    }
    size_--;
}

template <class T>
void List<T>::popFront() {
    Node<T>* temp;
    if (size_ == 1) {
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
    } else {
        temp = head_;
        head_ = head_->getNext();
        head_->setPrev(nullptr);
        delete temp;
    }
    size_--;
}

template  <class T>
void List<T>::setSize(size_t newSize) {
    size_ = newSize;
}

template  <class T>
List<T>& List<T>::operator+=(const List<T>& list) {
    Node<T>* current = list.getHead();
    while (current) {
        this->pushBack(current->getValue());
        current = current->getNext();
    }
    return *this;
}

template  <class T>
List<T>& List<T>::operator=(const List<T>& source) {
    this->clear();
    Node<T>* current = source.getHead();
    while (current) {
        this->pushBack(current->getValue());
        current = current->getNext();
    }
    return *this;
}

template  <class T>
List<T>& List<T>::operator=(List<T>&& source) {
    this->clear();
    Node<T>* current = source.getHead();
    while (current) {
        this->pushBack(current->getValue());
        current = current->getNext();
    }
    source.clear();
    return *this;
}

template  <class T>
std::ostream& operator<<(std::ostream &stream, const List<T>& list) {
    Node<T>* current = list.head_;
    stream << "{ ";
    while(current) {
        stream << current->getValue() << " ";
        current = current->getNext();
    }
    stream << "}";
    return stream;
}

template  <class T>
std::istream& operator>>(std::istream &stream, List<T>& list) {
    //list.clear();
    std::string s;
    std::getline(stream, s);
    std::istringstream ss(s);
    T value;
    while(ss >> value){
        list.pushBack(value);
    }
    return stream;
}

template <class T>
const List<T> operator+(const List<T>& left, const List<T>& right) {
    List<T> result;
    Node<T>* current = left.getHead();
    while (current) {
        result.pushBack(current->getValue());
        current = current->getNext();
    }

    current = right.getHead();
    while (current) {
        result.pushBack(current->getValue());
        current = current->getNext();
    }
    return result;
}

template <class T>
bool operator==(const List<T> &left, const List<T> &right) {
    if (left.size_ != right.size_){
        return false;
    }

    Node<T>* tempLeft = left.head_;
    Node<T>* tempRight = right.head_;

    while(tempLeft) {
        if (tempLeft->getValue() != tempRight->getValue()){
            return false;
        }
        tempLeft = tempLeft->getNext();
        tempRight = tempRight->getNext();
    }
    return true;
}

template <class T>
bool operator!=(const List<T> &left, const List<T> &right) {
    if (left.size_ != right.size_){
        return true;
    }

    Node<T>* tempLeft = left.head_;
    Node<T>* tempRight = right.head_;

    while(tempLeft) {
        if (tempLeft->getValue() != tempRight->getValue()){
            return true;
        }
        tempLeft = tempLeft->getNext();
        tempRight = tempRight->getNext();
    }
    return false;
}

template <class T>
void swap(List<T> &firstList, List<T> &secondList) {
    Node<T>* temp;
    size_t tempSize;

    tempSize = firstList.size_;
    firstList.size_ = secondList.size_;
    secondList.size_ = tempSize;

    temp = firstList.head_;
    firstList.head_ = secondList.head_;
    secondList.head_ = temp;

    temp = firstList.tail_;
    firstList.tail_ = secondList.tail_;
    secondList.tail_ = temp;

}

#endif //LAB_LIST_H
