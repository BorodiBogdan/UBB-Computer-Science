bits 32 ; assembling for the 32 bits architecture


global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we 
import exit msvcrt.dll    

; c+(a*a-b+7)/(2+a), a-byte; b-doubleword; c-qword
segment data use32 class=data
    a db 10
    b dd 57
    c dq 10001

; c+(a*a-b+7)/(2+a), a-byte; b-doubleword; c-qword - signed
segment code use32 class=code
    start:
        MOV EAX, dword[c]
        MOV EDX, dword[c + 4]
        PUSH EDX
        PUSH EAX;d is on the stack
        
        MOV DX, 0
        MOV AL, [a]
        MUL AL;AX:a * a
        
        PUSH DX
        PUSH AX
        
        POP EAX
        
        SUB EAX, [b]
        ADD EAX, 7;EAX = a * a - b + 7
        
        MOV EBX, 0
        MOV EDX, 0;EDX:ABX = a * a - b + 7
        MOV BL, [a]
        ADD BL, 2;EBX - a + 2
          
        DIV EBX;EAX = (a * a - b + 7) / (a + 2)
        MOV EDX, 0
        
        POP EBX
        POP ECX;ECX:EBX - c
        
        ADD EAX, EBX
        ADC EDX, ECX
          
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
