#pragma once

#include <iostream>
#include <vector>
#include <string_view>

namespace SASM::Tokenizer {
    enum Types {
        WHITESPACE,
        IDENTIFIANT,
        INT,
        OPERATOR,
        POSSIBLE_REGISTER
    };

    inline constexpr const char *sAllTokenTypes[] {
            "WHITESPACE",
            "IDENTIFIANT",
            "INT",
            "OPERATOR",
            "POSSIBLE_REGISTER"
    };

    class Token {
    public:
        enum Types TokenType = WHITESPACE;
        std::string TokenContent;

        friend std::ostream& operator<<(std::ostream& flux, Token const& token);
    };

    class Builder {
    public:
        static std::vector<Token> ParserTokens(std::string_view code);
        static void OverToken(Token& token, std::vector<Token>& tokens);
    };
}