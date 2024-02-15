bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
	new_string times 100 dw 0;here we store the resulting string
	format db "%d", 0
	number resd 1

segment code use32 class=code
start:
    push number
	push format
	call [scanf]
	add esp, 4 * 2

	mov ECX, dword[number];how many times we execute the loop
	mov ESI, new_string; we put in esi the adress where we want to store the even digits

	mov ESI, new_string

	my_loop:
        pushad
		push ESI
		push number
		call[scanf]
		add ESP, 4 * 2
        popad
		ADD ESI, 4
        
	loop my_loop

	push dword 0 
	call [exit] 