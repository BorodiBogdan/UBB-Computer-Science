bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a DW 12
    b DW 6
    c DW 7
    d DW 5
    ; ...

; our code starts here
; 15 ------> (a + d - c) - (b + b)
segment code use32 class=cod 
    start:
        MOV AX,[a]
        ADD AX,[d]
        SUB AX, [c]
        MOV BX, [b]
        ADD BX, BX
        ADD AX, BX
        
        PUSH AX
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
