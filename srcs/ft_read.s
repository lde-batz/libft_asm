; ssize_t ft_read(int fd, void *buf, size_t count);
;				   |		  |			   |
;				   v		  v			   v
;				  rdi		 rsi		  rdx

section .text
global _ft_read
extern  ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc _end
	ret
_end:
	mov r10, rax
	call ___error
	mov qword [rax], r10
	mov rax, -1
	ret
