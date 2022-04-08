global  _start

section .text
_start:
        mov     rax, 1                  
        mov     rdi, 1                 
        mov     rsi, message            
        mov     rdx, 33                 
        syscall  
                       
        mov     eax, 60                 
        xor     rdi, rdi                
        syscall                         

message: 
	db "Liberté, égalité, fraternité!", 10
