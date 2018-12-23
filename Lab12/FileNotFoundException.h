#pragma once
#ifndef FILENOTFOUNDEXCEPTION_H_INCLUDED
#define FILENOTFOUNDEXCEPTION_H_INCLUDED

#include <string>
#include "FileException.h"

class FileNotFoundException : public FileException{
    public:
        FileNotFoundException(std::string file);
        std::string execute();
    private:
        std::string file_;
};

#endif // FILENOTFOUNDEXCEPTION_H_INCLUDED
