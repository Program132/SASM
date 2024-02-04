#include <iostream>
#include <fstream>

#include "Lexer/Lexer.h"
#include "Parser/Parser.h"

int main(int const argc, char** argv) {
    std::string pos_FileName;
    if (argc == 2) {
        pos_FileName = argv[1];
    } else {
        std::cout << "Path to file: ";
        std::cin >> pos_FileName;
        std::cout << std::endl;
    }

    std::ifstream possibleFile {pos_FileName};
    if (!possibleFile) {
        std::cerr << "Did not find the file!" << std::endl;
        return -1;
    }

    std::string contentFile((std::istreambuf_iterator<char>(possibleFile)), (std::istreambuf_iterator<char>()));

    std::vector<SASM::Lexer::Token> TokensCode = SASM::Lexer::Lexer(contentFile);

    // for (auto const& token : TokensCode) { std::cout << token << std::endl; }

    SASM::Parser::parseTokens(TokensCode);

    return 0;
}