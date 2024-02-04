#include "Parser.h"

namespace SASM::Parser {
    // Data class functions :

    std::optional<Definitions::Register> Data::getRegister(const std::basic_string<char> &name) {
        if (this->Registers.contains(name)) {
            return this->Registers[name];
        }
        return std::nullopt;
    }

    std::optional<Definitions::Memory> Data::getMemory(const int &slot_memory) {
        if (this->Memories.contains(slot_memory)) {
            return this->Memories[slot_memory];
        }
        return std::nullopt;
    }

    void Data::push_register(Definitions::Register r) {
        this->Registers[r.getName()] = r;
    }

    void Data::push_memory(const Definitions::Memory& m) {
        this->Memories[m.getSlot()] = m;
    }



    // Parser :

    void logsEndProgram(Data& data) {
        for (auto& r : data.Registers) {
            std::cout << "Register Name: " << r.second.getName() << ", value: " << r.second.getValue() << std::endl;
        }
        for (auto& r : data.Memories) {
            std::cout << "Memory Slot: " << r.second.getSlot() << ", value: " << r.second.getValue() << std::endl;
        }
    }

    void parseTokens(std::vector<Token>& listTokens) {
        Data data;

        auto current = listTokens.begin();

        while (current != listTokens.end()) {
            if (!managerInstructions(current, listTokens, data)) {
                ++current;
                continue;
            }
        }

        logsEndProgram(data); // for logs (to see the values of registers + memories)
    }

    bool managerInstructions(std::vector<Token>::iterator& current,std::vector<Token>& listTokens, Data& data) {
        auto instruction = ExpectInstruction(current, listTokens);
        if (instruction.has_value() && instruction->content == "HALT") {
            haltInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "MOV") {
            movInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "STR") {
            strInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "LDR") {
            ldrInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "ADD") {
            addInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "SUB") {
            subInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "B") {
            bInstruction(current, listTokens, data);
            return true;
        } else if (instruction.has_value() && instruction->content == "CMP") {
            cmpInstruction(current, listTokens, data);
            return true;
        }
        return false;
    }

