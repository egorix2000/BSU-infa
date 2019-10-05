#pragma once
#include <windows.h>
#include <sstream>
#include "Model.h"
#include "ComplexNumber.h"
#include "MaxVisitor.h"
#include "MinVisitor.h"

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
	ListIterator<ComplexNumber> it = model->iterator();
	stream << it;
	SetDlgItemText(hView_, ID_LIST_A_ELEMENTS, stream.str().c_str());

	//update number of elements
	stream.str("");
	stream.clear();
	stream << model->getSize();
	SetDlgItemText(hView_, ID_ELEM_NUM_TEXT, stream.str().c_str());

	//update max
	MaxVisitor vMax;
	model->accept(vMax);
	stream.str("");
	stream.clear();
	stream << vMax.GetMax();
	SetDlgItemText(hView_, ID_MAX_TEXT, stream.str().c_str());

	//update min
	MinVisitor vMin;
	model->accept(vMin);
	stream.str("");
	stream.clear();
	stream << vMin.GetMin();
	SetDlgItemText(hView_, ID_MIN_TEXT, stream.str().c_str());
}

template <class T>
void View<T>::set_view(const HWND& hView) { 
	hView_ = hView;
}

