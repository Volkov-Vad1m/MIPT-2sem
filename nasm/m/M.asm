global _start


N equ 8

section .bss

array: resb N
array1: resb N

section .text
_start:
    call asm_read
    mov bl, [array]
    cmp bl, 45
    je negativ
    call asm_write_positiv
    call asm_exit
negativ:
    call asm_write_negativ
    call asm_exit



asm_read:
    mov rax, 0
    mov rdi, 0

    mov rsi, array
    mov rdx, N
    syscall
    ret

asm_write_positiv:
    mov rax, 1
    mov rdi, 1
    mov rsi, array
    mov rdx, N
    syscall
    ret
asm_write_negativ:
    mov rax, 1
    mov rdi, 1
    mov rsi, array + 1
    mov rdx, N
    syscall
    ret

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret
