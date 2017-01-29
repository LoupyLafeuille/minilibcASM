[BITS 64]
	global memcpy

section .text

memcpy:
	mov rax, rdi

loop:
	cmp rdx, 0
	je end
	mov cl, [rsi]
	mov [rdi], cl
	inc rdi
	inc rsi
	dec rdx
	jmp loop

end:
	ret
