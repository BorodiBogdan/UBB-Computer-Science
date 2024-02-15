bits 32

global start        

extern exit              
import exit msvcrt.dll    

;Given the word A and the byte B, compute the doubleword C:
;the bits 0-3 of C have the value 1
;the bits 4-7 of C are the same as the bits 0-3 of A
;the bits 8-13 of C have the value 0
;the bits 14-23 of C are the same as the bits 4-13 of A
;the bits 24-29 of C are the same as the bits 2-7 of B
;the bits 30-31 have the value 1

segment data use32 class=data
    a dw 1001100110011101b
    b db 11001100b
    c dd 0

; our code starts here
segment code use32 class=code
    start:
        OR dword[c], 1111b;the bits 0-3 of C have the value 1
        
        MOV EAX, 0
        MOV AX, word[a]
        AND EAX, 1111b
        SHL EAX, 4
        OR dword[c], EAX;the bits 4-7 of C are the same as the bits 0-3 of A     
        
        ;the bits 8-13 of C have the value 0 ---->that s ok because c is initialised with 0
        
        MOV EAX, 0
        MOV AX, word[a]
        AND EAX, 11111111110000b
        SHL EAX, 10
        OR dword[c], EAX;the bits 14-23 of C are the same as the bits 4-13 of A
              
        MOV EAX, 0
        MOV AL, byte[b]
        SHR AL, 2
        SHL EAX, 24
        OR dword[c], EAX;the bits 24-29 of C are the same as the bits 2-7 of B
    

        MOV EAX, 0
        MOV EAX, 11b
        SHL EAX, 30
        OR dword[c], EAX;the bits 30-31 have the value 1
        
        MOV EAX, dword[c]
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
