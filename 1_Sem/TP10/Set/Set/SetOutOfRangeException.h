#ifndef LAB_SETOUTOFRANGEEXCEPTION_H
#define LAB_SETOUTOFRANGEEXCEPTION_H


#include <string>
#include "SetException.h"

class SetOutOfRangeException : public SetException {
public:
    SetOutOfRangeException(int min, int max, int actual) : min_(min), max_(max), actual_(actual) {}
    std::string execute();
private:
    int min_;
    int max_;
    int actual_;
};


#endif //LAB_SETOUTOFRANGEEXCEPTION_H
