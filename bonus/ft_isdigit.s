; int isdigit(int c)
;				  |
;				  v
;				 rdi

section .text
global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp

	cmp rdi, 48
	jl _different
	cmp rdi, 57
	jg _different

_equal:
	mov rax, 0x1
	leave
	ret

_different:
	mov rax, 0x0
	leave
	ret
