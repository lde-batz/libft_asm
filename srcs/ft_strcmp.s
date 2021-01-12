; int strcmp(const char *s1, const char *s2);
;						  |				 |
;						  v				 v
;						 rdi			rsi

section .text
global _ft_strcmp

_ft_strcmp:
	mov	r8, rdi
	or	r8, rsi				; if (!s1 && !s2)
	cmp	r8, 0				; return 0
	je	equal

cmp_loop:
	mov	r8, [rdi]
	cmp	r8, 0				; if (*s1 == '\0')
	je	bcmp
	cmp	byte [rsi], 0		; if (*s2 == '\0')
	je	bcmp
	cmp	r8b, byte [rsi]		; if (*s1 == *s2)
	ja	greater				; if (*s1 > *s2)
	jb	lower				; if (*s1 < *s2)
	inc	rdi					; s1++
	inc	si					; s2++
	jmp	cmp_loop			

bcmp:
	cmp	r8b, byte [rsi]
	ja	greater				; if (*s1 > *s2)
	jb	lower				; if (*s1 < *s2)
	je	equal				; if (*s1 == *s2)

equal:
	mov	rax, 0				; return 0
	ret

greater:
	mov	rax, 1				; return 1
	ret

lower:
	mov	rax, -1				; return -1
	ret
