#include "StringUtils.h"
#include <iostream>

// Static method to find a substring in a string
int StringUtils::findstr(const std::string& str, const std::string& sub) {
    if (sub.length() > str.length()) {
        return -1;
    }
    for (size_t i = 0; i <= str.length() - sub.length(); ++i) {
        if (str.substr(i, sub.length()) == sub) {
            return i;
        }
    }
    return -1;
}

// Static method to get the length of a string
int StringUtils::lenstr(const std::string& str) {
    return str.length();
}
