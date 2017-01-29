[BITS 64]
	global strpbrk

section .text

strpbrk:
	xor rax, rax
	xor rdx, rdx
	xor r8, r8
	mov r8, rsi

_start:
	cmp BYTE [rdi], 0
	je _end
	cmp BYTE [rsi], 0
	je _end
	jmp _loop

_init:
	cmp BYTE [rdi], 0
	je _null
	mov rsi, r8
	inc rdi

_loop:
	cmp BYTE [rsi], 0
	je _init
	mov cl, [rsi]
	cmp [rdi], cl
	je _next
	inc rsi
	jmp _loop

_next:
	mov rax, rdi
	ret

_null:
	mov rax, 0

_end:
	ret
