; int ft_list_size(t_list *begin_list);
;								|
;								v
;							   rdi

section .text
global _ft_list_size

_ft_list_size:
	mov rcx, 0			; int i = 0
	jmp _loop
	ret

_loop:
	cmp rdi, 0			; while (begin_list != NULL)
	je _end				; if (begin_list == NULL) { ret }
	mov rdi, [rdi + 8]	; begin_list = begin_list->next
	inc rcx				; i++
	jmp _loop

_end:
	mov rax, rcx		; return (i)
	ret
