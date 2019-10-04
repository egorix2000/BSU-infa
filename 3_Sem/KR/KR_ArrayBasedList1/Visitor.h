#ifndef LAB_VISITOR_H
#define LAB_VISITOR_H

class Visitor{
public:
    virtual void visit(int element) = 0;
    virtual ~Visitor() = default;
};

#endif //LAB_VISITOR_H
