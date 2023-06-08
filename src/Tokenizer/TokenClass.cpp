#include "TokenClass.h"

std::ostream &SASM::Tokenizer::operator<<(std::ostream &flux, const SASM::Tokenizer::Token &token) {
    flux << "Token: " << token.TokenContent << ", type: " << sAllTokenTypes[token.TokenType];
    return flux;
}

namespace SASM::Tokenizer {

    std::vector<Token> Builder::ParserTokens(std::string_view code) {
        std::vector<Token> Tokens;
        Token current_token;

        for (auto const &element : code) {
            switch (element) {
                case '9':
                case '8':
                case '7':
                case '6':
                case '5':
                case '4':
                case '3':
                case '2':
                case '1':
                case '0':
                    if (current_token.TokenType == WHITESPACE) {
                        current_token.TokenType = INT;
                        current_token.TokenContent.append(1, element);
                    } else if (current_token.TokenType == IDENTIFIANT) {
                        OverToken(current_token, Tokens);
                        current_token.TokenType = INT;
                        current_token.TokenContent.append(1, element);
                    } else if (current_token.TokenType == POSSIBLE_REGISTER) {
                        current_token.TokenContent.append(1, element);
                        OverToken(current_token, Tokens);
                    } else {
                        current_token.TokenContent.append(1, element);
                    }
                    break;

                case '#':
                case ':':
                case ',':
                    OverToken(current_token, Tokens);
                    current_token.TokenType = OPERATOR;
                    current_token.TokenContent.append(1, element);
                    OverToken(current_token, Tokens);
                    break;

                case ' ':
                case '\t':
                    OverToken(current_token, Tokens);
                    break;

                default:
                    if (current_token.TokenType == WHITESPACE || current_token.TokenType == INT) {
                        OverToken(current_token, Tokens);
                        if (element == 'R') {
                            current_token.TokenType = POSSIBLE_REGISTER;
                            current_token.TokenContent.append(1, element);
                        } else {
                            current_token.TokenType = IDENTIFIANT;
                            current_token.TokenContent.append(1, element);
                        }
                    } else {
                        current_token.TokenContent.append(1, element);
                    }
                    break;
            }
        }
        OverToken(current_token, Tokens);
        return Tokens;
    }

    void Builder::OverToken(Token &token, std::vector<Token> &tokens) {
        if (token.TokenType != WHITESPACE) {
            tokens.push_back(token);
        }

        token.TokenType = WHITESPACE;
        token.TokenContent.erase();
    }
}