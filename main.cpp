#include <iostream>
#include <fstream>

#include "src/Tokenizer/TokenClass.h"
#include "src/Parser/Parser.h"

int main(int argc, char** argv) {
    std::string pos_FileName;
    if (argc == 2) {
        pos_FileName = argv[1];
    } else {
        std::cout << "File : ";
        std::cin >> pos_FileName;
        std::cout << std::endl;
    }

    std::ifstream possibleFile {pos_FileName};
    if (!possibleFile) {
        std::cerr << "Did not find the file!" << std::endl;
        return -1;
    }

    std::string contentFile((std::istreambuf_iterator<char>(possibleFile)), (std::istreambuf_iterator<char>()));

    std::vector<SASM::Tokenizer::Token> TokensCode = SASM::Tokenizer::Builder::ParserTokens(contentFile);

    SASM::Parser::Parser::MainParser(TokensCode);

    return 0;
}