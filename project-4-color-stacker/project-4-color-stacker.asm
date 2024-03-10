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

    ; string start listing colors, 10 for newlines
    listStartStr db 10, "Here are your colors:", 10

    ; length of listStartStr
    listStartStrLen equ $-listStartStr

    ; done message, 10 for newline
    doneMsg db "Done!", 10

    ; length of doneMsg
    doneMsgLen equ $-doneMsg

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

    ; Constants for color ascii characters (uppercase)
    redCharU equ "R"
    blueCharU equ "B"
    greenCharU equ "G"
    purpleCharU equ "P"
    cyanCharU equ "C"
    yellowCharU equ "Y"
    whiteCharU equ "W"

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

    ; if userInput is quit character, go to quit section
    je StartQuit

    ; since didn't jump, user didn't enter quit
    ; go to CheckForColors to see if input is a color
    jmp CheckForColors
    
CheckForColors:
    ; This section is for validating that the user
    ; inputted a valid color

    ; move value of userInput into eax for checking
    mov eax, [userInput]

    ; check if userInput == redChar
    ; if true, jump to isRed
    ; checks both lowercase and uppercase
    cmp eax, redChar
    je isRed
    cmp eax, redCharU
    je isRed

    ; check if userInput == blueChar
    ; if true, jump to isBlue
    ; checks both lowercase and uppercase
    cmp eax, blueChar
    je isBlue
    cmp eax, blueCharU
    je isBlue

    ; check if userInput == greenChar
    ; if true, jump to isGreen
    ; checks both lowercase and uppercase
    cmp eax, greenChar
    je isGreen
    cmp eax, greenCharU
    je isGreen

    ; check if userInput == purpleChar
    ; if true, jump to isPurple
    ; checks both lowercase and uppercase
    cmp eax, purpleChar
    je isPurple
    cmp eax, purpleCharU
    je isPurple

    ; check if userInput == cyanChar
    ; if true, jump to isCyan
    ; checks both lowercase and uppercase
    cmp eax, cyanChar
    je isCyan
    cmp eax, cyanCharU
    je isCyan

    ; check if userInput == yellowChar
    ; if true, jump to isYellow
    ; checks both lowercase and uppercase
    cmp eax, yellowChar
    je isYellow
    cmp eax, yellowCharU
    je isYellow

    ; check if userInput == whiteChar
    ; if true, jump to isWhite
    ; checks both lowercase and uppercase
    cmp eax, whiteChar
    je isWhite
    cmp eax, whiteCharU
    je isWhite

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

isGreen:
    push greenChar; push greenChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

isPurple:
    push purpleChar; push purpleChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

isCyan:
    push cyanChar; push cyanChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

isYellow:
    push yellowChar; push yellowChar onto stack
    inc edi; increment stack counter
    jmp ColorAddedMsg

isWhite:
    push whiteChar; push whiteChar onto stack
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

StartQuit:
    ; Print that we're starting to list colors
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, listStartStr; msg to write
    mov edx, listStartStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; actually start looping

QuitColorLoop:
    ; This section loops through the stack
    ; until it is empty, printing colors as
    ; it pops from the stack
    cmp edi, 0; compare edi (stack counter) to 0
    jle exit; jump to exit is <= 0

    ; if got to here, means stack isn't empty
    ; check for colors and print associated strings

    pop eax; pop from stack and store in eax for comparisons
    dec edi; decrement stack counter since we popped one

    ; if popped value == redChar go to exitRed
    cmp eax, redChar
    je exitRed

    ; if popped value == blueChar go to exitBlue
    cmp eax, blueChar
    je exitBlue

    ; if popped value == greenChar go to exitGreen
    cmp eax, greenChar
    je exitGreen

    ; if popped value == purpleChar go to exitPurple
    cmp eax, purpleChar
    je exitPurple

    ; if popped value == cyanChar go to exitCyan
    cmp eax, cyanChar
    je exitCyan

    ; if popped value == yellowChar go to exitYellow
    cmp eax, yellowChar
    je exitYellow

    ; if popped value == whiteChar go to exitWhite
    cmp eax, whiteChar
    je exitWhite

exitRed:
    ; Print red message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, redStr; msg to print
    mov edx, redStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitBlue:
    ; Print blue message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, blueStr; msg to print
    mov edx, blueStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitGreen:
    ; Print green message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, greenStr; msg to print
    mov edx, greenStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitPurple:
    ; Print purple message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, purpleStr; msg to print
    mov edx, purpleStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitCyan:
    ; Print cyan message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, cyanStr; msg to print
    mov edx, cyanStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitYellow:
    ; Print yellow message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, yellowStr; msg to print
    mov edx, yellowStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exitWhite:
    ; Print white message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, whiteStr; msg to print
    mov edx, whiteStrLen; len of msg
    int 80h; syscall
    jmp QuitColorLoop; go back to QuitColorLoop

exit:
    ; Print done message
    mov eax, 4; sys_write
    mov ebx, 1; to stdout
    mov ecx, doneMsg; msg to write
    mov edx, doneMsgLen; len of message
    int 80h; syscall

    ; Exit program
    mov eax, 1; sys_exit
    mov ebx, 0; exit code 0 -- no errors
    int 80h; syscall

