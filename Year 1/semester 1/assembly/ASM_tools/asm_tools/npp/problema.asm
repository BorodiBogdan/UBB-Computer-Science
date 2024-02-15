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
    filePath db "test.txt"
    operation db "r"
    vowels db "aeiouAEIOU"
    message db "There are %d vowels: "
    vowels_len equ $ - vowels
    file_descriptor resd 1
    character resb 4
    result db 0
 
    ; 1). Se da un fisier text. Sa se citeasca continutul fisierului, sa se contorizeze numarul de vocale si sa se afiseze aceasta valoare. Numele fisierului text este definit in segmentul de date.
segment code use32 class = code
    start:
        push dword operation
        push dword filePath
        call [fopen];we open test.txt
        mov [file_descriptor], EAX; we move the file descriptor from EAX
        
        add ESP, 2 * 4;we empty the stack
        ;now we need to read all characters one by one
        
        read_characters:
            push dword [file_descriptor]
            push 1
            push 1
            push dword character
            add ESP, 4 * 4;we empty the stack
            ;now we should have the readen character in memory at label character
            
            CMP EAX, 0
            JE final;the file is parsed or an error occured
            
            MOV ECX, vowels_len;now we compare the character with all the vowels
            MOV ESI, vowels
            
            verify_vowels:
                mov BL, byte[esi]
                cmp byte[character], BL;here we check if the character is a vowel
                JZ is_vowel;It's a vowel!
                
                INC ESI
            loop verify_vowels;we continue to read
            
            jmp read_characters
            
            is_vowel:
               mov BL, [result]
               INC BL
               MOV [result], BL
               
        jmp read_characters    
        final:
        
        push dword [result]
        push dword message
        call [printf]                       ; print the message
        add esp, 4 * 2
        
 
        push    dword 0
        call    [exit]
 