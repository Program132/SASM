cmake_minimum_required(VERSION 3.25)
project(SASM)

set(CMAKE_CXX_STANDARD 23)

add_executable(SASM main.cpp src/Tokenizer/TokenClass.cpp src/Tokenizer/TokenClass.h)
