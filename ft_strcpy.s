global _ft_strcpy

; char *strcpy(char *dest, const char *src);
;					  |					|
;					  v					v
;					 rdi			   rsi

section .text
_ft_strcpy:
	push rdi			; save l'addr de dest
	jmp _loop
	ret

_loop:
	cmp byte [rsi], 0	; while (src != '\0')
	je _end				; if (str == '\0') { ret }
	mov al, byte [rsi]	; char c = *src
	mov byte [rdi], al	; *dest = c
	inc rsi				; src++
	inc rdi				; dest++
	jmp _loop

_end:
	pop rax				; return l'addr de dest
	ret
