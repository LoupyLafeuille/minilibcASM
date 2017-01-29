[BITS 64]
	global memset

section .text

memset:
	mov rax, rdi

_loop:
	cmp rdx, 0
	je _end
	mov BYTE [rdi], sil
	inc rdi
	dec rdx
	jmp _loop

_end:
	ret
