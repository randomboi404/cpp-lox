#include "../include/error.h"

#include <iostream>
#include <string>

static void error(const int line, const std::string& message) {
    const std::string where{};
    report(line, where, message);
}

static void report(const int line, const std::string& where, const std::string& message) {
    std::cerr << "[line " << line << "] Error " << where << " : " << message;
    hadError = true;
}