    void haltInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        logsEndProgram(data); // for logs (to see the values of registers + memories)
        exit(0);
    }

    void movInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto targetRegister = ExpectRegister(current, listTokens);
        if (!targetRegister.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'MOV R0, #14'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'MOV R8, #800'" << std::endl;
            exit(2);
        }

        if (!ExpectOperator(current, listTokens, "#").has_value()) {
            std::cerr << "Error: Need '#'. Ex: 'MOV R1, #3'" << std::endl;
            exit(3);
        }

        auto targetRegisterValue = ExpectValue(current, listTokens);
        if (!targetRegisterValue.has_value()) {
            std::cerr << "Error: Need a value for the register. Ex: 'MOV R3, #7'" << std::endl;
            exit(4);
        }

        if (std::stoi(targetRegister->content.substr(1)) > 12) {
            std::cerr << "Error: There is a maximum of 13 registers (R0 to R12). Ex: 'MOV R12, #5'" << std::endl;
            exit(5);
        }

        Definitions::Register r(targetRegister->content, targetRegisterValue->content);
        data.push_register(r);
    }

    void strInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto targetRegister = ExpectRegister(current, listTokens);
        if (!targetRegister.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'STR R0, 150'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'STR R1, 20'" << std::endl;
            exit(2);
        }

        auto targetSlot = ExpectValue(current, listTokens);
        if (!targetSlot.has_value() || targetSlot->type != Lexer::Types::INT) {
            std::cerr << "Error: Need the memory slot. Ex: 'STR R3, 2'" << std::endl;
            exit(3);
        }

        auto R = data.getRegister(targetRegister->content);
        if (R.has_value()) {
            Definitions::Memory m(R->getValue(), std::stoi(targetSlot->content));
            data.push_memory(m);
        } else {
            Definitions::Memory m("0", std::stoi(targetSlot->content));
            data.push_memory(m);
        }
    }

    void ldrInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto targetRegister = ExpectRegister(current, listTokens);
        if (!targetRegister.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'STR R0, 150'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'STR R1, 20'" << std::endl;
            exit(2);
        }

        auto targetSlot = ExpectValue(current, listTokens);
        if (!targetSlot.has_value() || targetSlot->type != Lexer::Types::INT) {
            std::cerr << "Error: Need the memory slot. Ex: 'STR R3, 2'" << std::endl;
            exit(3);
        }

        auto M = data.getMemory(std::stoi(targetSlot->content));
        if (M.has_value()) {
            Definitions::Register r;
            r.setName(targetRegister->content);
            r.setValue(M->getValue());
            data.push_register(r);
        } else {
            std::cerr << "Error: The value in this slot does not exist. Ex: 'STR R3, 2'" << std::endl;
            exit(6);
        }
    }

    void addInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto toSave = ExpectRegister(current, listTokens);
        if (!toSave.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'ADD R3, R1, R2'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'ADD R3, R1, R2'" << std::endl;
            exit(2);
        }

        auto first = ExpectRegister(current, listTokens);
        if (!first.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'ADD R3, R1, R2'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'STR R1, 20'" << std::endl;
            exit(2);
        }

        auto second = ExpectRegister(current, listTokens);
        if (!first.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'ADD R3, R1, R2'" << std::endl;
            exit(1);
        }

        auto R1 = data.getRegister(first->content);
        auto R2 = data.getRegister(second->content);
        if (R1.has_value() && R2.has_value()) {
            Definitions::Register r(toSave->content,
                                    std::to_string(std::stoi(R1->getValue()) + std::stoi(R2->getValue()))
                                    );
            data.push_register(r);
        } else {
            std::cerr << "Error: The registers are not valid. Ex: 'ADD R3, R1, R2'" << std::endl;
            exit(7);
        }
    }

    void subInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto toSave = ExpectRegister(current, listTokens);
        if (!toSave.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'SUB R3, R1, R2'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'SUB R3, R1, R2'" << std::endl;
            exit(2);
        }

        auto first = ExpectRegister(current, listTokens);
        if (!first.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'SUB R3, R1, R2'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'STR R1, 20'" << std::endl;
            exit(2);
        }

        auto second = ExpectRegister(current, listTokens);
        if (!first.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'SUB R3, R1, R2'" << std::endl;
            exit(1);
        }

        auto R1 = data.getRegister(first->content);
        auto R2 = data.getRegister(second->content);
        if (R1.has_value() && R2.has_value()) {
            Definitions::Register r(toSave->content,
                                    std::to_string(std::stoi(R1->getValue()) - std::stoi(R2->getValue()))
            );
            data.push_register(r);
        } else {
            std::cerr << "Error: The registers are not valid. Ex: 'SUB R3, R1, R2'" << std::endl;
            exit(7);
        }
    }

    void bInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto gotoLoc = ExpectInstruction(current, listTokens);
        if (!gotoLoc.has_value()) {
            std::cerr << "Error: You need to specify the name of the location. Ex: 'B hello'" << std::endl;
            exit(8);
        }
        int indexGoto = -1;
        for (int i = 0; i < listTokens.size(); ++i) {
            if (listTokens[i].content == gotoLoc->content+":") {
                indexGoto = i;
                break;
            }
        }
        if (indexGoto == -1) {
            std::cerr << "Error: You need to specify the name of the location. Ex: 'B hello'" << std::endl;
            exit(8);
        }

        current = listTokens.begin() + indexGoto;
    }

    void cmpInstruction(std::vector<Token>::iterator& current, std::vector<Token>& listTokens, Data& data) {
        auto targetRegister = ExpectRegister(current, listTokens);
        if (!targetRegister.has_value()) {
            std::cerr << "Error: Need the register (R0 to R12). Ex: 'CMP R0, #14'" << std::endl;
            exit(1);
        }

        if (!ExpectOperator(current, listTokens, ",").has_value()) {
            std::cerr << "Error: Need ','. Ex: 'CMP R8, #800'" << std::endl;
            exit(2);
        }

        if (!ExpectOperator(current, listTokens, "#").has_value()) {
            std::cerr << "Error: Need '#'. Ex: 'CMP R1, #3'" << std::endl;
            exit(3);
        }

        auto targetValue = ExpectValue(current, listTokens);
        if (!targetValue.has_value()) {
            std::cerr << "Error: Need a value to compare with the register. Ex: 'CMP R3, #7'" << std::endl;
            exit(4);
        }

        auto conditionalOperator = ExpectInstruction(current, listTokens); // BGE, BGT, BLE, BLT or BEQ
        if (!conditionalOperator.has_value() || (conditionalOperator->content != "BGE" && conditionalOperator->content != "BGT" && conditionalOperator->content != "BLE" && conditionalOperator->content != "BLT" && conditionalOperator->content != "BEQ")) {
            std::cerr << "Error: Need the conditional action. Ex: 'BGE condition_true'" << std::endl;
            exit(9);
        }

        auto gotoLoc = ExpectInstruction(current, listTokens);
        if (!gotoLoc.has_value()) {
            std::cerr << "Error: You need to specify the name of the location. Ex: 'B hello'" << std::endl;
            exit(8);
        }

        int indexGoto = -1;
        for (int i = 0; i < listTokens.size(); ++i) {
            if (listTokens[i].content == gotoLoc->content+":") {
                indexGoto = i;
                break;
            }
        }

        if (indexGoto == -1) {
            std::cerr << "Error: You need to specify the name of the location. Ex: 'B hello'" << std::endl;
            exit(8);
        }

        auto R = data.getRegister(targetRegister->content);
        if (!R.has_value()) {
            std::cerr << "Error: Need a valid register. Ex: 'CMP R12, #3'" << std::endl;
            exit(7);
        }

        int vR = std::stoi(R->getValue());
        int vComp = std::stoi(targetValue->content);

        if (conditionalOperator->content == "BGE" && vR >= vComp) { // >=
            current = listTokens.begin() + indexGoto;
        } else if (conditionalOperator->content == "BGT" && vR > vComp) { // >
            current = listTokens.begin() + indexGoto;
        } else if (conditionalOperator->content == "BLE" && vR <= vComp) { // <=
            current = listTokens.begin() + indexGoto;
        } else if (conditionalOperator->content == "BLT" && vR < vComp) { // <
            current = listTokens.begin() + indexGoto;
        } else if (conditionalOperator->content == "BEQ" && vR == vComp) { // ==
            current = listTokens.begin() + indexGoto;
        }
    }
}