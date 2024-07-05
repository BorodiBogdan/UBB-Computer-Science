bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
    sir dd 1234A678h, 12785634h, 1A4D3C28h
    finall db 0;when we are here the loop ends
    word_string times 1000 dw 0
    format db "%d", 0

segment code use32 class=code
start:
    mov ESI, sir
    mov EDI, word_string
    mov EBX, 0;we store in EBX the sum of 1's

    my_loop:
        lodsd;EAX double word from sir
        ;we will store the higher parth of the higher double word in byte[esi + 1]
        ;higher part of the lower part in byte[esi](AH)
        ;we do this because of little endian

        mov byte[edi], AH

        ;we shift the bits 16 positions because we want the higher part of the higher word on Ah(to be able to acces it)
        SHR EAX, 16

        mov byte[edi + 1], AH

        MOV AX, word[EDI];we want to compute how many 1's
        mov ECX, 16

        While:
            SHR AX, 1
            ADC EBX, 0;if we have a one, then the carry flag is 1 also
        loop While

        ADD EDI, 2

        mov AL, byte[ESI];we check if the loop is done
        cmp AL, 0
        jz final

    jmp my_loop
    final:

    push EBX
    push format
    call[printf]
    add esp, 4 * 2

	push dword 0 
	call [exit] 