#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

class StringUtils {
public:
    static int findstr(const std::string& str, const std::string& sub);
    static int lenstr(const std::string& str);
};

#endif // STRING_UTILS_H
