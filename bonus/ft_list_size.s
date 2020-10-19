global _ft_list_size

; int ft_list_size(t_list *begin_list);
;								|
;								v
;							   rdi
section .text
_ft_list_size:
	mov rcx, 0			; int i = 0
	jmp _loop
	ret

_loop:
	cmp rdi, 0			; while (begin_list != NULL)
	je _end				; if (begin == NULL) { ret }
	mov rdi, [rdi + 8]
	inc rcx				; i++
	jmp _loop

_end:
	ret
