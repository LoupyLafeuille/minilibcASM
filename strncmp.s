[BITS 64]
	global strncmp

section .text

strncmp:
	xor rax, rax
	xor rcx, rcx

_start:
	mov cl, [rsi]
	cmp [rdi], cl
	jne _diff
	cmp rdx, 0
	je _end
	cmp BYTE [rdi], 0
	je _end
	cmp BYTE [rsi], 0
	je _end
	dec rdx
	inc rsi
	inc rdi
	jmp _start

_diff:
	sub cl, [rdi]
	movsx rax, cl
	neg rax

_end:
	ret
