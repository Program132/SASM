#pragma once

#include <iostream>
#include <string_view>
#include <string>
#include <map>
#include <vector>

#include "../Definitions/Register.h"
#include "../Definitions/Memory.h"

namespace SASM::Parser {
    class Register;

    class Data {
    public:
        std::map<std::string, Register> Registers;
        std::map<int, Memory> Memories;

        std::optional<Register> getRegister(const std::basic_string<char>& name);
        void push_register(Register r);
        void push_memory(Memory m);
    };
}
