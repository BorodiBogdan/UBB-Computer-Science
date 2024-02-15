bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DB 10
    b DB 9
    c DB 8
    d DB 7
    ; ...

; our code starts here
;15 --> a - b - d + 2 + c + (10 - b)
segment code use32 class=code
    start:
        MOV AL, a;a
        SUB AL, b;a - b
        SUB AL, d;a - b - d
        ADD AL, 2;a - b - d + 2
        ADD AL, c;a - b - d + 2 + c
        MOV AH, 10;10
        SUB AH, b;10 - b
        ADD AL, AH;a - b - d + 2 + c + (10 - b)
        ; ...
        PUSH AL
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
