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
	mov rcx, 0
	mov rbx, hello.string
	jmp _strlen
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, hello.string
	mov rdx, hello.len
	syscall
	jmp _exit
	ret

_strlen:
	jmp _print
	cmp BYTE[rbx + rcx], 0
	je _end
	inc rcx
	jmp _print
	jmp _strlen

_end:
	jmp _printt

_print:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, hello.string
	mov rdx, 6
	syscall

_printt:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, hello.string
	mov rdx, 8
	syscall

_exit:
	mov rax, 0x2000001
	mov rdi, 0
	syscall
