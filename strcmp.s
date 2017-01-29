[BITS 64]
	global strcmp

	section .text

strcmp:
	xor rax, rax
	xor rcx, rcx

loop:
	mov cl, [rsi]
	cmp [rdi], cl
	je next
	jne diff

next:
	cmp BYTE [rdi + 1], 0
	je match
	inc rdi
	inc rsi
	jmp loop

diff:
	sub cl, [rdi]
	movsx rax, cl
	neg rax
	jmp end

match:
	cmp BYTE [rsi + 1], 0
	je matching
	jmp diff

matching:
	mov rax, 0

end:
	ret
