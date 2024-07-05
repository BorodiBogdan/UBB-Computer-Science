bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;[[b*c-(e+f)]/(a+d)
;a,b,c,d-byte, e,f,g,h-word
segment data use32 class=data
    a DB 6
    b DB 8
    c DB 11
    d DB 5
    f DW 257
    e DW 343
    


segment code use32 class=code
    start:
        MOV AL, [a];a
        MOV BL, [c]
        MUL BL; AX: a * c
        
        MOV BX, [e];e
        ADD BX, [f];e + f
        
        SUB AX, BX;a * c - (e + f)
        
        MOV CL, [a];a
        ADD CL, [d];a + d
        
        MOV CH, 0
        MOV DX, 0
        DIV CX;[[b*c-(e+f)]/(a+d)
        
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
