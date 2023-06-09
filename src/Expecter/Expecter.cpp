#include "Expecter.h"

std::optional<Token> ExpectInstruction(std::vector<SASM::Tokenizer::Token>::iterator &current, std::vector<SASM::Tokenizer::Token>& tokens) {
    if (current->TokenType == IDENTIFIANT) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectRegister(std::vector<SASM::Tokenizer::Token>::iterator &current, std::vector<SASM::Tokenizer::Token>& tokens) {
    if (current->TokenType == POSSIBLE_REGISTER) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectValue(std::vector<SASM::Tokenizer::Token>::iterator &current, std::vector<SASM::Tokenizer::Token>& tokens) {
    if (current->TokenType == INT) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectOperator(std::vector<SASM::Tokenizer::Token>::iterator &current, std::vector<SASM::Tokenizer::Token>& tokens, std::string_view o) {
    if (current->TokenType == OPERATOR && current->TokenContent == o) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}
