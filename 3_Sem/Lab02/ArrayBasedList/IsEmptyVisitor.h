#ifndef LAB_ISEMPTYVISITOR_H
#define LAB_ISEMPTYVISITOR_H

#include "Visitor.h"
#include "List.h"

class IsEmptyVisitor : public Visitor{
public:
    bool value;
public:
    void visit(List &ref) override;
};


#endif //LAB_ISEMPTYVISITOR_H
