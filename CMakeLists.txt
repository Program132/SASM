cmake_minimum_required(VERSION 3.25)
project(SASM)

set(CMAKE_CXX_STANDARD 23)

add_executable(SASM
        main.cpp
        Lexer/Lexer.cpp
        Lexer/Lexer.h
        Parser/Parser.cpp
        Parser/Parser.h
        Memory/Memory.cpp
        Memory/Memory.h
        Register/Register.cpp
        Register/Register.h
        Expecter/Expecter.cpp
        Expecter/Expecter.h
)
