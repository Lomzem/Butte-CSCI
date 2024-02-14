;*************************************************************************
; Lawjay Lee
; Project Due Date: 2024-02-15
; Project Name: Adder
; CSCI-10: Computer Architecture and Organization
; Spring 2024
; Project Description: Receives integer input from user and adds them
;*************************************************************************

section .data

; For storing data with no starting value
section .bss
input resb 1; reserve one byte for input variable

section .text
global _start:
_start:

    ; End program
    mov eax, 1; sys_exit
    mov ebx, 0; return 0 on exit - No errors
    int 80h; interrupt for sys_call
