#pragma once
#ifndef EXPRESSIONEXCEPTION_H_INCLUDED
#define EXPRESSIONEXCEPTION_H_INCLUDED

#include <string>
#include "Exception.h"

class ExpressionException : public Exception {
    public:
        virtual std::string execute();
};

#endif // EXPRESSIONEXCEPTION_H_INCLUDED
