#pragma once
#ifndef FILEEXCEPTION_H_INCLUDED
#define FILEEXCEPTION_H_INCLUDED

#include <string>
#include "Exception.h"

class FileException : public Exception{
    public:
        virtual std::string execute();
};

#endif // FILEEXCEPTION_H_INCLUDED
