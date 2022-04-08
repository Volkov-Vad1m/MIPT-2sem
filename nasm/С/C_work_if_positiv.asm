%macro asm_read 1  ; arg - куда считываем
    mov rax, 0
    mov rdi, 0
    mov rsi, %1
    mov rdx, N
    syscall
    %endmacro

%macro asm_read_decimal 3 ; куда считываем, размер числа, само число
    asm_read %1

	jmp asm_exit
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

%macro asm_write 3 ; массив который печатаем, размер максимального числа, кол-во ведущих нулей(default r11)
    mov rax, 1
    mov rdi, 1
    lea rsi, [%1 + %3]
    mov r12, %2
    sub r12, %3
    mov rdx, r12
    syscall
    %endmacro

%macro asm_write_decimal 3 ; массив который печатаем, размер максимального числа, кол-во ведущих нулей(default r11)
    mov rcx, %2
    l_wr%2:
    xor rdx, rdx

    mov ebx, 10
    div ebx

    add rdx, code_zero
    mov rbx, rcx
    dec rbx
    mov [%1 + rbx], dl
    loop l_wr%2

    ; правильная печать чтоб в начале не было нулей
    xor %3, %3
    L%2:
    mov dl, [%1 + %3]
    inc %3
    cmp dl, code_zero
    je L%2

    dec %3
    asm_write %1, %2, %3
    %endmacro


global _start
N equ 12
code_zero equ 48
section .bss
    x: resb N
    y: resb N
    answer: resb N

section .text
_start:
; в r14 будет x в r15 -  y
; в r8 размер x в r9 - размер y

    asm_read_decimal x, r8, r14 ; после макроса в r8 будет размер числа, r14 - само число
    asm_read_decimal y, r9 , r15
    ; we readed numbers and start working with them
    cmp r14, r15
    je equally
    jg x_is_greater_than_y

    sub r15, r14
    asm_write minus, 1, 0
    mov rax, r15
    asm_write_decimal answer, r9, r11
    call asm_exit

x_is_greater_than_y:
    sub r14, r15
    mov rax, r14
    asm_write_decimal answer, r8, r11
    call asm_exit

equally:
    asm_write zero, 1, 0
    call asm_exit



;//////////////////////////////////////////////////

asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret

asm_write_minus:
    mov rax, 1
    mov rdi, 1
    mov rsi, minus
    mov rdx, 1
    syscall
    ret

minus:
    db "-", 1

zero:
    db "0", 0
