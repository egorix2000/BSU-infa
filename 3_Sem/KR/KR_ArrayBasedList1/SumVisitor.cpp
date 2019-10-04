#include "SumVisitor.h"

void SumVisitor::visit(int element) {
    sum_ += element;
}

int SumVisitor::GetSum() const {
    return sum_;
}
