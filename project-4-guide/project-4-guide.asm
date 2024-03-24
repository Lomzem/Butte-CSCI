section .data
    BEST equ 'z'

    prompt db "Please type in the best letter so I can print it for you.", 10
    promptLen equ $-prompt

    doneStr db 10, "Done!", 10
    doneLen equ $-doneStr

    ; Flag to track valid input
    validFlag db 0

section .bss

section .text
global _start
_start:
    ; Show prompt
    mov eax, 4
    mov ebx, 1
    mov ecx, prompt
    mov edx, promptLen
    int 80h

    ; Get input
    mov eax, 3
    mov ebx, 0
    mov ecx, input
    mov edx, 1
    int 80h

    ; Check if input is a Z
    ; can't cmp without size of data comparing
    cmp byte [input], BEST
    je setValid;

checkDone:
    cmp byte [validFlag], 1
    je done

setValid:
    mov byte [validFlag], 1
    jmp checkDone

done:
    mov eax, 1
    mov ebx, 0
    int 80h
    
