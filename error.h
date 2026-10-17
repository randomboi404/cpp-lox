#pragma once

#include <string>

inline bool hadError{};
static void error(int line, const std::string& message);
static void report(int line, const std::string& where, const std::string& message);
