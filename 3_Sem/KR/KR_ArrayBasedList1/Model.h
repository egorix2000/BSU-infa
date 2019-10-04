#pragma once

#include "List.h"

template <class T>
class View;

template <class T>
class Model : public List<T>
{
private:
	View<T>* view_;
	void informView();
public:
	void set_view(View<T>* view);
	void pushBack(const T value);
	void pushFront(const T value);
	void popBack();
	void popFront();
};

template <class T>
void Model<T>::informView() {
	view_->update_view(this);
}

template <class T>
void Model<T>::set_view(View<T>* view)
{
	view_ = view;
}

template <class T>
void Model<T>::pushBack(const T value) {
	List<T>::pushBack(value);
	informView();
}

template <class T>
void Model<T>::pushFront(const T value) {
	List<T>::pushFront(value);
	informView();
}

template <class T>
void Model<T>::popBack() {
	List<T>::popBack();
	informView();
}

template <class T>
void Model<T>::popFront() {
	List<T>::popFront();
	informView();
}