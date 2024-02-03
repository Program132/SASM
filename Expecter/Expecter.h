#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <string_view>
#include <optional>
#include <map>

#include "../Lexer/Lexer.h"

using namespace SASM;
using namespace SASM::Lexer;

std::optional<Token> ExpectInstruction(std::vector<Token>::iterator &current, std::vector<Token>& tokens);
std::optional<Token> ExpectOperator(std::vector<Token>::iterator &current, std::vector<Token>& tokens, std::string_view o);
std::optional<Token> ExpectValue(std::vector<Token>::iterator &current, std::vector<Token>& tokens);
std::optional<Token> ExpectRegister(std::vector<Token>::iterator &current, std::vector<Token>& tokens);