#ifndef LAB_SUMVISITOR_H
#define LAB_SUMVISITOR_H

#include "Visitor.h"
#include "ComplexNumber.h"

class MaxVisitor : public Visitor {
private:
	ComplexNumber max_;
	bool isMaxSet_;
public:
	MaxVisitor();
	void visit(ComplexNumber element);
	ComplexNumber GetMax() const;
};

#endif //LAB_SUMVISITOR_H
