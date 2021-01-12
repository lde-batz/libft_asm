; int isspace(int c)
;				  |
;				  v
;				 rdi

section .text
global _ft_isspace

_ft_isspace:
	push rbp
	mov rbp, rsp

	cmp rdi, 32
	je _equal
	cmp rdi, 9
	jl _different
	cmp rdi, 13
	jg _different

_equal:
	mov rax, 0x1
	leave
	ret

_different
	mov rax, 0x0
	leave
	ret
