
global  main

N equ 12

code_zero equ 48					; 48 это код нуля в ASCII

section .bss
    var_read:	resb N
    var_write:	resb N


section .text
main:
    call asm_read_decimal
    and rax, 1111111111111111b
    cmp rax, 0
    je zero
    call asm_write_decimal
	call asm_exit
zero:
    mov rax, 1
    mov rdi, 1
    mov rsi, remainder_is_zero
    mov rdx, 1
    syscall
    call asm_exit



asm_read_decimal:
    call asm_read
    mov r10, rax
    sub r10, 1
    xor rax, rax
    mov rcx, r10
    l_rd:
    mov ebx, 10
    mul ebx
    mov rdx, r10
    sub rdx, rcx
    xor rbx, rbx
    mov bl, [var_read + rdx]

    sub bl, code_zero
    add rax, rbx
    loop l_rd
    ret

asm_write_decimal:
    mov rcx, r10
l_wr:
    xor rdx, rdx

    mov ebx, 10
    div ebx

    add rdx, code_zero
    mov rbx, rcx
    dec rbx
    mov [var_write + rbx], dl
    loop l_wr

    ; правильная печать чтоб в начале не было нулей
    xor r11, r11
L1:
    mov dl, [var_write + r11]
    inc r11
    cmp dl, code_zero
    je L1

    dec r11
    call asm_write
    ret

asm_read:
    mov rax, 0
    mov rdi, 0
    mov rsi, var_read
    mov rdx, N
    syscall
    ret

asm_write:
    mov rax, 1
    mov rdi, 1
    lea rsi, [var_write + r11]
    mov r12, r10
    sub r12, r11
    mov rdx, r12
    syscall
    ret

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret

remainder_is_zero:
    db "0", 0
