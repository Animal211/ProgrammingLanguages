	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 4, 4
.string_const0: .string "enter a:"
.string_const1: .string "complete!"
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $.string_const0, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $0, %rbx
	movq %rbx, %rsi
	movl $.int_rformat, %edi
	movl $0, %eax
	call scanf
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovne %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L0
	movl $1, %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	jmp .L1
.L0:	nop
.L1:	nop
	movl $.string_const1, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
