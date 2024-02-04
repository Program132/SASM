# SASM

## Description

SASM is a programming language made in C++ inspired by the basic ASM.
It's not using a compiler ! By the way, it shows to students how they can create an interpreted programming languages.

WARNING: The language is like an emulator, it's not saved in your real memory !

Example in basic ASM (goal of this code: **Pythagore's theorem**):
```
      MOV R0, #5
      MOV R1, #7
      STR R0, 100
      STR R1, 101
      MOV R2, R0
      MOV R3, R1
      MOV R4, R0
      MOV R5, R1
carre_r0:
      CMP R2, #1
      BGT add_r0
      B end_r0
add_r0:
      ADD R0, R0, R4
      SUB R2, R2, #1
      B carre_r0
end_r0:
      STR R0, 100
      B carre_r1
carre_r1:
      CMP R3, #1
      BGT add_r1
      B end
add_r1:
      ADD R1, R1, R5
      SUB R3, R3, #1
      B carre_r1
end:
      STR R0, 100
      STR R1, 101
      B addition_ab
addition_ab:
      MOV R12, #0
      ADD R12, R0, R1
      STR R12, 102
      B start_sqrt
start_sqrt:
      MOV R6, #1
      MOV R7, #0
      MOV R8, #0
      MOV R9, R7
      CMP R6, #1000
      BLT add_i
add_i:
      ADD R6, R6, #1
      B divide_r12_r7
divide_r12_r7:
      ADD R9, R9, #1
      CMP R12, R9
      BLT add_quotient
add_quotient:
      ADD R8, R8, #1
      HALT
```

At the end of your code, you have the values of every registers declared in your program !

## Links to the documentation

- [Error Codes](errors.md)
- [MOV Instruction](mov.md)
- [STR Instruction](str.md)
- [LDR Instruction](ldr.md)
- [ADD Instruction](add.md)
- [SUB Instruction](sub.md)
- [B Instruction](b.md)
- [Conditions Instructions](conditions.md)