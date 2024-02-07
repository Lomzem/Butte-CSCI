 ;*************************************************************************
 ; Your Name: Lawjay Lee
 ; Project Due Date: 2024-02-08
 ; Project Name: Project 1: Hello NASM
 ; CSCI-10: Computer Architecture and Organization
 ; Spring 2024
 ; Project Description: Prints "Hello, NASM" to stdout
 ;*************************************************************************

;data section: contains initialized data, variables and constants that have a value to start with
; immutable data
section .data
    ; Create a string var that contains the text that we will print
    ; name db data
    ; db means create space in memory some # of bytes

    msg db "Hello, NASM!", 0Ah; 0Ah = '\n' in ascii

    ; each ascii character is one byte of data, two digits of hex
    ; to write hex in code, put h at end or 0x in front
    ; 13 bytes long including newline
    ; to get len without counting, use math to find distance from end from beginning

; bss section: contains uninitialized data, declared but not assigned data yet (stands for Block Starting Symbol)
; mutable data
section .bss

; text section: contains the code for the program
section .text
global _start ;Declare entry point as global, avoid some errors
_start: 
    ; to print, need to use sys call: SYS_WRITE
    ; in syscall, args are GP registers: eax, ebx, ecx, edx
    ; eax tells what operation to do with syscall
    ; ebx is where you're sending the data
    ; ecx must have location of the data you're writing
    ; edx where the amount of data you're sending (bytes)

    ; SYS_WRITE system call: prints to the screen/sends data somewhere
    mov eax, 4 ; first arg, put 4 in eax, decides what syscall to do
    mov ebx, 1 ; second arg, put 1 in ebx, 1 = write to stdout
    mov ecx, msg ; third arg, put msg into ecx, tell computer where data we're writing is located
    mov edx, 13 ;  fourth arg, number of bytes that we're going to write

    ; Now syscall is completely setup and ready
    int 80h; triggers an interrupt, which will make syscall execute

    ; Exit the program
    mov eax, 1          ;sys_exit system call number
    mov ebx, 0          ;sys_exit, return 0 status on exit - 'No Errors'
    int 80h; interrupt to invoke a sys call
