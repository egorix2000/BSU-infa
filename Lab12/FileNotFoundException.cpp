#include <string>
#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(std::string file) {
    file_ = file;
}

std::string FileNotFoundException::execute() {
    return "Error! File [" + file_ + "] doesn't exist!";
}
