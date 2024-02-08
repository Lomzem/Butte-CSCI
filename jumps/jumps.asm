; immutable
section .data

; mutable
section .bss

; contains code
section .text

global main
main:
; some extra code before jump
mov eax, 5
mov ebx, 10

jumpTest:
    cmp eax, ebx; Comparison changes flags
    ; cmp subtracts second from first
    ; eax = 5
    ; ebx = 10
    ; eax - ebx = 5 - 10 = -5
    ; never stores -5 anywhere
    ; negative means signed byte, most significant bit is 1, so signed flag is on

    ; Conditional jump
    ; Need label, jump opcode, comparison between between some operands
    ; conditional jump could be used like break
    je quitLoop; jump if eq

    sub ebx, eax; ebx - eax, store in ebx

    ; Unconditional jump:
    ; To do a jump, need label 2 jump to, and jump opcode
    jmp jumpTest ; goes back to "jumpTest:"

quitLoop:
    ; Exit program
    mov eax, 1; sys_exit sys call
    mov ebx, 0; sys_exit 0 status no errors
    int 80h; interrupt to invoke sys call
