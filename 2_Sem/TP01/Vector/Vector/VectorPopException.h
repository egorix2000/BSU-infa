#ifndef LAB_VECTORPOPEXCEPTION_H
#define LAB_VECTORPOPEXCEPTION_H


#include <string>
#include "VectorException.h"

class VectorPopException : public VectorException{
public:
    std::string execute();
};

#endif //LAB_VECTORPOPEXCEPTION_H
