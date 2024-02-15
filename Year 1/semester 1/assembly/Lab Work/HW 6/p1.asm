bits 32
global start

;The following exercises need to be solved using specific string instructions: LODSB, STOSB, MOVSB, SCASB, CMPSB, LODSW, STOSW, MOVSW, SCASW, CMPSW, LODSD, STOSD, MOVSD, SCASD, CMPSD.
; An array with doublewords containing packed data (4 bytes written as a single doubleword) is given. 
;Write an asm program in order to obtain a new array of doublewords, where each doubleword will be composed 
;by the rule: the sum of the bytes from an odd position will be written on the word from the odd position and the 
;sum of the bytes from an even position will be written on the word from the even position. The bytes are considered 
;to represent signed numbers, thus the extension of the sum on a word will be performed according to the signed arithmetic.

extern exit
import exit msvcrt.dll

segment data use32 class=data
    array dd 127F5678h, 0ABCDABCDh
    len equ ($-array) / 4 ;lenght of the array
    resulting_array times (len * 2) dd 0;we reserve space for the resulting array
    sum_odd dw 0;we will use this to store the sum of the bytes
    sum_even dw 0;we will use this to store the sum of the bytes
    aux dd 0;we will use this to store the sum of the bytes
    ;result 006800F7h, 0FF56FF9Ah
segment code use32 class=code
start:
    MOV ECX, len;How many times we will do the operation
    MOV ESI, array;Source
    MOV EDI, resulting_array;Destination
    cld;Clear direction flag(parse the string from left to right)

    JECXZ end_loop

        start_loop:
            LODSD;now we have the doubleword DS:ESI in EAX and ESI is incremented by one
            
            MOV [aux], EAX;we will use EBX to store the doubleword

            cbw;we extend the sign of the byte in AL to the word in AX
            MOV [sum_odd], AX;we store the sum of the bytes in the word
        
            MOV AL, BYTE[aux + 2];we move the byte from the third position in AL
            
            cbw
           
            add [sum_odd], AX;we add the byte to the sum of the bytes
            
            MOV AL, BYTE [aux + 1];we move the byte from the second position in AL
            cbw

            MOV [sum_even], AX;we store the sum of the bytes in the word
         
            MOV AL, BYTE [aux + 3];we move the byte from the second position in AL
            cbw
           
            add [sum_even], AX;we add the byte to the sum of the bytes    

            MOV AX, word [sum_even];we move the sum of the bytes on the odd position
            shl EAX, 16
            MOV AX, word [sum_odd];we move the sum of the bytes on the even position

            STOSD;now we have the doubleword in EAX and EDI is incremented by one
        loop start_loop

    end_loop:
    cld;recommended
    
	call [exit] 