#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <string_view>

#include "../Tokenizer/TokenClass.h"
#include "../Expecter/Expecter.h"

namespace SASM::Parser {
    void MainParser(std::vector<SASM::Tokenizer::Token>& tokens);
    bool ManagerInstruction(std::vector<SASM::Tokenizer::Token>& vector, std::vector<SASM::Tokenizer::Token>::iterator& currentToken);

    // Instructions:
    void MOVInstruction(std::vector<SASM::Tokenizer::Token>& Tokens, std::vector<SASM::Tokenizer::Token>::iterator& currentToken);
}
