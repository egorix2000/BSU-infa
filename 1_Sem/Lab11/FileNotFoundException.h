#pragma once
#ifndef FILENOTFOUNDEXCEPTION_H_INCLUDED
#define FILENOTFOUNDEXCEPTION_H_INCLUDED

#include <string>
#include "FileException.h"

class FileNotFoundException : public FileException{
    public:
        std::string execute();
};

#endif // FILENOTFOUNDEXCEPTION_H_INCLUDED
