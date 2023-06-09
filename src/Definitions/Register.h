#pragma once

#include <iostream>
#include <string_view>

namespace SASM::Parser {
    class Register {
    private:
        std::string name;
        std::string value;
        int memory = 0;

    public:
        Register();
        Register(std::string_view n, std::string_view v);

        [[nodiscard]] std::string getName() const;
        [[nodiscard]] std::string getValue() const;
        [[nodiscard]] int getMemory() const;
        void setName(std::string_view n);
        void setValue(std::string_view v);
        void setMemory(int c); // Case of the register in the memory

        friend std::ostream& operator<<(std::ostream& flux, Register const& r);
    };
}
