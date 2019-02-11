#include <string>
#include "EmptyFileException.h"

std::string EmptyFileException::execute() {
    return "Error! File can not be empty!";
}
