; int strcmp(const char *s1, const char *s2);
;						  |				 |
;						  v				 v
;						 rdi			rsi

section .text
global _ft_strcmp

_ft_strcmp:
	jmp _loop
	ret

_loop:
	mov al, byte [rdi]	; char c1 = *s1
	mov bl, byte [rsi]	; char c2 = *s2
	cmp al, bl			; if (c1 != c2) 
	jne _end			; { ret }
	cmp byte [rdi], 0	; while (s1 != '\0')
	je _end				; if (s1 == '\0') { ret }
	cmp byte [rsi], 0	; while (s2 != '\0')
	je _end				; if (s2 == '\0') { ret }
	inc rdi				; s1++
	inc rsi				; s2++
	jmp _loop

_end:
	sub rax, rbx		; return (c1 - c2)
	ret
