%macro asm_read 1  ; arg - куда считываем
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, N
    syscall
    %endmacro

%macro asm_read_decimal 3 ; куда считываем, размер числа, само число
    asm_read %1


    mov %2, rax
    dec %2
    xor rax, rax
    mov rcx, %2
    l_rd%1:
    mov ebx, 10
    mul ebx
    mov rdx, %2
    sub rdx, rcx
    xor rbx, rbx
    mov bl, [%1 + rdx]

    sub bl, code_zero
    add rax, rbx
    loop l_rd%1
    mov %3, rax
    %endmacro

global _start
N equ 8
code_zero equ 48

section .bss
number: resb N

section .text
_start:
    asm_read_decimal number, r8, r15 ; в r15 - номер числа фибоначи
    mov rcx, r15
    mov rax, 1
    mov rbx, 1
L0:
    add rax, rbx
                
    loop L0

    call asm_exit





;//////////
asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret
