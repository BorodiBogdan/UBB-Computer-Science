bits 32

global _base10
; linkeditorul poate folosi segmentul public de date si pentru date din afara
segment data public data use32
    
segment code public code use32

_base10:
    ; creare cadru de stiva pentru programul apelat
    PUSH ebp
    MOV ebp, esp
    MOV esi, [ebp + 8];Here we have our number in base 2
	CLD ;In order to parse correctly
	MOV edx, 0
	MOV eax, 0

	compute_number:
		LODSB;we load the string
		CMP al, 0
		JZ final ;we parsed the entire string
		SUB al, '0'
		SHL edx, 1
		ADD edx, eax
		JMP compute_number ;we go for the next digit		
	final:

	MOV eax, edx
	MOV esp, ebp
    POP ebp
    RET ;we are done