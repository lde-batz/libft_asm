; ssize_t write(int fd, const void *buf, size_t count);  
;					|				 |			  |
;					v				 v			  v
;				   rdi				rsi			 rdx

section .text
global _ft_write

_ft_write:
	mov rax, 0x2000004
	syscall 
	ret
