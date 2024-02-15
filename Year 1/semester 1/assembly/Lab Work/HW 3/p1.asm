bits 32

global start        


extern exit               

import exit msvcrt.dll     

segment data use32 class=data
    a db 0Ah
    b dw 258h
    c dd 0xFFDFFFA
    d dq 0xF0FFFF9FDFFFA
    
;c-(a+d)+(b+d) -> 1
segment code use32 class=code
    start:
        
        MOV EAX, dword [d];d
        MOV EDX, dword [d + 4];d -> EDX:EAX
        
        MOV EBX, 0
        MOV BL, byte [a]
        ADD EAX, EBX
        ADC EDX, 0
        ;ADC EDX, 0; a + d in case there is a carry
              
        MOV EBX, [c]
        SUB EBX, EAX
        SBB EDX, 0
        MOV EAX, EBX; c - (a + d)
        
        MOV ECX, 0
        MOV CX, [b]
        ADD EAX, ECX
        ADC EDX, 0
        
        ADD EAX, dword [d]
        ADC EDX, 0
        ADD EDX, dword[d + 4]
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
