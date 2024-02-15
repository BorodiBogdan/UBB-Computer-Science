bits 32 

global start        


extern exit              

import exit msvcrt.dll    

;x/2+100*(a+b)-3/(c+d)+e*e - signed
;a,c-word; b,d-byte; e-doubleword; x-qword
segment data use32 class=data
    a dw 101
    c dw -121
    b db 10
    d db -120
    e dd -2
    x dq -213121
    two equ 2
    o_hundread equ 100
; x/2+100*(a+b)-3/(c+d)+e*e
segment code use32 class=code
    start:
        MOV EAX, dword [x]
        MOV EDX, dword [x + 4];EAX:EDX = x-qword
        
        MOV EBX, two
        
        IDIV EBX;now we have EAX:EDX / 2 in EAX and EAX:EDX % 2 in EDX
        
        PUSH EAX;x / 2 is on the stack
        
        MOV AX, [a]
        ADD AL, [b]
        ADC AH, 0
        
        MOV BX, o_hundread
            
        MUL BX;DX:AX = 100*(a+b)
        
        PUSH DX
        PUSH AX;lat 16 bits on the stack = 100*(a+b)
        
        POP EAX ; EAX = 100*(a+b)
        
        MOV EBX, EAX; EBX = 100*(a+b)
        
        POP EAX;EAX = x/2
        
        ADD EAX, EBX;EAX = x / 2 + 100*(a+b)
        
        PUSH EAX; x / 2 + 100*(a+b) on the stack
        
        MOV DX, 0
        MOV AX, 3
        
        MOV BX, [c]
        ADD BL, [d] 
        ADC BH, 0;we have c + d in BX
        
        IDIV BX;AX = 3 / (c + d)
        
        cwd;DX:AX = 3 / (c + d)
        
        PUSH DX
        PUSH AX
        POP EBX;EBX = 3 / (c + d)
        
        POP EAX
        SUB EAX, EBX;EAX = x / 2 + 100*(a+b) - 3 / (c + d)
        
        PUSH EAX;EAX = x / 2 + 100*(a+b) - 3 / (c + d) on the stack
        
        MOV EAX, [e]
        IMUL EAX;EDX:EAX = e * e
        
        POP EBX; EBX = x / 2 + 100*(a+b) - 3 / (c + d)
        
        ADD EAX, EBX
        ADC EDX, 0;EAX:EDX = x / 2 + 100*(a+b) - 3 / (c + d) + e * e
        
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
