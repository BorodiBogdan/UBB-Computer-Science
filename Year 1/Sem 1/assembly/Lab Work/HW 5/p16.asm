bits 32 
global start
extern exit 

import exit msvcrt.dll  

;Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements found on odd positions in S2 and the elements found on even positions in S1.
;Example:
;S1: 'a', 'b', 'c', 'b', 'e', 'f'
;S2: '1', '2', '3', '4', '5'
;D: '1', '3', '5', 'b', 'b', 'f'
segment data use32 class=data
    S1 db 'a', 'b', 'c', 'b', 'e', 'f'
    l_S1 equ $ - S1
    S2 db '1', '2', '3', '4', '5'
    l_S2 equ $ - S2
    S3 times (l_S1 / 2 + (l_S2 + 1) / 2) db 0
    displacementOfS1 equ (l_S2 + 1) / 2
    a db 3
segment code use32 class=code
start:
    MOV AL, l_S1 / 2;moving the length of S1 to AL
    CMP Al, (l_S2 + 1) / 2;Comparing l_S1 to l_S2 and setting the appropriate flags
    ;if the carry flag is set to one, then length of S1 is smaller then S2

    ;we want to move in EXC max(l_S1, l_S2)
    JC FirstIsSmaller;if l_S1 / 2 < (l_S2 + 1) / 2 we go to FirstIsSmaller to MOV in ECX l_S2 else we execute the next line
        MOV ECX, l_S1 / 2;
    jmp End;we go to End because we already moved in ECX max(l_S1, l_S2)
    FirstIsSmaller:
        MOV ECX, (l_S2 + 1) / 2;l_S1 > (l_S2 + 1) / 2 so we move (l_S2 + 1) / 2 in ECX
    End:

    JECXZ EndOFLoop;if ECX is 0 don't execute the loop

    MOV ESI, 0;index to 0

    While:;here we loop ECX times

    CMP ESI, displacementOfS1

    JAE Add_From_S2;we jump here if we do not add items
        MOV AL, byte [S2 + esi * 2]
        MOV byte [S3 + esi], AL;add new item
    Add_From_S2:
    
    CMP ESI, l_S1 / 2

    JAE Add_From_S1;we jump here if we do not add items
        MOV AL, byte [S1 + esi * 2 + 1]
        MOV byte [S3 + esi + displacementOfS1], AL;add new item
    Add_From_S1:

    INC ESI;we increment the index

    loop While

    EndOFLoop:

	push dword 0 ; saves on stack the parameter of the function exit
	call [exit] ; function exit is called in order to end the execution of the program