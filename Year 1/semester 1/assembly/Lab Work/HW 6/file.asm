bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    s1 db 1, 2, 3, 0 ; null-terminated string s1
    s2 db 1, 6, 7, 8, 0 ; null-terminated string s2
    len equ ($ - s1) ; length of s1+ s2
    merged_string times len db 0 ; buffer for merged string
    endd db 0


segment code use32 class=code
start:
; Initialize registers
    MOV ESI, s1 ; source index for s1
    MOV EDI, s2 ; source index for s2
    MOV EBX, merged_string ; destination index for merged string
    cld ; clear direction flag
    ; Merge the strings
    While:
        CMP byte [EDI], 0
        JZ End_loop
        CMP byte [ESI], 0
        JZ End_loop1

        CMPSB ; compare byte at [esi] with byte at [edi]
        ; If the bytes are equal, jump to the end of the loop
        JAE add_second;here we add the first string to the result
            dec EDI
            dec ESI;esi and edi were incremented by cmpsb

            LODSB ; load byte at [ds:esi] into AL and increment esi
            
            MOV [ebx], al ; move byte from AL to [ebx] and increment ebx
            INC ebx ; increment ebx
        JMP end_condition
        add_second:
            dec EDI
            dec ESI;esi and edi were incremented by cmpsb
            MOV AL, byte [EDI] ; move byte from [edi] to AL
            MOV [ebx], al ; move byte from AL to [ebx] and increment ebx
            INC ebx ; increment ebx
            inc EDI
        end_condition:
    loop While

    End_loop:
    End_loop1:

    ;now the only thing that is left is to add the rest of the strings
    ;if one of the strings is empty, we add the other one


    
   

 
	push dword 0 
	call [exit] 