#include "../include/error.h"

#include <iostream>
#include <string>

void error(const int line, const std::string& message) {
    const std::string where{};
    report(line, where, message);
}

void report(const int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " << line << "] Error " << where << " : " << message << '\n';
    hadError = true;
}
