global _start
N equ 8
flags equ 0x42

section .bss
var_fd: resq 1

section .text
_start:
    ; открытие файла
    mov rax, 2
    mov rdi, name
    mov rsi, flags
    syscall

    mov [var_fd], rax ; сохраняем файловый дескриптор

    mov rcx, 4
L0:
    push rcx
    call asm_write
    pop rcx

loop L0

    mov rax, 3				; close - закрыть файл
	mov rdi, [var_fd]
	syscall

    call asm_exit





asm_write_n:
    mov rax, 1
    mov rdi, [var_fd]
    mov rsi, n
    mov rdx, 1
    syscall
    ret

asm_write:
    mov rax, 1
    mov rdi, [var_fd]
    mov rsi, message
    mov rdx, N
    syscall

    call asm_write_n

    mov rax, 1
    mov rdi, [var_fd]
    mov rsi, message + 1
    mov rdx, N
    syscall

    call asm_write_n

    ret

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret

name: db    "1.txt", 0
message: db "*#*#*#*#*", 0
n: db "", 10
