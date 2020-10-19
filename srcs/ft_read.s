global _ft_read

; ssize_t ft_read(int fd, void *buf, size_t count);
;				   |		  |			   |
;				   v		  v			   v
;				  rdi		 rsi		  rdx

section .text
_ft_read:
	mov rax, 0x2000003
	syscall 
	ret
