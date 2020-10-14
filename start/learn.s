section .bss ; declaration variable non initialisé
	a resb 256

section .data ; declaration variable initialisé
hello:
	.string db "hello world!", 10
	.len equ $ - hello.string

section .text ; declaration instruction
	global _start
	global _main

_start:
	call _main
	ret

_main:
	mov rax, 1
	mov rdi, 1
	mov rsi, hello.string
	mov rdx, hello.len
	syscall
	jmp exit
	ret

exit:
	mov rax, 60
	mov rdi, 0
	syscall