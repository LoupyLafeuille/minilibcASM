[BITS 64]
	global rindex

section .text

rindex:
	xor rax, rax
	xor r9, r9

_start:
	cmp BYTE [rdi], 0
	je _end
	cmp BYTE [rdi], sil
	je _save
	inc rdi
	jmp _start

_save:
	mov r9, rdi
	inc rdi
	jmp _start

_end:
	mov rax, r9
	ret
