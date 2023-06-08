#include "Expecter.h"

std::optional<Token> ExpectInstruction(std::vector<SASM::Tokenizer::Token>& tokens) {
    if (!tokens.empty()) {
        auto start_t = tokens.begin();
        auto end_t = tokens.end();
        if (start_t->TokenType == IDENTIFIANT) {
            tokens.erase(start_t);
            return *start_t;
        }
    }
    return std::nullopt;
}

std::optional<Token> ExpectOperator(std::vector<SASM::Tokenizer::Token>& tokens) {
    if (!tokens.empty()) {
        auto start_t = tokens.begin();
        auto end_t = tokens.end();
        if (start_t->TokenType == OPERATOR) {
            tokens.erase(start_t);
            return *start_t;
        }
    }
    return std::nullopt;
}

std::optional<Token> ExpectValue(std::vector<SASM::Tokenizer::Token>& tokens) {
    if (!tokens.empty()) {
        auto start_t = tokens.begin();
        auto end_t = tokens.end();
        if (start_t->TokenType == INT) {
            tokens.erase(start_t);
            return *start_t;
        }
    }
    return std::nullopt;
}

std::optional<Token> ExpectRegister(std::vector<SASM::Tokenizer::Token>& tokens) {
    if (!tokens.empty()) {
        auto start_t = tokens.begin();
        auto end_t = tokens.end();
        if (start_t->TokenType == POSSIBLE_REGISTER) {
            tokens.erase(start_t);
            return *start_t;
        }
    }
    return std::nullopt;
}
