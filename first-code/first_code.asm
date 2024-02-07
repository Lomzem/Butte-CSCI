section .data

section .bss

section .text

global main
main:; Add numbers with eax and ebx
mov ebp, esp; for debugging

mov eax, 5 ; mov 5 into eax
mov ebx, 6 ; mov 6 into ebx
add eax, ebx

sub eax, 10 ; Subtraction: subtract 10 from eax

inc eax ; Increment eax by 1
dec ebx; Decrement ebx by 1

; Needed to exit the program correctly
mov eax, 1; sys_exit system call number
mov ebx, 0; return 0 status on exit - 'No Errors'
int 80h; interrupt to invoke sys call
