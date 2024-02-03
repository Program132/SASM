#include "Lexer.h"

namespace SASM::Lexer {
    std::ostream &operator<<(std::ostream &flux, const Token &token) {
        flux << "'" << token.content << "' | '" << stringTypes[token.type] << "'";
        return flux;
    }

    std::vector<Token> Lexer(std::string const& code) {
        Token current;
        std::vector<Token> listTokens;

        for (auto const& e : code) {
            switch(e) {
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
                    if (current.type == WHITESPACE) {
                        current.type = INT;
                        current.content.append(1, e);
                    } else {
                        current.content.append(1, e);
                    }
                    break;

                case '#':
                case ',':
                    Conclude(current, listTokens);
                    current.type = OPERATOR;
                    current.content.append(1, e);
                    Conclude(current, listTokens);
                    break;

                case ':':
                    if (current.type == IDENTIFIANT) {
                        current.type = POSSIBLE_GOTO;
                        current.content.append(1, e);
                        Conclude(current, listTokens);
                    } else {
                        Conclude(current, listTokens);
                        current.type = OPERATOR;
                        current.content.append(1, e);
                        Conclude(current, listTokens);
                    }

                case ' ':
                case '\n':
                    Conclude(current, listTokens);
                    break;

                default:
                    if (current.type == WHITESPACE || current.type == INT) {
                        Conclude(current, listTokens);
                        if (e == 'R') {
                            current.type = POSSIBLE_REGISTER;
                            current.content.append(1, e);
                        } else {
                            current.type = IDENTIFIANT;
                            current.content.append(1, e);
                        }
                    } else {
                        current.content.append(1, e);
                    }
            }
        }
        Conclude(current, listTokens);
        return listTokens;
    }

    void Conclude(Token& token, std::vector<Token>& listTokens) {
        if (token.type != WHITESPACE) {
            listTokens.push_back(token);
        }
        token.type = WHITESPACE;
        token.content.erase();
    }
}