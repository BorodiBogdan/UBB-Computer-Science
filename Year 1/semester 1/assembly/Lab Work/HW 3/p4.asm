bits 32 ; assembling for the 32 bits architecture


global start        

extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;(d-a)-(a-c)-d
;a - byte, b - word, c - double word, d - qword - Signed representation
segment data use32 class=data
    a db 7
    c dd -240
    d dq -1000

;(d-a)-(a-c)-d
segment code use32 class=code
    start:
        MOV AL, [a]
        cbw
        cwd
        
        PUSH DX
        PUSH AX
        POP EBX
        
        MOV EAX, dword [d]
        MOV EDX, dword [d + 4]
        
        SUB EAX, EBX
        SBB EDX, 0;EDX:EAX d - a
        
        PUSH EDX
        PUSH EAX;saving d - a on the stack
        
        MOV AL, [a]
        cbw
        cwd
        
        PUSH DX
        PUSH AX
        POP EAX;a
        
        cdq
        
        SUB EAX, [c]
        SBB EDX, 0;a - c
        
        MOV EBX, EAX
        MOV ECX, EDX;ECX:EBX a - c
        
        POP EAX
        POP EDX;EAX:EDX d - a
       
       SUB EAX, EBX
       SBB EDX, ECX
       
       SUB EAX, dword[d]
       SBB EDX, dword[d + 4]
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
