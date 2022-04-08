global _start

section .bss
var: resb 1

section .text
_start:
    mov eax, 3
    xor ebx, ebx
    mov ecx, var
    mov edx, 1
    int 0x80

    mov al, [var]
    or al, 00000111b
    mov [var], al

    mov eax, 4
    mov ebx, 1
    mov ecx, var
    mov edx, 1
    int 0x80

    
    call asm_exit

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret