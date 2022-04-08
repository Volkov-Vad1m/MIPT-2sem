all:
	nasm -f elf64 -o D.o D.asm
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o D -lc D.o
	./D

