#include "Expecter.h"

std::optional<Token> ExpectInstruction(std::vector<Token>::iterator &current, std::vector<Token>& tokens) {
    if (current->type == IDENTIFIANT) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectRegister(std::vector<Token>::iterator &current, std::vector<Token>& tokens) {
    if (current->type == POSSIBLE_REGISTER) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectValue(std::vector<Token>::iterator &current, std::vector<Token>& tokens) {
    if (current->type == INT) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}

std::optional<Token> ExpectOperator(std::vector<Token>::iterator &current, std::vector<Token>& tokens, std::string_view o) {
    if (current->type == OPERATOR && current->content == o) {
        auto returnt = current;
        current++;
        return *returnt;
    }
    return std::nullopt;
}