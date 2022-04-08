global _start

size_byte equ 8
N equ 100

section .bss

symbol_read: resb N
symbol_write: resb N

section .text
_start:
    call asm_read
    call asm_work

    call asm_write
    call asm_exit

asm_work:
    mov rcx, N
    xor rdx, rdx ; rdx = 0
    L0:
    mov bl, [symbol_read + rdx] ; в rbx кладу ascii код каждого символа
    ;тут

    cmp bl, 93
    ja L1
    jb L2
    L1:
    sub bl, 32
    jmp leave
    L2:
    add bl, 32
    leave:

    ;тут
    mov [symbol_write + rdx], bl
    add rdx, 1

    loop L0
    ret



asm_read:
    mov rax, 0
    mov rdi, 0

    mov rsi, symbol_read
    mov rdx, N
    syscall
    ret

asm_write:
    mov rax, 1
    mov rdi, 1
    mov rsi, symbol_write
    mov rdx, N
    syscall
    ret

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret
