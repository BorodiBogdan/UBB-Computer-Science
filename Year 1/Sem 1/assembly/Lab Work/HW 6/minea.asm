bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s db 5, 25, 55, 127
    len equ $ - s
    result times len db 0

segment code use32 class=code
start:
    MOV ECX, len
    MOV ESI, s
    MOV EDI, result

    JECXZ final;if the string is empty

        While:;we start the loop to iterate through every byte
            LODSB;AL -> DS:ESI and afte INC ESI
            MOV AH, 0;here we keep the number of ones

            not_done:
                SHR AL, 1; we have 1 in the carry flag if the last bit is one
                ADC AH, 0
                CMP AL, 0;AL = 0 - Al, but we change only the flags
            JNZ not_done;jump to not_done if AL is not 0

            MOV AL, AH
            STOSB;mov AL at ES:EDI and increment EDI

        loop While

    final:

	push dword 0 
	call [exit] 