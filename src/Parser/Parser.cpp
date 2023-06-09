#include "Parser.h"

namespace SASM::Parser {
    void Parser::LDRInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data) {

    }

    void Parser::STRInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data) {
        auto possibleRegister = ExpectRegister(currentToken, Tokens);
        bool pass = true;

        if (!possibleRegister) {
            std::cerr << "Forgot the register to put your int value!" << std::endl;
            pass = false;
        }

        if (!ExpectOperator(currentToken, Tokens, ",").has_value()) {
            std::cerr << "Forgot to put ',' after the register!" << std::endl;
            pass = false;
        }

        auto possibleValue = ExpectValue(currentToken, Tokens);

        if (!possibleValue.has_value()) {
            std::cerr << "Forgot to give a case to save the register " << possibleRegister->TokenContent << "!" << std::endl;
            pass = false;
        }

        auto reg = data.getRegister(possibleRegister->TokenContent);
        if (!reg.has_value()) {
            std::cerr << "The register " << possibleRegister->TokenContent << " has not a value!" << std::endl;
            pass = false;
        }

        if (pass) {
            Memory mem(reg->getValue(), std::stoi(possibleValue->TokenContent));
            data.push_memory(mem);
            reg->setMemory(mem.getSlot());
            data.Registers[reg->getName()] = reg.value();
        }
    }

    void Parser::MOVInstruction(std::vector<SASM::Tokenizer::Token> &Tokens, std::vector<Token>::iterator& currentToken, Data& data) {
        auto possibleRegister = ExpectRegister(currentToken, Tokens);
        bool pass = true;

        if (!possibleRegister.has_value()) {
            std::cerr << "Forgot the register to put your int value!" << std::endl;
            pass = false;
        }

        int numberR;
        int i = 0;
        for (auto const& e : possibleRegister->TokenContent) {
            if (i == 1) {
                numberR = e - '0';
            } else if (i == 2) {
                switch(e) {
                    case '0':
                        numberR = 10;
                        break;
                    case '1':
                        numberR = 11;
                        break;
                    case '2':
                        numberR = 12;
                        break;
                    default:
                        std::cerr << "You have only 13 registers, R0 to R12!" << std::endl;
                        pass = false;
                }
                break;
            }
            i++;
        }

        if (!ExpectOperator(currentToken, Tokens, ",").has_value()) {
            std::cerr << "Forgot to put ',' after the register!" << std::endl;
            pass = false;
        }

        if (!ExpectOperator(currentToken, Tokens, "#").has_value()) {
            std::cerr << "Forgot to put '#' after ',' to give a value to the register " << possibleRegister->TokenContent << "!" << std::endl;
            pass = false;
        }

        auto possibleValue = ExpectValue(currentToken, Tokens);
        if (!possibleValue.has_value()) {
            std::cerr << "Forgot to give a value to the register " << possibleRegister->TokenContent << "!" << std::endl;
            pass = false;
        }

        if (pass) {
            SASM::Parser::Register r(possibleRegister->TokenContent, possibleValue->TokenContent);
            data.push_register(r);
        }
    }

    bool Parser::ManagerInstruction(std::vector<SASM::Tokenizer::Token> &vector, std::vector<Token>::iterator &currentToken, Data& data) {
        auto instruction = ExpectInstruction(currentToken, vector);
        if (instruction.has_value()) {
            if (instruction->TokenContent == "MOV") {
                MOVInstruction(vector, currentToken, data);
                return true;
            } else if (instruction->TokenContent == "STR") {
                STRInstruction(vector, currentToken, data);
                return true;
            } else if (instruction->TokenContent == "LDR") {
                LDRInstruction(vector, currentToken, data);
                return true;
            }
        }
        return false;
    }

    void Parser::MainParser(std::vector<SASM::Tokenizer::Token>& tokens) {
        Data dataLang;

        auto current_token = tokens.begin();

        while (current_token != tokens.end()) {
            if (!ManagerInstruction(tokens, current_token, dataLang)) {
                std::cerr << "Unknown: " << current_token->TokenContent << std::endl;
                ++current_token;
                continue;
            }
        }
     }
}