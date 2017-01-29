[BITS 64]
	global strcasecmp

	section .text

strcasecmp:
	xor rax, rax
	xor rcx, rcx
	xor r8, r8
	xor r9, r9

_start:

	mov r8b, [rdi]
	mov r9b, [rsi]
	cmp r8b, 91
	jl _lowerRDI

_brk:
	cmp r9b, 91
	jl _lowerRSI
	jmp _cmp

_lowerRDI:
	cmp r8b, 65
	jl _brk
	add r8b, 32
	jmp _brk

_lowerRSI:
	cmp r9b, 65
	jl _cmp
	add r9b, 32
	jmp _cmp

_cmp:
	cmp r8b, r9b
	jne _diff
	cmp r8b, 0
	je _end
	cmp r9b, 0
	je _end
	inc rsi
	inc rdi
	jmp _start

_diff:
	mov cl, [rsi]
	sub cl, [rdi]
	movsx rax, cl
	neg rax

_end:
		ret
