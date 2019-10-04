#ifndef LAB_SUMVISITOR_H
#define LAB_SUMVISITOR_H

#include "Visitor.h"

class SumVisitor : public Visitor {
private:
	int sum_;
public:
    SumVisitor() : sum_(0) {};
	void visit(int element);
	int GetSum() const;
};

#endif //LAB_SUMVISITOR_H
