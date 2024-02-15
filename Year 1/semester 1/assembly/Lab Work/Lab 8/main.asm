bits 32
global start

extern exit
extern printf
extern scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data


extern printf, scanf, exit
import printf, scanf, exit msvcrt.dll

section .data
    fmt db "%s", 0
    buffer times 256 db 0

section .text
    global main
    main:
        ; call scanf to read a string from the console
        push buffer
        push fmt
        call scanf
        add esp, 8

        ; call printf to print the string
        push buffer
        push fmt
        call printf
        add esp, 8

        ; call exit to terminate the program
        push 0
        call exit