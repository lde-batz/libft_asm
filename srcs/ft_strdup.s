; char *strdup(const char *s);
;						   |
;						   v
;						  rdi

section .text
global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	push rdi			; save s
	call _ft_strlen		; rax = ft_strlen(s)
	inc rax				; rax++
	mov rdi, rax		; rax = malloc(rax)
	call _malloc
	cmp rax, 0
	je _end
	mov rdi, rax		; dest = rax
	pop rsi				; src = s
	call _ft_strcpy
	ret

_end:
	ret
