bits 32
global start

extern exit, scanf, printf
extern write_in_file;thats the module we created


import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll

;Read a string of unsigned numbers in base 10 from keyboard. 
;Determine the maximum value of  the string and write it in the file max.txt (it will be created) in 16  base.
segment data use32 class=data
    input_message db "Enter the number of integers from the string: ", 0
    format db "%d", 0
    number_of_integers dd 0
    max_value dd 0
    integer dd 0

segment code use32 class=code
start:
    cld

    ;-----------Here we read the number of integers------------------
    push input_message
    call [printf]
    add ESP, 4 * 1; We empty the stack

    push number_of_integers
    push format
    call [scanf]
    add ESP, 4 * 2;We empty the stack

    MOV ECX, [number_of_integers];we read n numbers
    ;-----------------------------------------------------------------

    
    my_loop:
        ;In case we read a value lower then 0
        MOV EAX, [number_of_integers]
        CMP EAX, 0
        JLE final
        DEC EAX
        MOV [number_of_integers], EAX
        
        
        ;-------we read the integer--------
        push integer
        push format
        call [scanf]
        add ESP, 4 * 2;We empty the stack
        ;--------------------------------

        ;--------we find the max value----------
        MOV EAX, [integer]
        CMP EAX, [max_value]

        JL my_loop;In case the integer is smaller then the max_value we start again

        MOV [max_value], EAX;we update the max value
        ;---------------------------------------

    JMP my_loop

    final:  

    push dword [max_value]
    call write_in_file;here we call our module(check module.asm)

	push dword 0 
	call [exit] 