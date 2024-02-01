section .data

section .bss

section .text

global main
main:
mov ebp, esp; for debugging

mov eax, 2

; Needed to exit the program correctly
mov eax, 1; sys_exit system call number
mov ebx, 0; return 0 status on exit - 'No Errors'
int 80h; iterrupt to invoke sys call

