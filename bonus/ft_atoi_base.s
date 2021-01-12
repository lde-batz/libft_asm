; int ft_atoi_base(char *str, char *base);
;						  |			 |
;						  v			 v
;						 rdi		rsi

section .text
global _ft_atoi_base
extern _ft_strlen
extern _ft_isspace
extern _printf

_ft_atoi_base:
	; calling convention
	push rbp
	mov rbp, rsp

	; init stack
	; str -> rsp
	; base -> rsp+8
	; long int nbr -> rsp+16
	; int base_len -> rsp+24
	; int is_negative -> rsp+28
	sub rsp, 16					; save 16
	mov qword [rsp], 0x0		; init var
	mov dword [rsp + 8], 0x0
	mov dword [rsp + 12], 0x0
	push rsi					; save base
	push rdi					; save str

	; check base
	mov rdi, rsi				; check_base(base)
	call _check_base
	cmp rax, 0					; if (ret == 0)
	je _ft_atoi_base_error		; return 0
	
	mov rdi, [rsp]				; rdi = str

; delete spaces
_ft_atoi_base_delete_spaces:
	mov [rsp], rdi							; save str
	mov r8, rdi
	xor rdi, rdi
	mov dil, byte [r8]						; ft_isspace(*str)
	call _ft_isspace
	mov rdi, [rsp]							; rdi = str
	cmp rax, 1								; while (ret == 1)
	je _ft_atoi_base_delete_spaces_inc		; do

_ft_atoi_base_delete_sign:
	cmp byte [rdi], 0x2b				; if (*str == '+')
	je _ft_atoi_base_delete_sign_inc	
	cmp byte [rdi], 0x2d				; if (*str == '-')
	je _ft_atoi_base_delete_sign_neg
	
	; get the length base
	mov [rsp], rdi						; save new/clear str
	mov rdi, [rsp+0x8]					; ft_strlen(base)
	call _ft_strlen
	cmp eax, 2							; if (len < 2)
	jl _ft_atoi_base_error				; return 0
	mov dword [rsp + 24], eax			; base_len = ret

	mov rdi, [rsp]						; rdi = str

_ft_atoi_base_loop:
	; check end of str
	cmp byte [rdi], 0					; if (*str == '\0')
	je _ft_atoi_base_neg				; return

	; check if the char is in the base
	mov rsi, [rsp+8]
	call _check_base_position			; _check_base_position(str, base)
	cmp eax, -1							; if (ret == -1)
	je _ft_atoi_base_neg				; return 0

	mov r11, qword [rsp+16]				; nbr
	xor r15, r15						; r15 = 0
	mov r15d, dword [rsp+24]			; base_len
	imul r11, r15						; nbr *= base_len
	add r11, rax						; nbr += ret
	mov qword [rsp+16], r11				; save nbr
	inc rdi								; str++
	jmp _ft_atoi_base_loop
	

_ft_atoi_base_neg:
	mov rax, qword [rsp+16]				; ret = nbr
	xor rcx, rcx						; rcx = 0
	mov ecx, dword [rsp+28]				; rcx = neg
	cmp ecx, 0							; if (neg == 0)
	je _ft_atoi_base_end				; return ret
	neg rax								; ret = -ret

_ft_atoi_base_end:
	pop rdi
	pop rsi
	leave
	ret


_ft_atoi_base_delete_spaces_inc:
	inc rdi								; str++
	jmp _ft_atoi_base_delete_spaces

_ft_atoi_base_delete_sign_neg:
	not dword [rsp + 28]				; is_negative = !is_negative

_ft_atoi_base_delete_sign_inc:
	inc rdi								; str++
	jmp _ft_atoi_base_delete_sign		; while (*str == '+' || *str == '-') do;

; return 0
_ft_atoi_base_error:
	mov rax, 0							; ret = 0
	pop rdi
	pop rsi
	leave
	ret


;--------------------------------------------------------------------------------------------------

; CHECK BASE

; check is the base is valid
_check_base:
	; calling convention
	push rbp
	mov rbp, rsp
	
	push rdi
	call _ft_strlen
	mov r11, [rsp]
	cmp eax, 0x2			; if (ft_strlen(base) < 2)
	jl _check_base_false	; return 0

_check_base_loop:
	; check if the check is finished
	cmp byte [r11], 0		; if (*base == 0)
	je _check_base_true		; return 1

	; check if it's a '+' or a '-'
	cmp byte [r11], 0x2b	; if (*base == '+')
	je _check_base_false	; return 0
	cmp byte [r11], 0x2d	; if (*base == '+')
	je _check_base_false	; return 0

	; check if it's a space
	mov [rsp], r11
	xor rdi, rdi
	mov dil, byte[r11]
	call _ft_isspace		; if (_ft_isspace(*base))
	mov r11, [rsp]
	cmp rax, 0				; if (ft_isspace(*base) == 1)
	jne _check_base_false	; return 0
	mov r15, r11			; int check = base

; check if it's duplicate
_check_base_loop_in_base:
	inc r15							; check++
	mov r10b, byte [r15]
	cmp r10b, byte [r11]			; if (*base == *check)
	je  _check_base_false			; return 0
	cmp r10b, 0						; while (check != NULL)
	jne _check_base_loop_in_base	; do

	inc r11							; base++
	jmp _check_base_loop			; while

; return 0
_check_base_false:
	mov rax, 0x0
	leave
	ret

; return 1
_check_base_true:
	mov rax, 0x1
	leave
	ret


;--------------------------------------------------------------------------------------------------

; CHECK BASE POSITION

; find the position of the char in the base
_check_base_position:
	push rbp
	mov rbp, rsp
	xor rcx, rcx

_check_base_position_loop:
	cmp byte [rsi], 0
	je _check_base_position_error
	mov al, byte [rdi]
	cmp al, byte [rsi]
	je _check_base_position_end
	inc rsi
	inc rcx
	jmp _check_base_position_loop

_check_base_position_end:
	mov rax, rcx
	leave
	ret

_check_base_position_error:
	mov rax, -1
	leave
	ret