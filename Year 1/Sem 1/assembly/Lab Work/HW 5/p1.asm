bits 32 

global start        

extern exit              
import exit msvcrt.dll    

segment data use32 class=data
    S db 1, 2, 3, 4
    l equ $ - S - 1
    multiplier db 0
    D times l * 2 db 0

    
; Given a byte string S of length l, obtain the string D of length l-1 as:
;D(i) = S(i) * S(i+1) (each element of D is the product of two consecutive elements of S)
segment code use32 class=code
    start:
        MOV ECX, l;How many times it loops
        
        MOV esi,0; index
        
        jecxz End
       
        While:;this is the loop
            
            MOV AL, [S + esi]
            MOV BL, [S + esi + 1]
            MOV byte[multiplier], BL
            
            mul byte[multiplier];S(i) * S(i + 1)
            MOV [D + esi * 2], AX;moving S(i) * S(i + 1) in D
            inc ESI
            
        loop While
        
        
        End:;End of the program

    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
