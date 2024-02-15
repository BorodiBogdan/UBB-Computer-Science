bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DB 5
    b DB 5
    c DB 43
    d DW 201
    e DW 432
    ; ...

; 18 a,b,c - byte d, e -> word
; 200 - [3 * (c + b + d / a) - 300] 
segment code use32 class=code
    start:
        MOV AX, [d];d
        DIV byte [a];d / a
        MOV BL, [b]
        ADD BL, AL;B + D / A
        ADD BL, [c];c + b + d / a
        
        MOV AH, 0
        MOV AL, BL
        MOV CL, 3
        MUL CL;3 * (c + b + d / a)
        SUB AX, 300;3 * (c + b + d / a) - 300
        MOV BX, AX
        MOV AX, 200;200
        SUB AX, BX;200 - (3 * (c + b + d / a) - 300)
        
        
        ; ...
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
