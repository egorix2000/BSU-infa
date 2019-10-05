#pragma once

#include "Visitor.h"
#include "ComplexNumber.h"

class MinVisitor : public Visitor {
private:
	ComplexNumber min_;
public:
	MinVisitor();
	void visit(ComplexNumber element);
	ComplexNumber GetMin() const;
};