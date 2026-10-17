#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "token.h"

inline std::unordered_map<std::string, TokenType> keywords = {
    { "and", AND },
    { "or", OR },
    { "if", IF },
    { "else", ELSE },
    { "true", TRUE },
    { "false", FALSE },
    { "none", NIL },
    { "for", FOR },
    { "while", WHILE },
    { "print", PRINT },
    { "fn", FUN },
    { "class", CLASS },
    { "super", SUPER },
    { "this", THIS },
    { "return", RETURN },
    { "var", VAR },
};

struct Scanner {
    std::string source;
    std::vector<Token> tokens;
    int start{};
    int current{};
    int line{1};

    explicit Scanner(std::string source) : source(std::move(source)) {}

    std::vector<Token> scanTokens();
    bool isAtEnd();

    void scanToken();
    char advance();
    bool match(char c);
    bool isalphanum(char c);
    char peek();
    char peekNext();
    void addToken(TokenType type);
    void addToken(TokenType type, const std::string& literal);

    void handleString();
    void handleDigit();
    void handleIdentifier();
};
