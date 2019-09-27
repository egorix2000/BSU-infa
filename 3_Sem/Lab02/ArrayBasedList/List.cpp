#include "List.h"

List::List() {
	array_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

List::List(const List& source) : List() {
	size_ = source.size();
	capacity_ = source.getCapacity();
	if (capacity_ > 0) {
		array_ = new int[capacity_];

		for (int i = 0; i < source.size(); i++) {
			array_[i] = source.getElement(i);
		}
	}
}

List::List(std::initializer_list<int> args) : List() {
	typename std::initializer_list<int>::iterator it = args.begin();
	while (it != args.end()) {
		this->pushBack(*it);
		it++;
	}
}

List::List(List&& source) : List() {
	swap(*this, source);
}

List::~List() {
	this->clear();
}

List::ListIterator List::begin() const {
    return List::ListIterator(this, 0);
}

List::ListIterator List::end() const {
    return List::ListIterator(this, size_);
}

void List::accept(Visitor &v) {
    v.visit(*this);
}

size_t List::size() const {
	return size_;
}

size_t List::getCapacity() const {
	return capacity_;
}

int List::front() const {
	if (size_ > 0) {
		return array_[0];
	}
	return 0;
}

int List::back() const {
	if (size_ > 0) {
		return array_[size_ - 1];
	}
	return 0;
}

int List::getElement(int index) const {
	return array_[index];
}

void List::clear() {
	if (array_ != nullptr) {
		delete [] array_;
	}
	array_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}

void List::pushBack(const int value) {
	if (size_+2 > capacity_) {
		capacity_ += DELTA_CAPACITY;
		this->resize();
	}
	array_[size_] = value;
	size_++;
}


void List::pushFront(const int value) {
	if (size_+2 > capacity_) {
		capacity_ += DELTA_CAPACITY;
		this->resize();
	}
	for (int i = size_; i > 0; i--) {
		array_[i] = array_[i - 1];
	}
	array_[0] = value;
	size_++;
}

void List::popBack() {
	if (size_ != 0) {
		size_--;
	}
}

void List::popFront() {
	if (size_ != 0) {
		for (int i = 0; i < size_ - 1; i++) {
			array_[i] = array_[i + 1];
		}
		size_--;
	}
}

void List::setSize(size_t newSize) {
	size_ = newSize;
}

void List::setCapacity(size_t newCapacity) {
	capacity_ = newCapacity;
}

void List::setElement(int index, const int value) {
	array_[index] = value;
}

void List::resize() {
	int* oldArray = array_;
	if (capacity_ > 0) {
		array_ = new int[capacity_];
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

List& List::operator+=(const List& list) {
	for (int i = 0; i < list.size(); i++) {
		this->pushBack(list.getElement(i));
	}
	return *this;
}

List& List::operator=(const List& source) {
	if (this == &source) {
		return *this;
	}
	this->clear();
	size_ = source.size();
	capacity_ = source.getCapacity();
	if (capacity_ > 0) {
		array_ = new int[capacity_];

		for (int i = 0; i < source.size(); i++) {
			array_[i] = source.getElement(i);
		}
	}
	else {
		array_ = nullptr;
	}
	return *this;
}

List& List::operator=(List&& source) {
	if (this == &source) {
		return *this;
	}
	this->clear();
	swap(*this, source);
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const List& list) {
	for (List::ListIterator it = list.begin(); it != list.end(); ++it) {
		stream << *it << " ";
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, List& list) {
	list.clear();
	std::string s;
	std::getline(stream, s);
	std::istringstream ss(s);
	int value;
	while (ss >> value) {
		list.pushBack(value);
	}
	return stream;
}

const List operator+(const List& left, const List& right) {
	List result;
	if (left.getCapacity() + right.getCapacity() > 0) {
		for (int i = 0; i < left.size(); i++) {
			result.pushBack(left.getElement(i));
		}

		for (int i = 0; i < right.size(); i++) {
			result.pushBack(right.getElement(i));
		}
	}
	else {
		result.array_ = nullptr;
	}

	return result;
}

bool operator==(const List& left, const List& right) {
	if (left.size_ != right.size_) {
		return false;
	}

	for (int i = 0; i < left.size(); i++) {
		if (left.getElement(i) != right.getElement(i)) {
			return false;
		}
	}
	return true;
}

bool operator!=(const List& left, const List& right) {
	if (left.size_ != right.size_) {
		return true;
	}

	for (int i = 0; i < left.size(); i++) {
		if (left.getElement(i) != right.getElement(i)) {
			return true;
		}
	}
	return false;
}

void swap(List& firstList, List& secondList) {
	size_t temp;
	int* tempArray;

	temp = firstList.size_;
	firstList.size_ = secondList.size_;
	secondList.size_ = temp;

	temp = firstList.capacity_;
	firstList.capacity_ = secondList.capacity_;
	secondList.capacity_ = temp;

	tempArray = firstList.array_;
	firstList.array_ = secondList.array_;
	secondList.array_ = tempArray;

}


List::ListIterator::ListIterator(const List* list, const int index) {
    list_ = list;
    index_ = index;
}

List::ListIterator& List::ListIterator::operator++() {
    index_++;
    return *this;
}

List::ListIterator& List::ListIterator::operator--() {
    index_--;
    return *this;
}

int List::ListIterator::operator*() {
    return list_->getElement(index_);
}

bool operator==(const List::ListIterator& left, const List::ListIterator& right) {
    return (left.index_ == right.index_) && (left.list_ == right.list_);
}

bool operator!=(const List::ListIterator& left, const List::ListIterator& right) {
	return (left.index_ != right.index_) || (left.list_ != right.list_);
}
