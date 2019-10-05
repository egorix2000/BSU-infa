#include "MinVisitor.h"

MinVisitor::MinVisitor() {
	min_ = ComplexNumber();
	isMinSet_ = false;
}

void MinVisitor::visit(ComplexNumber element) {
	if (min_.getRe() > element.getRe() || !isMinSet_) {
		min_.setRe(element.getRe());
		min_.setIm(element.getIm());
		isMinSet_ = true;
	}
}

ComplexNumber MinVisitor::GetMin() const {
	return min_;
}
