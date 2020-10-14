BITS 64

%define READ 0x0
%define WRITE 0x1
%define STDIN 0x0
%define STDOUT 0x1
%define LEN 12

section .bss
	entry resb LEN

section .data
prompt:
	.string db "Your name : "
	.len equ $-prompt.string
prnt_name:
	.string db "Your name is : "
	.len equ $-prnt_name

section .text
	global _start
	global _main

_start:
	call _main
	ret

_main:
	jmp _prompt
	jmp _read_name
	jmp _print_name
	jmp exit
	ret

_prompt:
	mov rax, WRITE
	mov rdi, STDOUT
	mov rsi, prompt.string
	mov rdx, prompt.len
	syscall

_read_name:
	mov rax, READ
	mov rdi, STDIN
	mov rsi, entry
	mov rdx, LEN
	syscall
	push rsi ; met rsi (l'adresse d'entry) sur la stack

_print_name:
	mov rax, WRITE
	mov rdi, STDOUT
	mov rsi, prnt_name.string
	mov rdx, prnt_name.len
	syscall
	mov rax, WRITE
	mov rdi, STDOUT
	pop rsi ; met la 1ere valeur de la slack (en la supprimant de la stack) soit entry dans rsi
	mov rdx, LEN
	syscall

exit:
	mov rax, 60
	mov rdi, 0
	syscall