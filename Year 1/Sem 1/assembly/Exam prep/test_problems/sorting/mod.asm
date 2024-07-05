bits 32
global sortare

segment data use32 class=data
    len db 0

segment code use32 class=code
sortare:

    mov ESI, [esp + 4]
    mov CL, byte [esp + 8]
    mov byte [len], CL
    MOV CL, 0

    my_loop:
        mov EDI, ESI
        MOV CH, CL

        second_loop:
            mov EAX, dword[ESI]
            cmp EAX, dword[EDI]
            
            jng not_swap
                mov EAX, dword[ESI]
                mov EDX, dword[EDI]
                mov dword[EDI], EAX
                mov dword[ESI], EDX
            not_swap:

            add EDI, 4
            INC CH
            cmp CH, [len]
            jz end_second_loop
        jmp second_loop 
        end_second_loop:

        ADD ESI, 4
        INC CL
        cmp CL, [len]
        jz end_my_loop
    jmp my_loop
    end_my_loop:
    
    ret 8