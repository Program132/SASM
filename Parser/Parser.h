#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <optional>

#include "../Lexer/Lexer.h"
#include "../Memory/Memory.h"
#include "../Register/Register.h"
#include "../Expecter/Expecter.h"

namespace SASM::Parser {

    using namespace SASM::Lexer;

    class Data { // Data from program (the code)
    public:
        std::map<std::string, Definitions::Register> Registers;
        std::map<int, Definitions::Memory> Memories;

        std::optional<Definitions::Register> getRegister(const std::basic_string<char>& name);
        std::optional<Definitions::Memory> getMemory(const int &slot_memory);

        void push_memory(const Definitions::Memory& m);
        void push_register(Definitions::Register r);
    };

    void parseTokens(std::vector<Token>& listTokens);
    bool managerInstructions(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void logsEndProgram(Data& data);
    int getValueOrFromRegister(std::vector<Token>::iterator& current,std::vector<Token>& listTokens, Data& data);

    void haltInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data); // stopping the program
    void movInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void strInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void ldrInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void addInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void subInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data);
    void bInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data); // Goto
    void cmpInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data); // for conditions
}