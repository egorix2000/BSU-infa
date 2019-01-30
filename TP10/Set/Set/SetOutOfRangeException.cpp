#include <string>
#include "SetOutOfRangeException.h"

std::string SetOutOfRangeException::execute() {
    return ("Error! Index must be from " + std::to_string(min_) +
            " to " + std::to_string(max_-1) + ". Your index: " + std::to_string(actual_));
}