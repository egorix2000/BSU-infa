#pragma once
#ifndef EMPTYFILEEXCEPTION_H_INCLUDED
#define EMPTYFILEEXCEPTION_H_INCLUDED

#include <string>
#include "FileException.h"

class EmptyFileException : public FileException {
    public:
        std::string execute();
};

#endif // EMPTYFILEEXCEPTION_H_INCLUDED
