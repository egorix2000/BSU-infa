#ifndef LAB_LIST_H
#define LAB_LIST_H

#include <cstddef>
#include <ostream>
#include <string>
#include <sstream>
#include <initializer_list>
#include "Visitor.h"

const int DELTA_CAPACITY = 30;

class List {
private:
	size_t size_;
	size_t capacity_;
	int* array_;
public:

	class ListIterator {
	private:
		const List* list_;
		int index_;
	public:
		ListIterator(const List* list, const int index);
		ListIterator& operator++ ();
		ListIterator& operator-- ();
		int operator* ();
		friend bool operator==(const ListIterator& left, const ListIterator& right);
        friend bool operator!=(const ListIterator& left, const ListIterator& right);
	};
	friend class Visitor;

	List();
	List(const List& source);
	List(List&& source);
	List(std::initializer_list<int> args);
	~List();
	ListIterator begin() const;
	ListIterator end() const;
    void accept(Visitor &v);
	size_t size() const;
	int front() const;
	int back() const;
	int getElement(int index) const;
	size_t getCapacity() const;
	void clear();
	void pushBack(const int value);
	void pushFront(const int value);
	void popBack();
	void popFront();
	void setSize(size_t newSize);
	void setCapacity(size_t newCapacity);
	void setElement(int index, const int value);
	void resize();

	List& operator+=(const List& list);
	List& operator=(const List& source);
	List& operator=(List&& source);


	friend std::ostream& operator<<(std::ostream& stream, const List& list);
	friend std::istream& operator>>(std::istream& stream, List& list);
	friend const List operator+(const List& left, const List& right);
	friend bool operator==(const List& left, const List& right);
	friend bool operator!=(const List& left, const List& right);
	friend void swap(List& firstList, List& secondList);
};

#endif //LAB_LIST_H
