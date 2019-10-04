#pragma once
#include <windows.h>
#include <sstream>
#include "Model.h"

template <class T>
class View
{
	HWND hView_;
public:
	void update_view(Model<T>* model);
	void set_view(const HWND& hView);
};

template <class T>
void View<T>::update_view(Model<T>* model) {
	//update list
	std::ostringstream stream;
	ListIterator<int> it = model->iterator();
	stream << it;
	SetDlgItemText(hView_, ID_LIST_A_ELEMENTS, stream.str().c_str());

	//update sum
	SumVisitor v;
	model->accept(v);
	SetDlgItemText(hView_, ID_ELEM_SUM_TEXT, std::to_string(v.GetSum()).c_str());
}

template <class T>
void View<T>::set_view(const HWND& hView) { 
	hView_ = hView;
}

