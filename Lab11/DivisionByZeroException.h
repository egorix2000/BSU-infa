#pragma once
#ifndef DIVISIONBYZEROEXCEPTION_H_INCLUDED
#define DIVISIONBYZEROEXCEPTION_H_INCLUDED

#include <string>
#include "ExpressionException.h"

class DivisionByZeroException : public ExpressionException {
    public:
        std::string execute();
};

#endif // DIVISIONBYZEROEXCEPTION_H_INCLUDED
