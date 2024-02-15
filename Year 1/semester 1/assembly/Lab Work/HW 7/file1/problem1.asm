bits 32
 
global start
 
extern exit, fopen, fread, fclose, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
 
    ; 
segment data use32 class = data
    filePath db "C:\Users\Bob\Documents\FMI - YEAR 1\assembly\Lab Work\HW 7\file1\test.txt", 0
    operation db "r", 0
    vowels db "aeiouAEIOU"
    vowels_len equ $ - vowels
    message db "There are %d vowels: ", 0
    file_descriptor resd 1
    character resb 4
    result dd 0
 
    ;problem 1 lab 8
segment code use32 class = code
    start:
        push dword operation
        push dword filePath
        call [fopen];we open test.txt
        MOV [file_descriptor], EAX; we move the file descriptor from EAX
        
        add ESP, 2 * 4;we empty the stack
        ;now we need to read all characters one by one
        
        read_characters:
            push dword [file_descriptor]
            push dword 1
            push dword 1
            push dword character
            call [fread]
            add ESP, 4 * 4;we empty the stack
            ;now we should have the readen character in memory at label character
            
            CMP EAX, 0
            JE final;the file is parsed or an error occured
            
            MOV ECX, vowels_len;now we compare the character with all the vowels
            MOV ESI, vowels
            
            verify_vowels:
                MOV BL, byte[esi]
                cmp BL, [character];here we check if the character is a vowel
                JE is_vowel;It's a vowel!
                
                INC ESI
            loop verify_vowels;we continue to read
            
            jmp read_characters
            
            is_vowel:
               MOV EBX, dword [result]
               INC EBX
               MOV DWORD [result], EBX
               
        jmp read_characters   
        
        final:
        
        push dword [result]
        push dword message
        call [printf]                       ; print the message
        add esp, 4 * 2
        
 
        push    dword 0
        call    [exit]
 