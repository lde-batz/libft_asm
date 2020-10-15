global _ft_bzero

; void bzero(void *s, size_t n);
;				   |		 |
;				   v		 v
;				  rdi		rsi

section .text
_ft_bzero:
	cmp rsi, 0			; while(n > 0)
	je _ret				; if (n == 0) { ret }
	mov byte [rdi], 0	; s = '\0'
	inc rdi				; s++
	dec rsi				; n--
	jmp _ft_bzero

_ret:
	ret
