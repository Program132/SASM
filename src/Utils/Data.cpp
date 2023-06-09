#include <optional>
#include "Data.h"

namespace SASM::Parser {
    void Data::push_register(SASM::Parser::Register r) {
        this->Registers[r.getName()] = r;
    }

    void Data::push_memory(Memory m) {
        this->Memories[m.getSlot()] = m;
    }

    std::optional<Register> Data::getRegister(const std::basic_string<char>& name) {
        if (this->Registers.contains(name)) {
            return this->Registers[name];
        }
        return std::nullopt;
    }

    std::optional<Memory> Data::getMemory(const int &slot_memory) {
        if (this->Memories.contains(slot_memory)) {
            return this->Memories[slot_memory];
        }
        return std::nullopt;
    }
}