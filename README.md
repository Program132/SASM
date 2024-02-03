# SASM

## Description

SASM is a programming language made in C++ inspired by the basic ASM.
The goal is to give an example to students of a little programming language (parser).
I am not using a compiler !

WARNING: The language is like an emulator, it's not saved in your real memory ! By the way, in the reality every instruction are in the memory.

## Read the code

### Definitions

There is a lot of definitions of special objects like **Registers**, **Memory**, etc.
It's like you're defining a type of word or sentence.

### Lexer

The lexer is the first part of an interpreted language, his role is to create the grammar of the language.

### Parser

The parser use the results of the lexer to create something, like if you were saying a sentence, you have verbs, adjectives, adverbs etc. and you use them to create a sentence. 

### Expecter

The files with the name "Expecter" are used to obtain the desired arguments, in this language we can wait for a value, a register or an instruction.

## Links

- [Documentation of SASM](doc/main.md)
- [Conditions Instructions in basic ASM](https://chortle.ccsu.edu/assemblytutorial/Chapter-24/ass24_4.html)