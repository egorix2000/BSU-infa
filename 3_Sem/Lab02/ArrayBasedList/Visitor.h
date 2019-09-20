#ifndef LAB_VISITOR_H
#define LAB_VISITOR_H

class List;

class Visitor
{
public:
    virtual void visit(List &ref) = 0;
};

#endif //LAB_VISITOR_H
