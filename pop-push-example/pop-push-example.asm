section .data

section .bss

section .text
global _start
_start:
    mov  eax, 5
    mov ebx, 15
    push eax
    pop ebx

; Label for a function
testFunction:
    mov ecx, 10
    ; RET is return opcode, return from  afunction back to calling location
    ret 

    ; CALL opcode jump that will save the calling location on the stack
    call testFunction
    ; Exit program
    mov eax, 1
    mov ebx, 0
    int 80h
