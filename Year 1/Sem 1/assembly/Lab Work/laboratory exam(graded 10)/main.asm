bits 32
global start

extern exit, fscanf, scanf, fopen, fclose, printf, fprintf, fclose

import exit msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fclose msvcrt.dll

segment data use32 class=data
    newline db 10, 0
    sum_of_grades_message db "Sum of grades is: ", 0
    difference_of_grades db "The difference of grades is: ", 0
    file_name db "test.txt", 0;acesta este fisierul din care citim
    acces_mode db "r+", 0
    decimal_format db "%d", 0
    grade resd 10
    file_descriptor resd 10
    sum_of_grades resd 10
    first_grade resd 10

segment code use32 class=code
start:
    push acces_mode
    push file_name
    call [fopen]
    add esp, 4 * 2
    mov dword [file_descriptor], EAX
    ;mai sus am deschis fisierul din data segment si am golit stiva

    my_loop:
        push grade
        push decimal_format
        push dword[file_descriptor]
        call [fscanf]
        add esp, 4 * 3
        ;am citit gradeul
        
        cmp EAX, -1
        jz final;inseamna ca nu a mai citit nimic

        ;tinem minte primul grade pentru a calcula mai usor diferenta
        MOV EAX, dword[first_grade]
        cmp EAX, 0
        JNE sari_peste;daca nu e 0 am citit primul grade
            mov EAX, dword[grade]
            mov dword[first_grade], EAX
        sari_peste:

        mov EAX, dword[grade]
        mov EBX, dword[sum_of_grades]
        ADD EBX, EAX;;adunam gradeul la suma
        MOV dword[sum_of_grades], EBX;tinem minte suma in memorie
    jmp my_loop
    final:

    push newline
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 * 2   
    ;punem newline

    push sum_of_grades_message
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 * 2
    ;afisam mesajul pentru a stii ce cerinta am rezolvat

    push dword[sum_of_grades]
    push decimal_format
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 * 3
    ;am afisat si suma notelor

    push newline
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 * 2   
    ;punem newline iarasi

    push difference_of_grades
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 * 2
    ;afisam mesajul pentru diferenta notelor
    ;aici calculam diferenta
    ;scadem din primul grade * 2 suma tuturor gradeurilor
    ;->rezulta diferenta

    mov EAX, dword[first_grade]
    MOV ecx, 2
    mul ECX
    MOV EBX, dword[sum_of_grades]
    SUB EAX, EBX

    ;mai jos afisam diferenta
    push EAX
    push decimal_format
    push dword[file_descriptor]
    call [fprintf]
    add esp, 4 *3
    ;problema e gata!

    push dword[file_descriptor]
    call [fclose]
    add esp, 4 * 1
    ;am inchis fisierul
    
	push dword 0 
	call [exit] 