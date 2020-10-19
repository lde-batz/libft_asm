global _ft_strlen

; size_t strlen(const char *s);
;							|
;							v
;						   rdi

section .text
_ft_strlen:
	mov rcx, 0			; int = 0
	jmp _loop
	ret

_loop:
	cmp byte [rdi], 0	; while (str != '\0')
	je _end				; if (str == '\0') { ret }
	inc rdi				; str++
	inc rcx				; i++
	jmp _loop

_end:
	mov rax, rcx		; return (i)
	ret
