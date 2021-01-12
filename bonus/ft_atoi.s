; int ft_atoi(char *str);
;					 |
;					 v
;					rdi

section .text
global _ft_atoi
extern _ft_isdigit
extern _ft_isspace

_ft_atoi:
	; calling convention
	push rbp
	mov rbp, rsp

	; init stack
	; str -> rsp
	; int nbr -> rsp+8
	; int is_negative -> rsp+16
	sub rsp, 12					; save 12
	mov qword [rsp], 0x0		; init var
	mov dword [rsp + 8], 0x0
	push rdi					; save str

	mov r10, rdi

_ft_atoi_delete_spaces:
	mov [rsp], r10					; save str
	xor rdi, rdi					; rdi = 0
	mov dil, byte [r10]
	call _ft_isspace				; ft_isspace(*str)
	mov r10, [rsp]					; r10 = str
	cmp rax, 1						; while (ret == 1)
	je _ft_atoi_delete_spaces_inc	; do

_ft_atoi_delete_sign:
	cmp byte [r10], 0x2b			; if (*str == '+')
	je _ft_atoi_delete_sign_inc	
	cmp byte [r10], 0x2d			; if (*str == '-')
	je _ft_atoi_delete_sign_neg

_ft_atoi_loop:
	; check end of str
	cmp byte [r10], 0				; if (*str == '\0')
	je _ft_atoi_neg					; return

	; check if a num
	mov [rsp], r10					; save str
	xor rdi, rdi					; rdi = 0
	mov dil, byte [r10]
	call _ft_isdigit				; _ft_isdigit(*str)
	mov r10, [rsp]					; str
	cmp rax, 0						; if (ret == 0)
	je _ft_atoi_neg					; return

	mov r11, qword [rsp+8]			; nbr
	imul r11, 10					; nbr *= 10
	xor r15, r15
	mov r15b, byte [r10]
	sub r15, 48						; *str - '0'
	add r11, r15					; nbr += *str - '0'

	mov qword [rsp+8], r11			; save nbr
	inc r10							; str++
	jmp _ft_atoi_loop


_ft_atoi_neg:
	mov rax, qword [rsp+8]			; ret = nbr
	xor rcx, rcx					; rcx = 0
	mov ecx, dword [rsp+16]			; rcx = neg
	cmp ecx, 0						; if (neg == 0)
	je _ft_atoi_end					; return ret
	neg rax							; ret = -ret

_ft_atoi_end:
	pop rdi
	leave
	ret

_ft_atoi_delete_spaces_inc:
	inc r10							; str++
	jmp _ft_atoi_delete_spaces

_ft_atoi_delete_sign_neg:
	not dword [rsp + 16]			; is_negative = !is_negative

_ft_atoi_delete_sign_inc:
	inc r10							; str++
	jmp _ft_atoi_loop
