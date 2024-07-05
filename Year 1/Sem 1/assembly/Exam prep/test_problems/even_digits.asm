bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
	a dw 7
segment code use32 class=code
start:
	lea edx, [ebx >> 2 + 5]
	call [exit] 