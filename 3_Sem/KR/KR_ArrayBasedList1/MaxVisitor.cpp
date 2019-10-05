#include "MaxVisitor.h"

MaxVisitor::MaxVisitor() {
	max_ = ComplexNumber(0, 0);
}

void MaxVisitor::visit(ComplexNumber element) {
	if (max_.getIm() < element.getIm()) {
		max_.setRe(element.getRe());
		max_.setIm(element.getIm());
	}
}

ComplexNumber MaxVisitor::GetMax() const {
    return max_;
}
