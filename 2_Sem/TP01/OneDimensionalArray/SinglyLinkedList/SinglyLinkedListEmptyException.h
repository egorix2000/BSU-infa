#ifndef LAB_SINGLYLINKEDLISTEMPTYEXCEPTION_H
#define LAB_SINGLYLINKEDLISTEMPTYEXCEPTION_H


#include <string>
#include "SinglyLinkedListException.h"

class SinglyLinkedListEmptyException : public SinglyLinkedListException{
public:
    std::string execute();
};

#endif //LAB_SINGLYLINKEDLISTEMPTYEXCEPTION_H
