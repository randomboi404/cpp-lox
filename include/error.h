#pragma once

#include <string>

inline bool hadError{};
void error(int line, const std::string& message);
void report(int line, const std::string& where, const std::string& message);
