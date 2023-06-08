#include "Parser.h"

namespace SASM::Parser {
    void MOVInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken) {
        auto possibleRegister = ExpectRegister(Tokens);
        std::cout << "possibleRegister -> " << possibleRegister->TokenContent << std::endl;
    }

    bool ManagerInstruction(std::vector<SASM::Tokenizer::Token> &vector, std::vector<Token>::iterator& currentToken) {
        auto instruction = ExpectInstruction(vector);
        std::cout << instruction->TokenContent << std::endl;
        if (instruction->TokenContent == "MOV") {
            MOVInstruction(vector, currentToken);
            return true;
        }
        return false;
    }

    void MainParser(std::vector<SASM::Tokenizer::Token>& tokens) {
        auto current_token = tokens.begin();

        while (current_token != tokens.end()) {
            if (ManagerInstruction(tokens, current_token)) {
                if (current_token->TokenContent.empty()) {
                    continue;
                }
                std::cerr << "Unknown: " << current_token->TokenContent << std::endl;
            }
        }
     }
}