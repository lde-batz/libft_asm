global ft_islower

; int	islower(int c);
;					|
;					v
;				   rdi

section .text:
ft_islower:
	mov rax, 1
	cmp byte [rdi], 96
	jl _end
	cmp byte [rdi], 122
	jg _end
	sub byte [rdi], 32
	jmp _end

_end:
	mov rax, rdi
	ret