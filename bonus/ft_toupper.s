; int	toupper(int c);
;					|
;					v
;				   rdi

section .text
global _ft_toupper

_ft_toupper:
	cmp rdi, 97
	jl _end
	cmp rdi, 122
	jg _end
	sub rdi, 32
	jmp _end

_end:
	mov rax, rdi
	ret
