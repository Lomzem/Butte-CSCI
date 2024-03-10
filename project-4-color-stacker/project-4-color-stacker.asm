;*************************************************************************
; Lawjay Lee
; Project Due Date: 2024-03-21
; Project Name: Color Stacker
; CSCI-10: Computer Architecture and Organization
; Spring 2024
; Project Description: TODO
;*************************************************************************

section .data
    ; store prompt string in variable, 10 for newline
    promptInput db "Please enter r, b, g, p, c, y, or w to add a color! Enter q to quit", 10

    ; len of prompt string with memory subtraction
    promptInputLen equ $-promptInput

    ; store invalid input message in variable, 10 for newline
    invalidInputMsg db "Invalid color character! Skipping...", 10

    ; len of prompt string with memory subtraction
    invalidInputMsgLen equ $-invalidInputMsg

    ; string to show a color was added, 10 for newline
    colorAddedMsg db "Succesfully added a color!", 10

    ; len of color added message
    colorAddedMsgLen equ $-colorAddedMsg

    ; constant for storing newline (decimal 10)
    newline db 10

    ; Constant for ascii character representing wanting to quit
    quitChar equ "q"

    ; Constants for color ascii characters
    redChar equ "r"
    blueChar equ "b"
    greenChar equ "g"
    purpleChar equ "p"
    cyanChar equ "c"
    yellowChar equ "y"
    whiteChar equ "w"

    ; Constants for strings to print for the colors, 10 for newline
    ; AND the lengths of the strings with memory subtraction

    redStr db "RED light!", 10
    redStrLen equ $-redStr

    blueStr db "BLUE light!", 10
    blueStrLen equ $-blueStr
    
    greenStr db "GREEN light!", 10
    greenStrLen equ $-greenStr

    purpleStr db "PURPLE light!", 10
    purpleStrLen equ $-purpleStr

    cyanStr db "CYAN light!", 10
    cyanStrLen equ $-cyanStr

    yellowStr db "YELLOW light!", 10
    yellowStrLen equ $-yellowStr

    whiteStr db "WHITE light!", 10
    whiteStrLen equ $-whiteStr

section .bss
    userInput resb 1; reserve one byte for user input (one character)

section .text
global _start
_start:
    ; EDI register will store the number of items on the stack
    ; It initially starts with 0 (stack is empty)
    mov edi, 0

PromptForInput:
    ; This section is for prompting the user to input
    ; something and storing their input into "userInput"

    ; Print prompt input string
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, promptInput; string to write
    mov edx, promptInputLen; length of string
    int 80h; syscall

    ; Get user input
    mov eax, 3; sys_read
    mov ebx, 0; from stdin
    mov ecx, userInput; store input in userInput
    mov edx, 1; only read one byte (should be character for quit or a color)
    int 80h; syscall

    ; Get rid of newline from user pressing enter
    mov eax, 3; sys_read
    mov ebx, 0; from stdin
    mov ecx, esi; store input in esi (don't need it so can overwrite esi later)
    mov edx, 1; only read one byte (should be newline)
    int 80h; syscall

CheckForQuit:
    ; This section is for checking is "userInput" is "q"

    ; move the value from userInput into eax
    mov eax, [userInput]

    ; check if userInput is equal to quit character
    cmp eax, quitChar

    ; if userInput is quit character, go to quick section
    je Quit

    ; since didn't jump, user didn't enter quit
    ; go to CheckForColors to see if input is a color
    jmp CheckForColors
    
CheckForColors:
    ; This section is for validating that the user
    ; inputted a valid color

    ; move value of userInput into eax for checking
    mov eax, [userInput]

    ; check for red
    ; check if userInput == redChar
    ; if true, jump to isRed
    cmp eax, redChar
    je isRed

    ; check for blue
    ; check if userInput == blueChar
    ; if true, jump to isBlue
    cmp eax, blueChar
    je isBlue

    ; by now, it's not a color, jump to invalid input
    jmp InvalidInput

isRed:
    push redChar; push redChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

isBlue:
    push blueChar; push blueChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

ColorAddedMsg:
    ; This section is for confirming that a color
    ; was successfully added to stack

    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, colorAddedMsg; msg to write
    mov edx, colorAddedMsgLen; len of msg
    int 80h; syscall
    jmp newLinePromptAgain; jump to newLinePromptAgain

InvalidInput:
    ; This section prints invalid input message

    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, invalidInputMsg; message to write
    mov edx, invalidInputMsgLen; len of message
    int 80h; syscall

    jmp newLinePromptAgain; jump to newLinePromptAgain

newLinePromptAgain:
    ; This section prints a newline before once
    ; again asking for user to input something

    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, newline; newline
    mov edx, 1; newline is one byte
    int 80h; syscall

    jmp PromptForInput; go back to PromptForInput

Quit:
    ; Exit program
    mov eax, 1; sys_exit
    mov ebx, 0; exit code 0 -- no errors
    int 80h; syscall

