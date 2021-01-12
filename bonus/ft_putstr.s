; void ft_putstr(char *str);
;						|
;						v
;					   rdi

section .text
global _ft_putstr
extern _ft_strlen
extern _ft_write

_ft_putstr:
	; calling convention
	push rbp
	mov rbp, rsp

	cmp rdi, 0
	je _end
	cmp byte [rdi], 0
	je _end
	push rdi
	call _ft_strlen
	mov rdx, rax
	pop rsi
	mov rdi, 1
	call _ft_write

_end:
	leave
	ret
