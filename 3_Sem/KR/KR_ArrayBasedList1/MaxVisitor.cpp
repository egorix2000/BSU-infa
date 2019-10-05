#include "MaxVisitor.h"

MaxVisitor::MaxVisitor() {
	max_ = ComplexNumber();
	isMaxSet_ = false;
}

void MaxVisitor::visit(ComplexNumber element) {
	if (max_.getIm() < element.getIm() || !isMaxSet_) {
		max_.setRe(element.getRe());
		max_.setIm(element.getIm());
		isMaxSet_ = true;
	}
}

ComplexNumber MaxVisitor::GetMax() const {
    return max_;
}
