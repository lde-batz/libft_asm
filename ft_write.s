global _ft_write

; ssize_t write(int fd, const void *buf, size_t count);  
;					|				 |			  |
;					v				 v			  v
;				   rdi				rsi			 rdx

section .text
_ft_write:
	mov rax, 0x2000004
	syscall 
	ret
