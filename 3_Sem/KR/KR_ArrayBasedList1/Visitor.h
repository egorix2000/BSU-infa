#ifndef LAB_VISITOR_H
#define LAB_VISITOR_H
#include "ComplexNumber.h"

class Visitor {
public:
    virtual void visit(ComplexNumber element) = 0;
    virtual ~Visitor() = default;
};

#endif //LAB_VISITOR_H
