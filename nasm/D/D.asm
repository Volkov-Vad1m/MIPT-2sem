global main
extern printf
extern scanf

section .bss
var1: resd 1
var2: resd 1

section .text
main:

    mov rdi, format1
    mov rsi, var1
    mov rdx, var2
    xor rax, rax
	call scanf
    mov eax, [var1]
    cdq
    mov ebx, [var2]

    idiv ebx

    mov [var1], edx

    mov rdi, format2
    mov esi, [var1]
    xor rax, rax
    call printf

	call asm_exit

format1: db "%d %d", 0

format2: db "%d", 0


asm_exit:
    
    mov rax, 60
    xor rdi, rdi
    syscall
    ret
