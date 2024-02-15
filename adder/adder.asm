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
prompt_len equ $-prompt; gets current memory location - prompt location

newline_text db 0Ah; used to print newline at the end

total_text db "Total Sum: "; Prefix for final message
total_text_len equ $-total_text; Len of prefix

; For storing data with no starting value
section .bss
input resb 1; reserve one byte for input variable
trash resb 1; reserve one byte for a variable that just holds trash
total resb 1; reserve one byte for total variable

section .text
global _start:
_start:

; initialize total
mov al, 0; move 0 into 8-bit al
mov [total], al; move 0 into total

repeat:

    ; Prompt user to enter input number between 1 and 9, or 0 to exit
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, prompt; get what to write from prompt variable
    mov edx, prompt_len; get how many bytes to write from len variable
    int 80h; interrupt for sys_call to sys_write

    ; Get input
    mov eax, 3; sys_read
    mov ebx, 0; read from stdin
    mov ecx, input; store data into input
    mov edx, 1; only read in one byte
    int 80h; interrupt for sys_call to sys_read

    ; This is to avoid the prompt being shown twice by the user pressing enter
    mov eax, 3; sys_read
    mov ebx, 0; read from stdin
    mov ecx, trash; store the user pressing <Enter> into the trash
    mov edx, 1; only read in one byte
    int 80h; interrupt for sys_call to sys_read

    mov al, [input]; move dereferenced input into 8-bit register
    movzx ebx, al; move al value into ebx and fill rest with 0

    sub ebx, "0"; convert input into integer from ascii

    ; *** EXIT CONDITION: USER TYPED 0 ***
    cmp ebx, 0; check if input is "0"
    je exit; jump to exit label if user entered 0

    mov al, [total]; move total into 8-bit al to work with it
    movzx ecx, al; move total from al to ecx, fill rest with 0

    mov edx, ecx; copy total into edx to work with it as "temp total"
    add edx, ebx; add input to "temp total"

    ; *** EXIT CONDITION: New Total > 9
    ; if "temp total" > 9 jump to exit without adding to total
    cmp edx, 9; compare "temp total" to 9
    jg exit; jump to exit

    ; else add input to total and repeat
    add ecx, ebx; add total with input integer, store in ecx
    mov [total], ecx; move the total back into total variable

    jmp repeat; Go back to beginning

exit:
    mov al, [total]; move total into 8-bit al
    add al, "0"; convert total into ascii from integer
    mov [total], al; move ascii value back into total

    ; Print prefix message
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, total_text; print string from total_text
    mov edx, total_text_len; length of message
    int 80h; interrupt for sys_call

    ; Print actual total value
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, total; print total which is ascii now
    mov edx, 1; length of message, total should only be one byte
    int 80h; interrupt for sys_call

    ; Print newline to avoid weird symbols
    mov eax, 4; sys_write
    mov ebx, 1; write to stdout
    mov ecx, newline_text; print newline to stdout
    mov edx, 1; newline is one byte
    int 80h; interrupt for sys_call

    ; End program
    mov eax, 1; sys_exit
    mov ebx, 0; return 0 on exit - No errors
    int 80h; interrupt for sys_call
