#pragma once
#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <string>

class Exception{
    public:
        virtual std::string execute();
};

#endif // EXCEPTION_H_INCLUDED
