#include "Register.h"

#include <utility>

namespace SASM::Definitions {
    Register::Register() = default;
    
    Register::Register(std::string name, std::string value) {
        this->name = name;
        this->value = value;
    }

    std::string Register::getName() {
         return this->name;
    }
    
    void Register::setName(std::string& name) {
        this->name = name;
    }
    
    int Register::getMemorySlot() const {
        return this->memorySlot;
    }

    void Register::setMemorySlot(int& slot) {
        this->memorySlot = slot;
    }
    
    std::string Register::getValue() {
        return this->value;
    }
    
    void Register::setValue(const std::string& value) {
        this->value = value;
    }
}