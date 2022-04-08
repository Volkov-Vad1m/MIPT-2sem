global _start

N equ 4
code_zero equ 48

section .bss
var: resb N

section .text
_start:

    xor rax, rax
    call func   
    mov [var], eax ; кладём в переменную то, что вернула функция.
    

    call asm_write_decimal ; проверка. выводим на экран то, что вернула функция func


    call asm_exit

func:
    push rbp
    mov rbp, rsp
    mov	DWORD [rbp - 12], 7 ; a = 7
	mov	DWORD [rbp - 8], 8  ; b = 8
	mov	edx, DWORD [rbp -12] ; кладём в регистры для работы 
	mov	eax, DWORD [rbp - 8]
	add	eax, edx             ; a + b
	mov	DWORD [rbp - 4], eax ; c = a + b
	mov	eax, DWORD [rbp - 4] ; кладём в eax переменную с для return c
	pop	rbp
    ret


asm_exit:
    mov rax, 60
    xor rdi, rdi
    syscall
    ret

asm_write_decimal:					
	mov rcx, N					
	l_wr:						
		xor rdx, rdx			
							
		mov ebx, 10				
		div ebx					 
							
		add rdx, code_zero		
		mov rbx, rcx				
		dec rbx						
		mov [var + rbx], dl		
		loop l_wr			
							
	call asm_write					
	ret	

asm_write:
    mov rax, 1
    mov rdi, 1
    mov rsi, var
    mov rdx, N
    syscall
    ret

