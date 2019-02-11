#pragma once
#ifndef NODENOTFOUNDEXCEPTION_H_INCLUDED
#define NODENOTFOUNDEXCEPTION_H_INCLUDED

#include <string>
#include "Exception.h"

class NodeNotFoundException : public Exception{
    public:
        std::string execute();
};

#endif // NODENOTFOUNDEXCEPTION_H_INCLUDED
