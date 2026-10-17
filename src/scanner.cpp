#include "../include/scanner.h"
#include "../include/token.h"
#include "../include/error.h"
#include <vector>

std::vector<Token> Scanner::scanTokens() {
    while (!isAtEnd()) {
        start = current;
        scanToken();
    }

    tokens.push_back(Token(TokenType::END_OF_FILE, "", "", line));
    return tokens;
}

bool Scanner::isAtEnd() {
    return current >= source.size();
}

void Scanner::scanToken() {
    char c = advance();

    switch (c) {
        case '(': addToken(LEFT_PAREN); break;
        case ')': addToken(RIGHT_PAREN); break;
        case '{': addToken(LEFT_BRACE); break;
        case '}': addToken(RIGHT_BRACE); break;
        case ',': addToken(COMMA); break;
        case '.': addToken(DOT); break;
        case '-': addToken(MINUS); break;
        case '+': addToken(PLUS); break;
        case ';': addToken(SEMICOLON); break;
        case '*': addToken(STAR); break;
        case '!':
            addToken(match('=') ? BANG_EQUAL : BANG);
            break;
        case '=':
            addToken(match('=') ? EQUAL_EQUAL : EQUAL);
            break;
        case '>':
            addToken(match('=') ? GREATER_EQUAL : GREATER);
            break;
        case '<':
            addToken(match('=') ? LESS_EQUAL : LESS);
            break;
        case '/':
            if (match('/')) {
                while (peek() != '\n' && !isAtEnd()) advance();
                break;
            }
            addToken(SLASH);
            break;
        case '\n': line++;
        case ' ':
        case '\r':
        case '\t': break;
        case '"': handleString(); break;
        default:
            if (isdigit(c)) {
                handleDigit();
                break;
            }

            if (isalpha(c)) {
                handleIdentifier();
                break;
            }

            error(line, "Unexpected character...");
            break;
    }
}

char Scanner::advance() {
    return source[current++];
}

bool Scanner::match(const char c) {
    if (isAtEnd()) return false;
    if (source[current] != c) return false;

    current++;
    return true;
}

bool Scanner::isalphanum(const char c) {
    return isalnum(c) || c == '_';
}

char Scanner::peek() {
    if (isAtEnd()) return '\n';
    return source[current];
}

char Scanner::peekNext() {
    if (current + 1 >= source.size()) return '\n';
    return source[current + 1];
}

void Scanner::addToken(const TokenType type) {
    addToken(type, "");
}

void Scanner::addToken(const TokenType type, const std::string& literal) {
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token(type, text, literal, line));
}

void Scanner::handleString() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }

    if (peek() != '"') {
        error(line, "Unterminated string...");
        return;
    }

    advance();

    const std::string literal = source.substr(start + 1, current - start - 2);
    addToken(STRING, literal);
}

void Scanner::handleDigit() {
    while (isdigit(peek())) advance();

    if (peek() == '.' && isdigit(peekNext())) {
        advance();
    }

    while (isdigit(peek())) advance();

    const std::string literal = source.substr(start, current - start);
    addToken(NUMBER, literal);
}

void Scanner::handleIdentifier() {
    while (isalphanum(peek())) advance();

    const std::string text = source.substr(start, current - start);

    if (keywords.contains(text)) addToken(keywords[text], text);
    else addToken(IDENTIFIER, text);
}
