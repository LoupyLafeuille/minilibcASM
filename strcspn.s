[BITS 64]
	global strcspn

section .text

strcspn:
	xor rax, rax
	xor rcx,rcx
	xor r8, r8
	xor r9, r9

_start:
	cmp BYTE [rdi + r8], 0
	je _end
	jmp _compare

_restart:
	inc rax
	inc r8
	cmp BYTE [rdi + r8], 0
	je _end
	xor r9, r9

_compare:
	cmp BYTE [rsi + r9], 0
	je _restart
	mov cl, [rdi + r8]
	cmp [rsi + r9], cl
	je _end
	inc r9
	jmp _compare

_end:
	ret
