#pragma once

#include <string>
#include <utility>

enum TokenType {
    // Single character tokens
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two character tokens
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keywords
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
    PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

    Token(
        const TokenType type,
        std::string lexeme,
        std::string literal,
        const int line
        ) : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}

    std::string toString() {
        return std::to_string(static_cast<int>(type)) + " " + lexeme + " " + literal;
    }
};
