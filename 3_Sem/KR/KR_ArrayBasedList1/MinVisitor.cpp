#include "MinVisitor.h"

MinVisitor::MinVisitor() {
	min_ = ComplexNumber(10000, 10000);
}

void MinVisitor::visit(ComplexNumber element) {
	if (min_.getRe() > element.getRe()) {
		min_.setRe(element.getRe());
		min_.setIm(element.getIm());
	}
}

ComplexNumber MinVisitor::GetMin() const {
	return min_;
}
