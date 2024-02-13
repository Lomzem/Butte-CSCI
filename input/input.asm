; value to start with
section .data
    ; 0Ah = 10, Prompt plus newline
    ; db = some number of bytes
    prompt db "Please type a number from 1 to 9, or type 0 to exit", 0Ah

    ; create a const for len of prompt
    ; equ should have exactly this value
    ; $ means current location in memory
    ; current location - prompt location
    prompt_len equ $-prompt

; no value to start with (block starting symbol)
section .bss
    ; resb means reserve bytes
    input resb 1
    total resb 1; reserve one byte for total

; code section
section .text
global _start
_start:
    ; initialize total
    mov al, 0
    mov [total], al

repeat:
    ; Prompt
    mov eax, 4; do syscall sys_write
    mov ebx, 1; send to stdout
    mov ecx, prompt; where the data you're going to print goes
    mov edx, prompt_len; how much data
    int 80h; run syscall

    ; Get Input
    mov eax, 3; do syscall sys_read
    mov ebx, 0; get from stdin
    mov ecx, input; store data into input
    mov edx, 1; how long is data
    int 80h; run syscall

    ; data from stdin from sys_read, getting ascii chars
    ; convert single ascii char to integer
    ; subtract ascii 0 (48) from ascii char

    ; take input and put into a register but not full size one (8bit)
    mov al, [input]; deference pointer
    ; al is lower 8 bits of eax, so also changing eax
    ; get 8 bit value into different 32 bit register

    ; special move instruction
    ;movzx is move with Zero Extend
    ; fill rest with 0
    movzx ebx, al

    ; now we could convert it from ascii to integer
    sub ebx, "0"; subtract char '0' (48 decimal) from ebx, store in ebx

    cmp ebx, 0; check if input number is equal to 0
    je stop; go to stop and end program if input is 0

    ; got past both exit conditions
    ; convert total back into ascii
    ; print converted total with sys_write

    jmp repeat

stop:
    ; Exit
    mov eax, 1
    mov ebx, 0
    int 80h
