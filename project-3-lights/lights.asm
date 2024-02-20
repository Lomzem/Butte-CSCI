;*************************************************************************
; Lawjay Lee
; Project Due Date: 2024-02-22
; Project Name: Lights
; CSCI-10: Computer Architecture and Organization
; Spring 2024
; Project Description: Uses loops to print multiple color strings
; depending on what value is in the ESI register.
;*************************************************************************

; initialized data
section .data

; RED
red equ 2; store 2 as constant in variable red
redStr db "RED light!", 10; store string + newline (10) in redStr variable
redLen equ $-redStr; memory location subtraction for length

; BLUE
blue equ 4; store 4 as constant in variable blue
blueStr db "BLUE light!", 10; store string + newline (10) in blueStr variable
blueLen equ $-blueStr; memory location subtraction for length

; PURPLE (RED + BLUE)
purple equ 6
purpleStr db "PURPLE light!", 10; store string + newline (10) in purpleStr variable
purpleLen equ $-purpleStr; memory location subtraction for length

; GREEN
green equ 8
greenStr db "GREEN light!", 10; store string + newline (10) in greenStr variable
greenLen equ $-greenStr; memory location subtraction for length

; YELLOW
yellow equ 10
yellowStr db "YELLOW light!", 10; store string + newline (10) in yellowStr variable
yellowLen equ $-yellowStr; memory location subtraction for length

; CYAN
cyan equ 12
cyanStr db "CYAN light!", 10; store string + newline (10) in cyanStr variable
cyanLen equ $-cyanStr; memory location subtraction for length

; WHITE
white equ 14
whiteStr db "WHITE light!", 10; store string + newline (10) in whiteStr variable
whiteLen equ $-whiteStr; memory location subtraction for length

; uninitialized data
section .bss

section .text
global _start
_start:
    mov esi, 0; start with esi being 0

loopStart:
    add esi, 2; add 2 to esi every loop start

    ; RED
    cmp esi, red; compare esi value to red constant
    je redJump; jump if esi value == red constant

    ; BLUE
    cmp esi, blue; compare esi value to blue constant
    je blueJump; jump if esi value == blue constant

    ; PURPLE
    cmp esi, purple; compare esi value to purple constant
    je purpleJump; jump if esi value == purple constant

    ; GREEN
    cmp esi, green; compare esi value to green constant
    je greenJump; jump if esi value == green constant

    ; YELLOW
    cmp esi, yellow; compare esi value to yellow constant
    je yellowJump; jump if esi value == yellow constant

    ; CYAN
    cmp esi, cyan; compare esi value to cyan constant
    je cyanJump; jump if esi value == cyan constant

    ; WHITE
    cmp esi, white; compare esi value to white constant
    je whiteJump; jump if esi value == white constant

    jmp exit

redJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, redStr; msg to print is redStr
    mov edx, redLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

blueJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, blueStr; msg to print is blueStr
    mov edx, blueLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

purpleJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, purpleStr; msg to print is purpleStr
    mov edx, purpleLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

greenJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, greenStr; msg to print is greenStr
    mov edx, greenLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

yellowJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, yellowStr; msg to print is yellowStr
    mov edx, yellowLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

cyanJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, cyanStr; msg to print is cyanStr
    mov edx, cyanLen; length of msg to print
    int 80h; invoke syscall
    jmp loopStart; jump back to start of loop

whiteJump:
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, whiteStr; msg to print is whiteStr
    mov edx, whiteLen; length of msg to print
    int 80h; invoke syscall
    jmp exit; white is the last color so just exit the program
    ; could cmp current esi value to white constant and jump if greater
    ; but that's extra unnecessary steps
    
exit:
    mov eax, 1; sys_exit
    mov ebx, 0; Exit with code 0 - no errors
    int 80h; invoke syscall
