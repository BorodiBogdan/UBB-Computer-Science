bits 32
global start

extern exit, printf, scanf

import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

;problem 1
;%d -> decimal
;%x -> 16
;scanf(%d, %x)
segment data use32 class=data
    message_for_a db "a = ", 0
    message_for_b db "b = ", 0
    result_message db "a * b = %lld", 0
    format db "%d", 0
    a dd 0FFFFFFFFh
    b dd 0FFFFFFFFh
    result resq 1

segment code use32 class=code
start:
    push dword message_for_a
    call [printf]
    add esp, 4 * 1;print message for a
    
    push dword a
    push dword format
    call [scanf];read a from console
    
    add esp, 2 * 4
    
    push dword message_for_b;print message for bits
    call[printf]
        
    add esp, 4 * 1
    
    push dword b
    push dword format
    call [scanf];reading b from console
    
    add esp, 4 * 2
    
    MOV eax, [a]
    MOV ebx, [b]
    mul ebx;we have a * b in edx:eax
    
    MOV [result], eax
    MOV [result + 4], edx;we have a * b in result
    
    ;now we need to display the result
        
    push dword [result + 4]
    push dword [result]
    push dword result_message
    call [printf]
    
    
	push dword 0 
	call [exit] 