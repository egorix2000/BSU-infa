#ifndef LAB_SINGLYLINKEDLIST_H
#define LAB_SINGLYLINKEDLIST_H

#include "Node.h"
#include "SinglyLinkedListIterator.h"
#include "SinglyLinkedListEmptyException.h"

template <class T>
class SinglyLinkedList{
protected:
    Node<T>* head_;
    int size_;
public:
    SinglyLinkedList();
    explicit SinglyLinkedList(const T& firstElementValue);
    ~SinglyLinkedList();
    T& getHead() const;
    SinglyLinkedListIterator<T> begin() const;
    SinglyLinkedListIterator<T> end() const;
    bool isEmpty() const;
    int getSize() const;
    SinglyLinkedListIterator<T>& insert(SinglyLinkedListIterator<T>& iterator, const T& value);
    SinglyLinkedListIterator<T>& erase(SinglyLinkedListIterator<T>& iterator);
    void push_front(const T& value);
    void pop_front();
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head_ = 0;
    size_ = 0;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(const T& firstElementValue) {
    Node<T> *newFirstElement = new Node<T>(firstElementValue, 0);
    head_ = newFirstElement;
    size_ = 1;
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* current = head_;
    Node<T>* temp;
    while (current != 0) {
        temp = current;
        current = current->next;
        delete temp;
    }
}

template <class T>
T& SinglyLinkedList<T>::getHead() const {
    if (head_) {
        return head_->value;
    } else {
        throw SinglyLinkedListEmptyException();
    }
}

template <class T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::begin() const {
    return SinglyLinkedListIterator<T>(*head_);
}

template <class T>
SinglyLinkedListIterator<T> SinglyLinkedList<T>::end() const {
    return SinglyLinkedListIterator<T>();
}

template <class T>
int SinglyLinkedList<T>::getSize() const {
    return size_;
}

template <class T>
SinglyLinkedListIterator<T>& SinglyLinkedList<T>::insert(SinglyLinkedListIterator<T>& iterator, const T& value) {
    Node<T> *temp;
    Node<T> *newNode;
    if (iterator.getCurrent()) {
        newNode = new Node<T>(value, 0);
        temp = iterator.getCurrent()->next;
        iterator.getCurrent()->next = newNode;
        newNode->next = temp;
        ++iterator;
        size_++;
        return iterator;
    } else {
        temp = head_;
        newNode = new Node<T>(value, 0);
        head_ = newNode;
        newNode->next = temp;
        size_++;
        iterator.setCurrent(*head_);
        return iterator;
    }
}

template <class T>
SinglyLinkedListIterator<T>& SinglyLinkedList<T>::erase(SinglyLinkedListIterator<T>& iterator) {
    size_--;
    Node<T>* temp;
    if (iterator.getCurrent() == head_) {
        if (head_->next) {
            temp = head_;
            head_ = head_->next;
            ++iterator;
            delete temp;
            return iterator;
        } else {
            delete head_;
            head_ = 0;
            iterator.setCurrent(*head_);
            return iterator;
        }
    } else {
        Node<T> *prev = head_;
        while (prev->next != iterator.getCurrent()) {
            prev = prev->next;
        }
        prev->next = iterator.getCurrent()->next;
        temp = iterator.getCurrent();
        ++iterator;
        delete temp;
        return iterator;
    }
}

template <class T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head_ == 0;
}

template <class T>
void SinglyLinkedList<T>::push_front(const T& value) {
    Node<T>* temp = head_;
    Node<T> *newHead = new Node<T>(value, 0);
    head_ = newHead;
    newHead->next = temp;
    size_++;
}

template <class T>
void SinglyLinkedList<T>::pop_front() {
    if(head_){
        Node<T>* temp = head_;
        head_ = head_->next;
        size_--;
        delete temp;
    } else {
        throw SinglyLinkedListEmptyException();
    }
}

#endif //LAB_SINGLYLINKEDLIST_H
