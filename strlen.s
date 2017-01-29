[BITS 64]
	global strlen

section .text

strlen:
	xor rax, rax

_start:
	cmp BYTE [rdi], BYTE 0
	je _end
	inc rax
	inc rdi
	jmp _start

_end:
	ret
