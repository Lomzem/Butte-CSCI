section .data

section .bss

section .text

global main
main:
mov ebp, esp; for debugging

; 1
mov eax, 5; move value 5 into eax

;2
mov edx, ecx; move ecx value into edx

; 3
add eax, ebx; add and store in eax
mov ecx, eax; store eax value in ecx

; 4
sub ebx, eax; sub eax from ebx store in ebx
mov eax, ebx; mov ebx value into eax

; 5
dec ecx; decrement ecx

; 6
; initialize these four with 0
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0

; 7
inc eax; increment eax
add eax, eax; add eax to itself, store in eax

; 8
add ebx, ecx; add ebx and ecx store in ebx
dec ebx; decrement result

; 9
mov edx, 10; initialize edx with 10
dec edx; decrement
dec edx; decrement again

; 10
mov eax, 3; move 3 into eax
mov ebx, 5; move 5 into ebx
add eax, ebx; add eax and ebx, store in eax
; AFTER:
; eax has value 8
; ebx has value 5

; 11
mov eax, 6; move 6 into eax
mov ebx, 4; move 4 into ebx
sub eax, ebx; sub ebx from eax, store in eax
; AFTER:
; eax has value 2
; ebx has value 4

; 12
mov ecx, 9; store 9 into ecx
mov edx, 3; store 3 into edx
mov eax, 1; store 1 into eax
add eax, edx; add edx to eax, store in eax
sub ecx, eax; subtract eax from ecx, store in ecx
; AFTER:
; eax has value 10
; ebx has value 0?
; ecx has value -1
; edx has value 3

; Needed to exit the program correctly
mov eax, 1; sys_exit system call number
mov ebx, 0; return 0 status on exit - 'No Errors'
int 80h; iterrupt to invoke sys call
