#ifndef LAB_VECTOROUTOFRANGEEXCEPTION_H
#define LAB_VECTOROUTOFRANGEEXCEPTION_H

#include <string>
#include "VectorException.h"

class VectorOutOfRangeException : public VectorException {
public:
    VectorOutOfRangeException(int min, int max, int actual) : min_(min), max_(max), actual_(actual) {}
    std::string execute();
private:
    int min_;
    int max_;
    int actual_;
};

#endif //LAB_VECTOROUTOFRANGEEXCEPTION_H
