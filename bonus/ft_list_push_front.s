; void ft_list_push_front(t_list **begin_list, void *data);
;										|			  |
;										v			  v
;									   rdi			 rsi

section .text
global _ft_list_push_front
extern _malloc

_ft_list_push_front:
	push rdi					; save begin_list
	push rsi					; save data
	mov rdi, 16					; new = malloc(16)
	call _malloc
	pop rsi
	pop rdi
	cmp rax, 0					; if (new == NULL)
	je _end						; { ret }
	mov [rax], rsi				; *new = data    ->    mov [rax+0], rsi
	mov rbx, [rdi]				; save *begin_list
	mov [rax + 8], rbx			; new->next = *begin_list
	mov [rdi], rax				; begin_list = &new
	ret

_end:
	ret
