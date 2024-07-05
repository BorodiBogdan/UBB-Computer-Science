bits 32 

global start        
extern exit               

import exit msvcrt.dll    

;byte A and the word B, compute the doubleword C
segment data use32 class=data
    A db 10010000b
    B dw 1101100111011101b
    C dd 0;the result must be 11011001000001110111100111111111
                             ;11011001000001110111100111111111
    s1 db 1, 2, 0 ; null-terminated string s1
    s2 db 3, 0 ; null-terminated string s2
    len equ ($ - s1) ; length of s1+ s2
    merged_string times len db 0 ; buffer for merged string

;the bits 0-7 of C have the value 1
;the bits 8-11 of C are the same as the bits 4-7 of A
;the bits 12-19 are the same as the bits 2-9 of B
;the bits 20-23 are the same as the bits 0-3 of A
;the bits 24-31 are the same as the high byte of B

segment code use32 class=code
    start:
        MOV dword[C], 0;we put 0 in C
        OR dword[C], 0000000011111111b;the bits 0-7 of C have the value 1
        
        MOV AX, 0
        MOV AL, BYTE [A];we need to fill bits 8-11 and A is a byte so we put it in AX
        SHR AX, 4;now bits from 4-7 are on 0-3 and the rest is 0
        
        SHL AX, 8;Now bits 8-11 of AX are the same as 4-7 of A and the other bits are 0

        OR word[C], AX;now Bits 8-11 of AX are the same as 4-7 of A
        
        MOV EAX, 0
        MOV AX, word[B];So we need to keep bits 2-9 and transform the others in 0
        SHR EAX, 2;we delete bits 0, 1
        SHL EAX, 24;we delete bits 10-31 and now we have bits 2-9 on position 31-24
        SHR EAX, 12;BITS 2-9 on position 12-19
        OR DWORD[C], EAX
        
        
        MOV EAX, 0
        MOV AL,[A]
        AND AL, 00001111b
        ROL EAX, 20
        OR DWORD[C], EAX
        ;the bits 20-23 are the same as the bits 0-3 of A
        
        MOV EAX, 0
        MOV AX, WORD[B]
        AND AX, 1111111100000000b
        ;the bits 24-31 are the same as the high byte of B(8- 15)
        SHL EAX, 16
        OR DWORD[C], EAX
        
        MOV EAX, DWORD[C]
        MOV DWORD[C], EAX
        
        push    dword 0      
        call    [exit] 