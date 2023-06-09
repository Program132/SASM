cmake_minimum_required(VERSION 3.25)
project(SASM)

set(CMAKE_CXX_STANDARD 23)

add_executable(SASM main.cpp src/Tokenizer/TokenClass.cpp src/Tokenizer/TokenClass.h src/Parser/Parser.cpp src/Parser/Parser.h src/Expecter/Expecter.cpp src/Expecter/Expecter.h src/Definitions/Register.cpp src/Definitions/Register.h src/Utils/Data.cpp src/Utils/Data.h src/Definitions/Memory.cpp src/Definitions/Memory.h)
