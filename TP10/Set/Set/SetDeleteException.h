#ifndef LAB_SETDELETEEXCEPTION_H
#define LAB_SETDELETEEXCEPTION_H

#include <string>
#include "SetException.h"

class SetDeleteException : public SetException {
public:
    std::string execute();
};


#endif //LAB_SETDELETEEXCEPTION_H
