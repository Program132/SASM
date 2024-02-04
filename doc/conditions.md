# Conditions

In this section, we will speak about conditions to compare registers and their values.
The first thing you need to know is the first instruction ``CMP`` which means "Compare" and you have to specify the register and a value.

Format: ``CMP Re, #Value``

Warning: if the condition return "false", make sure to do a jump to don't run content from the label if the condition was true.

## Greater or Equal (BGE)

Format: ``BGE label``

Example: 
```
MOV R0, #10
CMP R0, #9
BGE condition_true
MOV R1, #1
condition_true:
    MOV R1, #0
    
MOV R0, #3
CMP R0, #5
BGE condition_true2
MOV R1, #1
condition_true2:
    MOV R1, #0
```


## Greater (BGT)

Format: ``BGT label``

Example:
```
MOV R0, #10
CMP R0, #25
BGT condition_true
MOV R1, #1
condition_true:
    MOV R1, #0
    
MOV R0, #3
CMP R0, #3
BGT condition_true2
MOV R1, #1
condition_true2:
    MOV R1, #0
```

## Lower or Equal (BLE)

Format: ``BLE label``

Example:
```
MOV R0, #25
CMP R0, #10
BLE condition_true
MOV R1, #1
condition_true:
    MOV R1, #0
    
MOV R0, #4
CMP R0, #3
BLE condition_true2
MOV R1, #1
condition_true2:
    MOV R1, #0
```

## Lower (BLT)

Format: ``BLT label``

Example:
```
MOV R0, #25
CMP R0, #10
BLT condition_true
MOV R1, #1
condition_true:
    MOV R1, #0
    
MOV R0, #3
CMP R0, #3
BLT condition_true2
MOV R1, #1
condition_true2:
    MOV R1, #0
```

## Lower (BEQ)

Format: ``BEQ label``

Example:
```
MOV R0, #30
CMP R0, #30
BEQ condition_true
MOV R1, #1
condition_true:
    MOV R1, #0
    
MOV R0, #3
CMP R0, #0
BEQ condition_true2
MOV R1, #1
condition_true2:
    MOV R1, #0
```