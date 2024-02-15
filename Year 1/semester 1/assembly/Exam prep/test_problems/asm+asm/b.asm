bits 32
segment code use32 public code
global cdecl

cdecl:
    mov ESI, [ESP + 4]
    mov EDI, [esp + 8]
    mov ecx, [esp + 12]

    JECXZ final
        my_loop:
            LODSD
            MOV EBX, 0

            compute_sum:
                push EBX
                MOV EBX, 16
                MOV EDX, 0
                DIV EBX
                POP EBX
                ADD EBX, EDX
                CMP EAX, 0
                jz end_compute_sum
            jmp compute_sum
            end_compute_sum:

            MOV EAX, EBX
            STOSD 
        loop my_loop
    final:

    ret 12

