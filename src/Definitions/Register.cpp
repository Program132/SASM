#include "Register.h"

namespace SASM::Parser {
    std::string Register::getName() const {
        return this->name;
    }

    std::string Register::getValue() const {
        return this->value;
    }

    int Register::getMemory() const {
        return this->memory;
    }

    void Register::setName(std::string_view n) {
        this->name = n;
    }

    void Register::setValue(std::string_view v) {
        this->value = v;
    }

    void Register::setMemory(int c) {
        this->memory = c;
    }

    std::ostream &operator<<(std::ostream &flux, const Register& r) {
        flux << "(REGISTER: " << r.getName() <<  ", " << r.getValue() << ", " << std::to_string(r.getMemory()) << ")" << std::endl;
        return flux;
    }

    Register::Register(std::string_view n, std::string_view v) {
        this->setName(n);
        this->setValue(v);
    }

    Register::Register() = default;
}