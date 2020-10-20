; int	tolower(int c);
;					|
;					v
;				   rdi

section .text
global _ft_tolower

_ft_tolower:
	cmp rdi, 65
	jl _end
	cmp rdi, 90
	jg _end
	add rdi, 32
	jmp _end

_end:
	mov rax, rdi
	ret
