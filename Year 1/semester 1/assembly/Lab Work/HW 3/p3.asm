bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    

;(c+b+a)-(d+d)
;a - byte, b - word, c - double word, d - qword - Signed representation
segment data use32 class=data
    a db -10
    b dw -7
    c dd 230
    d dq 1000

; our code starts here
segment code use32 class=code
    start:
        MOV AL, [a]
        cbw
        ADD AX, [b]
        cwd
        
        PUSH DX
        PUSH AX
        
        POP EAX
        
        cdq
        ADD EAX, [c]
        ADC EDX, 0;a + c + d
        
        PUSH EDX
        PUSH EAX
        
        MOV EAX, dword [d]
        MOV EDX, dword [d + 4]
        
        ADD EAX, dword [d]
        ADC EDX, dword [d + 4]; d + d
        
        POP ECX
        POP EBX;EBX:ECX d + d
        
        PUSH EAX;adding a + b + c to stack
        PUSH EDX
        
        MOV EDX, EBX
        MOV EAX, ECX;EDX:EAX a + b + c
        
        POP EBX
        
        SUB EAX, EBX;(a + b + c) - (d + d)
        
        POP EBX
        
        SBB EAX, EBX;(a + b + c) - (d + d)
        
        cdq
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
