bits 32
global write_in_file

extern fopen, fprintf, fclose


import fclose msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll

segment data use32 class=data
    filePath db "max.txt", 0
    operation db "w", 0
    file_descriptor resd 1
    ret_file resd 1
    value_to_be_printed dd 0
    display_message db "Valoarea maxima din sir este: %x", 0

write_in_file:
    pop dword [ret_file]
    pop dword [value_to_be_printed]

    ;----------here we open the file ------------------------------
    push dword operation
    push dword filePath
    call [fopen];we open test.txt
    MOV [file_descriptor], EAX; we move the file descriptor from EAX
    add ESP, 4 * 3
    ;----------------------------------------------------------------

    CMP EAX, 0
    JZ error1;If EAX is 0 the file is not successfully open

    ;-------------Here we print the value---------------------------
    push dword[value_to_be_printed]
    push display_message
    push dword [file_descriptor]
    call [fprintf]
    ADD ESP, 4 * 2;We empty the stack
    ;---------------------------------------------------------------


    ;-------------Here we close the file---------------------------
    push dword [file_descriptor]
    call [fclose]
    ADD ESP, 4 * 1
    ;--------------------------------------------------------------

    error1:

	push dword [ret_file];we need ret to function
	ret