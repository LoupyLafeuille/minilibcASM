[BITS 64]
	global strchr

section .text

strchr:
	xor rax, rax

_start:
	cmp BYTE [rdi], 0
	je _null
	cmp BYTE [rdi], sil
	je _end
	inc rdi
	jmp _start

_null:
	mov rax, 0
	ret

_end:
	mov rax, rdi
	ret
