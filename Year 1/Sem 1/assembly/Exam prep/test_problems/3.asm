bits 32
global start

extern exit, printf, scanf
import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll

segment data use32 class=data
    sir dd 1, 6 ,3 , 3,4, 32, 3,1321,1312,231 ,123 ,432, 312
    len equ ($ - sir) / 4
    format db "%d ", 0
segment code use32 class=code
start:
    
    MOV CL, 0
    mov ESI, sir

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
            cmp CH, len
            jz end_second_loop
        jmp second_loop 
        end_second_loop:

        ADD ESI, 4
        INC CL
        cmp CL, len
        jz end_my_loop
    jmp my_loop
    end_my_loop:


    mov ESI, sir
    mov ECX, len

    While:
        pushad
        push dword[ESI]
        push format
        call[printf]
        add esp, 4 * 2
        popad
        add ESI, 4
    loop While

	push dword 0 
	call [exit] 