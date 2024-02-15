bits 32 

global start        

extern exit              

import exit msvcrt.dll    


segment data use32 class=data
    A dw 1011000111101010b
    B dw 1111000010101100b
    C dd 0

;Given the words A and B, compute the doubleword C as follows:
;the bits 0-4 of C are the same as the bits 11-15 of A
;the bits 5-11 of C have the value 1
;the bits 12-15 of C are the same as the bits 8-11 of B
;the bits 16-31 of C are the same as the bits of A
;the result must be 1011 0001 1110 1010 0000 1111 1111 0110
                   ;1011 0001 1110 1010 0000 1111 1111 0110
                   
segment code use32 class=code
    start:
        MOV EAX, 3
        MOV dword[C], 0
        
        MOV EBX, 0
        MOV BX, word[A]
        SHR BX, 11
        MOV EAX, dword[C]
        OR EAX, EBX;the bits 0-4 of C are the same as the bits 11-15 of A
        
        MOV EBX, 0
        MOV EBX, 1111111b
        SHL EBX, 5
        OR EAX, EBX;the bits 5-11 of C have the value 1
        
        MOV EBX, 0
        MOV BX, word[B]
        SHL BX, 4
        SHR BX, 12
        SHL BX, 12
        
        OR EAX, EBX;the bits 12-15 of C are the same as the bits 8-11 of B
        
        MOV EBX, 0
        MOV BX, word[A]
        SHL EBX, 16
        OR EAX,EBX
        
        MOV dword[C], EAX
        
        push    dword 0      
        
        call    [exit]       ; call exit to terminate the program
