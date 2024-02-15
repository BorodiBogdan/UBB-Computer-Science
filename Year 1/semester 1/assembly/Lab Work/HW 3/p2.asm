bits 32 
global start        

extern exit                
import exit msvcrt.dll    

;c-a-(b+a)+c
;a - byte, b - word, c - double word, d - qword - Unsigned representation

segment data use32 class=data
    c dd 101
    a db 12
    b dw 10
    
segment code use32 class=code
    start:
        MOV EAX, [c]
        
        MOV EBX, 0
        MOV BL, [a]
        SUB EAX, EBX;c - a
           
        PUSH EAX
        
        MOV AX, [b]
        ADD AL, [a]
        ADC AH, 0;b + a
            
        MOV EBX, 0
        MOV BX, AX
        POP EAX
        
        SUB EAX, EBX;c - a - (b + a)
        
        MOV EDX, 0
        ADD EAX, [c]
        ADC EDX, 0
        
        push    dword 0     
        
        call    [exit]       
