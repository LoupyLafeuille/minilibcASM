[BITS 64]
	global memmove

memmove:
	xor rax,rax
	xor rcx,rcx
	xor r8,r8
	xor r9, r9

	push rbp
	mov rbp, rsp
	sub rsp, rdx

_start:
	cmp rdx, 0
	je _next
	dec rdx
	mov r9b, [rsi]
	mov [rsp + r8], r9b
	inc rsi
	inc r8
	jmp _start

_next:
	cmp rdx, r8
	je _end
	mov r9b, [rsp + rdx]
	mov [rdi], r9b
	inc rdx
	inc rdi
	jmp _next

_end:
	mov rsp, rbp
	pop rbp
	sub rdi, rdx
	mov rax, rdi
	ret
