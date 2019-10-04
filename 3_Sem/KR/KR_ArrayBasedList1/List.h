#ifndef LAB_LIST_H
#define LAB_LIST_H

#include <cstddef>
#include <ostream>
#include <string>
#include <sstream>

#include "Visitor.h"

const int DELTA_CAPACITY = 30;

template <class U>
class ListIterator;

template <class T>
class List {
private:
	size_t size_;
	size_t capacity_;
	T* array_;
	void resize();
public:
	List();
	List(const List<T>& source);
	~List();
	
	ListIterator<T> iterator();
	void accept(Visitor &v);
	void pushBack(const T value);
	void pushFront(const T value);
	void popBack();
	void popFront();

	template <class K>
	friend std::ostream& operator<<(std::ostream& stream, ListIterator<K>& iterator);

	template<class U> friend class ListIterator;
};


template <class T>
List<T>::List() {
	array_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

template <class T>
List<T>::List(const List<T>& source) : List() {
	size_ = source.size_;
	capacity_ = source.capacity_;
	if (capacity_ > 0) {
		array_ = new T[capacity_];

		for (int i = 0; i < source.size_; i++) {
			array_[i] = source[i];
		}
	}
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
ListIterator<T> List<T>::iterator() {
	ListIterator<T> it = ListIterator<T>(this);
	return it;
}

template <class T>
void List<T>::accept(Visitor &v) {
	ListIterator<T> iterator(this);

	while (iterator.hasNext()) {
		v.visit(iterator.current());
		iterator.next();
	}
}

template <class T>
void List<T>::pushBack(const T value) {
	if (size_+1 > capacity_) {
		capacity_ += DELTA_CAPACITY;
		this->resize();
	}
	array_[size_] = value;
	size_++;
}


template <class T>
void List<T>::pushFront(const T value) {
	if (size_+1 > capacity_) {
		capacity_ += DELTA_CAPACITY;
		this->resize();
	}
	for (int i = size_; i > 0; i--) {
		array_[i] = array_[i - 1];
	}
	array_[0] = value;
	size_++;
}

template <class T>
void List<T>::popBack() {
	if (size_ != 0) {
		size_--;
	}
}

template <class T>
void List<T>::popFront() {
	if (size_ != 0) {
		for (int i = 0; i < size_ - 1; i++) {
			array_[i] = array_[i + 1];
		}
		size_--;
	}
}

template  <class T>
void List<T>::resize() {
	int* oldArray = array_;
	if (capacity_ > 0) {
		array_ = new T[capacity_];
		for (int i = 0; i < size_; i++) {
			array_[i] = oldArray[i];
		}
	}
	else {
		array_ = nullptr;
	}
	if (oldArray != nullptr) {
		delete [] oldArray;
		oldArray = nullptr;
	}
}

template  <class T>
std::ostream& operator<<(std::ostream& stream, ListIterator<T>& iterator) {
	while(iterator.hasNext()) {
		stream << iterator.current()<< " ";
		iterator.next();
	}
	return stream;
}

#endif //LAB_LIST_H
