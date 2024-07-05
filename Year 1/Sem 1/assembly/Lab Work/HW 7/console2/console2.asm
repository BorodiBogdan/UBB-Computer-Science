bits 32 ; assembling for the 32 bits architecture

global start        

extern exit, scanf, printf          
import exit msvcrt.dll    
import scanf msvcrt.dll
import printf msvcrt.dll

;18
segment data use32 class=data
    message1 db "Enter the number in base 10: ", 0
    message2 db "Enter the number in base 16: ", 0
    message3 db "The number of 1's of the sum of the two numbers is: %d", 0
    format_base_10 db "%d", 0
    format_base_16 db "%x", 0
    number_in_base_10 dd 0
    number_in_base_16 dd 0
    number_of_ones db 0

segment code use32 class=code
    start:
      push dword message1
      call [printf]
      add esp, 1 * 4;we clear the stack
      
      push number_in_base_10
      push format_base_10
      call[scanf]
      add esp, 2 * 4;we clear the stack
      ;we read the numbr in base 10, so we need to read the number in base 16
      
      push dword message2
      call [printf]
      add esp, 1 * 4
      
      push dword number_in_base_16
      push dword format_base_16
      call [scanf]
      add esp, 2 * 4
      ;we have read the number in base 16
      ;now we need to compute the sum in order to find how many 1's are in the representation
      
      MOV eax, [number_in_base_10]
      MOV ebx, [number_in_base_16]
      add eax, ebx;we computed the sum
      
      while:
        shr eax, 1
        adc byte [number_of_ones], 0
        cmp eax, 0
      jnz while
      ;in byte [number_of_ones] we store how many 1's we have
        
      
      push dword [number_of_ones]
      push dword message3
      call [printf]
      add esp, 4 * 1
      
      
        push    dword 0      
        call    [exit]
