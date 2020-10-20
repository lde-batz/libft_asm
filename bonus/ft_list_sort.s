; void ft_list_sort(t_list **begin_list, int (*cmp)());
;								|				|
;								v				v
;							   rdi			   rsi

section .text
global _ft_list_sort

_ft_list_sort:
	push rdi
	push rsi
	mov rdi, [rdi]
	jmp _loop
	ret

_loop:
	mov rsi, [rdi + 8]
	cmp rsi, 0				; while (list->next != NULL)
	je _end					; if (list == NULL) { _end }
	push rdi				; save list
	mov rsi, [rsi]			; arg2 = list->next->data		
	mov rdi, [rdi]			; arg1 = list->data
	call [rsp + 8]			; ret_cmp = cmp(arg1, arg2)
	pop rdi					; list = list
	cmp rax, 0				; if (ret_cmp > 0)
	jg _swap				; { _swap }
	mov rdi, [rdi + 8]		; list = list->next
	jmp _loop

_swap:
	mov rax, [rdi]			; swap1 = list->data
	mov rbx, [rdi + 8]		; swap2 = list->next
	mov rbx, [rbx]			; swap2 = swap2->data
	mov rcx, [rdi + 8]		; list2 = list->next
	mov [rcx], rax			; list2->data = swap1
	mov [rdi], rbx			; list->data = swap2

	pop rsi					; reinitialisation de rsi
	pop rdi					; reinitialisation de rdi
	jmp _ft_list_sort

_end:
	pop rax					; destack cmp()
	pop rax					; return (begin_list)
	ret
