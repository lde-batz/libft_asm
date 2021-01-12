; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
;									  |				   |			|
;									  v				   v			v
;									 rdi			  rsi		   rdx

section .text
global _ft_list_remove_if

_ft_list_remove_if:
	push rdi				; save begin_last
	push rsi				; save data_ref
	push rdx				; save cmp()
	mov rdi, [rdi]			; list = *begin_list
	push rdi				; save last
	mov r15, 0				; int r15 = 0
	jmp _loop
	ret

_loop:
	cmp rdi, 0				; while (list != NULL)
	je _end					; if (list == NULL) { _end }
	push rdi				; save list
	mov rdi, [rdi]			; arg1 = list->data
	mov rsi, [rsp + 24]		; arg2 = data_ref	
	call [rsp + 16]			; ret_cmp = cmp(arg1, arg2)
	pop rdi					; list - list
	cmp rax, 0				; if (ret_cmp == 0)
	je _remove				; { _remove }
	mov rdi, [rdi + 8]		; list = list->next
	cmp r15, 0				; if (r15 != 0)
	jne _increment			; { _increment }
	mov r15, 1				; sinon { r15 = 1 }
	jmp _loop

_remove:
	cmp r15, 0				; if (r15 == 0)
	je _remove_first		; { _remove_first }
	pop rax					; last = last
	mov rbx, [rdi + 8]		; tmp = list->next
	mov [rax + 8], rbx		; last->next = tmp
	push rax				; save last
	mov rdi, [rdi + 8]		; list = list->next
	mov r15, 1				; r15 = 1
	jmp _loop

_remove_first:
	mov rax, [rsp + 24]		; rax = begin_list
	mov rbx, [rdi + 8]		; rbx = list->next
	pop rdx					; rdx = last
	mov [rax], rbx			; *begin = list->next
	mov rdi, [rdi + 8]		; list = list->next
	mov rdx, rdi			; last = list
	push rdx				; save last
	jmp _loop

_increment:
	pop rax					; last = last
	mov rax, [rax + 8]		; last = last->next
	push rax				; save last
	jmp _loop

_end:
	pop rdi					; destack last
	pop rdx					; destack cmp()
	pop rsi					; destack data_ref
	pop rdi					; destack begin_list
	ret
