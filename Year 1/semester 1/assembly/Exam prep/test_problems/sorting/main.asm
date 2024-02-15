bits 32
global start

extern exit, printf, scanf
import printf msvcrt.dll
import exit msvcrt.dll
import scanf msvcrt.dll

extern sortare

segment data use32 class=data
    sir dd 123,123,21321,3,21,123,12,23,4, 12, 23, 32,5,
    a dd ($ - sir) / 4
    format db "%d "
    len db 0

segment code use32 class=code
start:
    push dword[a]
    push sir
    call sortare

    mov esi, sir

    mov ECX, dword[a]

    afisare:
        pushad
        push dword[ESI]
        push format
        call [printf]
        add esp, 4 * 2
        popad
        ADD ESI, 4

    loop afisare

    push ESI
    push format
    call [scanf]
    add esp, 4 * 2

	push dword 0 
	call [exit] 