#pragma once

#include <iostream>
#include <vector>

namespace SASM::Lexer {
    enum Types {
        WHITESPACE,
        IDENTIFIANT,
        INT,
        OPERATOR,
        POSSIBLE_REGISTER,
        POSSIBLE_GOTO
    };

    inline constexpr const char *stringTypes[] {
        "WHITESPACE",
        "IDENTIFIANT",
        "INT",
        "OPERATOR",
        "POSSIBLE_REGISTER"
    };

    class Token {
    public:
        enum Types type = WHITESPACE;
        std::string content;
        friend std::ostream& operator<<(std::ostream& flux, Token const& token);
    };

    std::vector<Token> Lexer(std::string const& code);
    void Conclude(Token& token, std::vector<Token>& listTokens);
}