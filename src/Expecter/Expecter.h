#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <string_view>
#include <optional>
#include <map>

#include "../Tokenizer/TokenClass.h"

using namespace SASM;
using namespace SASM::Tokenizer;

std::optional<Token> ExpectInstruction(std::vector<SASM::Tokenizer::Token>& tokens);
std::optional<Token> ExpectOperator(std::vector<SASM::Tokenizer::Token>& tokens);
std::optional<Token> ExpectValue(std::vector<SASM::Tokenizer::Token>& tokens);
std::optional<Token> ExpectRegister(std::vector<SASM::Tokenizer::Token>& tokens);