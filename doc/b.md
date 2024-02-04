# B Instruction

**B** is a way to jump to another location called **label** (like in C++ with *goto*, or you understand this like a 'function' but with no arguments inside).

## Format
``B label``

## Example
```
B hello
hello:
    MOV R0, #3
```