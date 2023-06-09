#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <string_view>
#include <map>

#include "../Tokenizer/TokenClass.h"
#include "../Expecter/Expecter.h"
#include "../Definitions/Register.h"
#include "../Definitions/Memory.h"
#include "../Utils/Data.h"

namespace SASM::Parser {
    class Data;

    class Parser {
    public:
        static void MainParser(std::vector<SASM::Tokenizer::Token>& tokens);
        static bool ManagerInstruction(std::vector<SASM::Tokenizer::Token> &vector, std::vector<Token>::iterator &currentToken,
                           Data& data);

        // Instructions:
        static void MOVInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data);
        static void STRInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data);
        static void LDRInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data);
        static void ADDInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data);
        static void SUBInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data);
    };
}
