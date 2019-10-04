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
	Node<T>* head_;
	Node<T>* tail_;
public:
	List();
	List(const List<T>& source);
	List(List<T>&& source);
	~List();
	size_t size() const;
	Node<T>* getHead() const;
	Node<T>* getTail() const;
	void pushBack(const T value);
	void pushFront(const T value);
	void popBack();
	void popFront();
	void setSize(size_t newSize);

	List<T>& operator=(const List<T>& source);
	List<T>& operator=(List<T>&& source);

	template <class K>
	friend std::ostream& operator<<(std::ostream& stream, const List<K>& list);
};


template <class T>
List<T>::List() {
	this->head_ = nullptr;
	this->tail_ = nullptr;
	size_ = 0;
}

template <class T>
List<T>::List(const List<T>& source) : List() {
	Node<T>* current = source.getHead();
	while (current) {
		this->pushBack(current->getValue());
		current = current->getNext();
	}
	size_ = source.size();
}

template <class T>
List<T>::List(List<T>&& source) : List() {
	swap(*this, source);
}

template <class T>
List<T>::~List() {
	if (array_ != nullptr) {
		delete[] array_;
	}
	array_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <class T>
size_t List<T>::size() const {
	return size_;
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
void List<T>::pushBack(const T value) {
	Node<T>* newNode;
	if (size_ == 0) {
		newNode = new Node<T>(value, nullptr, nullptr);
		head_ = newNode;
		tail_ = newNode;
	}
	else {
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
	}
	else {
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
		size_--;
	}
	else if (size_ != 0) {
		temp = tail_;
		tail_ = tail_->getPrev();
		tail_->setNext(nullptr);
		delete temp;
		size_--;
	}
}

template <class T>
void List<T>::popFront() {
	Node<T>* temp;
	if (size_ == 1) {
		delete head_;
		head_ = nullptr;
		tail_ = nullptr;
		size_--;
	}
	else if (size_ != 0) {
		temp = head_;
		head_ = head_->getNext();
		head_->setPrev(nullptr);
		delete temp;
		size_--;
	}
}

template  <class T>
void List<T>::setSize(size_t newSize) {
	size_ = newSize;
}

template  <class T>
List<T>& List<T>::operator=(const List<T>& source) {
	if (this == &source) {
		return *this;
	}
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
	if (this == &source) {
		return *this;
	}
	this->clear();
	swap(*this, source);
	return *this;
}

template  <class T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list) {
	Node<T>* current = list.head_;
	while (current) {
		stream << current->getValue() << " ";
		current = current->getNext();
	}
	return stream;
}

#endif //LAB_LIST_H

