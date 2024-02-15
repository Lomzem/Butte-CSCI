section .data

section .bss

section .text
global _start
_start:

loopLabel:

    ; if then
    ; need comparison and jump
    ; jump somewhere if eax equals 5
    mov eax, 19; put 5 into eax
    cmp eax, 5; compare eax with 5
    je goHere; jump to goHere if eax == 5

    ; condition false

    ; NOT CORRECT
    ; cmp eax, 19
    ; cmp eax, 20
    ; je nine
    ; jg greater

    ; Correct
    cmp eax, 19
    je nine
    cmp eax, 20
    jg greater

    mov eax, 17
    jmp loopLabel

nine:
    mov ebx, 19
    jmp goHere; jump to exit

greater:
    mov ebx, 20
    jmp loopLabel; go back to start of loop

goHere:

    ; Exit
    mov eax, 1; sys_exit
    mov ebx, 0; 0 status - No errors
    int 80h; invoke syscall
