[BITS 64]
	global strstr

section .text

strstr:
	xor rax, rax
	xor rcx, rcx
	xor r8, r8
	cmp BYTE [rsi], 0
	jne _start
	mov rax, rdi
	jmp _end

_start:
	cmp BYTE [rdi], 0
	je _end
	mov cl, [rsi]
	cmp BYTE [rdi], cl
	je _match
	inc rdi
	jmp _start

_match:
	mov r8, rdi

_loop:
	inc rdi
	inc rsi
	cmp BYTE [rsi], 0
	je _success
	mov cl, [rsi]
	cmp BYTE [rdi], cl
	je _loop
	jne _end

_success:
	mov rax, r8

_end:
	ret
