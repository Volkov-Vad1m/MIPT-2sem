global _start

N equ 100

section .bss

array_read: resb N
array_write: resb N

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
    mov bl, [array_read + rdx] ; в rbx кладу ascii код каждого символа
    ;тут
    call asm_test
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
    mov [array_write + rdx], bl
    add rdx, 1

    loop L0
    ret



asm_read:
    mov rax, 0
    mov rdi, 0

    mov rsi, array_read
    mov rdx, N
    syscall
    ret

asm_write:
    mov rax, 1
    mov rdi, 1
    mov rsi, array_write
    mov rdx, N
    syscall
    ret

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret

asm_test:
    cmp bl, 123
    jae break
    cmp bl, 64
    jbe break
    cmp bl, 91
    jae more_test
    ret
    more_test:
    cmp bl, 96
    jbe break
    ret
    break:
    call error
    call asm_exit
    ret

error:
    mov rax, 1
    mov rdi, 1
    mov rsi, error_message
    mov rdx, 36
    syscall
    ret
error_message: db "Error! You entered a invalid symbol", 10
