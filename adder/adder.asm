;*************************************************************************
; Lawjay Lee
; Project Due Date: 2024-02-15
; Project Name: Adder
; CSCI-10: Computer Architecture and Organization
; Spring 2024
; Project Description: Receives integer input from user and adds them
;*************************************************************************

; For storing data with a starting value
section .data
; Create prompt variable, allocate db for string, 0Ah for newline
prompt db "Enter a number between 1 and 9, or enter 0 to exit", 0Ah

; const variable to store len of prompt string
; gets current memory location - prompt location
prompt_len equ $-prompt

; For storing data with no starting value
section .bss
input resb 1; reserve one byte for input variable
total resb 1; reserve on byte for total variable

section .text
global _start:
_start:
    ; Prompt user to enter input number between 1 and 9, or 0 to exit
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, prompt; get what to write from prompt variable
    mov edx, prompt_len; get how many bytes to write from len variable
    ; mov ecx, 

    ; End program
    mov eax, 1; sys_exit
    mov ebx, 0; return 0 on exit - No errors
    int 80h; interrupt for sys_call
