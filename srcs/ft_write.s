; ssize_t write(int fd, const void *buf, size_t count);  
;					|				 |			  |
;					v				 v			  v
;				   rdi				rsi			 rdx

section .text
global _ft_write
extern  ___error

_ft_write:
	mov rax, 0x2000004
	syscall
	jc _end
	ret
_end:
	push rax
	call ___error
	pop qword [rax]
	mov rax, -1
	ret
