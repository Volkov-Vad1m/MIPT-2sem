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
    mov ebx, [var2]
    cmp eax, ebx
    jg var1_var2
    mov rdi, format2
    mov esi, [var1]
    xor rax, rax
    call printf
    xor rax, rax
    ret
var1_var2:
    mov rdi, format2
    mov esi, [var2]
    xor rax, rax
    call printf
	xor rax, rax
	ret

format1: db "%d %d", 0

format2: db "%d", 0
