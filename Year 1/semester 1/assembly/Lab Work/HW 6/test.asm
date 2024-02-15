bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    v dw 0AAh, 5566h
segment code use32 class=code
start:
    MOV eax, -1
    MOV edx, -1
    push ax
    push dx
	push dword 0 
	call [exit] 