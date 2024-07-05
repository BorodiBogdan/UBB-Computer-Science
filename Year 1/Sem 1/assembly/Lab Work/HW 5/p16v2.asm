bits 32
global start

extern exit
import exit msvcrt.dll

;Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements found on odd positions in S2 and the elements found on even positions in S1.
;Example.|.:
;S1: 'a', 'b', 'c', 'b', 'e', 'f'
;S2: '1', '2', '3', '4', '5'
;D: '1', '3', '5', 'b', 'b', 'f'
segment data use32 class=data
    S1 db 'a', 'b', 'c', 'b', 'e', 'f', 'g'
    l_S1 equ $ - S1
    S2 db '1', '2', '3', '4', '5', '6', '7'
    l_S2 equ $ - S2
    D times ((l_S1 / 2) + ((l_S2 + 1) / 2)) db 0

segment code use32 class=code
start:
    MOV ECX, (l_S2 + 1) / 2; ECX = number of elements in S1 to be added

    JECXZ end_for1; if ECX = 0, jump to end_for1
        MOV ESI, 0; ESI = index in S1
        MOV EAX, S2
        MOV EDX, D

        While:
            MOV BL, [EAX + ESI * 2]
            MOV BYTE [EDX + ESI], BL
            INC ESI
        loop While


    end_for1:

    MOV ECX, l_S1 / 2; ECX = number of elements in S2 to be added

    JECXZ end_for2; if ECX = 0, jump to end_for1
        MOV ESI, 0; ESI = index in S2
        MOV EAX, S1 + 1
        MOV EDX, D + (l_S2 + 1) / 2
        
        While2:
            MOV BL, [EAX + ESI * 2]
            MOV BYTE [EDX + ESI], BL
            INC ESI
        loop While2


    end_for2:

	push dword 0 
	call [exit] 