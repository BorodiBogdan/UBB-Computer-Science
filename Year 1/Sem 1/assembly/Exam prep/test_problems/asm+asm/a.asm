bits 32
global start

extern exit, printf, scanf
import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll


extern cdecl

segment data use32 class=data
    sir dd -1, 123456, 0xabcdeff, 0xabcdeff, 0xdbcdeff, 0111010101b
    len equ ($ - sir) / 4
    sum_sir resd 100
    format db "%d ", 0

segment code use32 class=code
start:
    mov ax, 5
    mov bl, 0
    div bl

	push dword 0 
	call [exit] 