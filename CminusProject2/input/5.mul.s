	.section	.rodata
.int_wformat: .string "%d\n"
.str_wformat: .string "%s\n"
.int_rformat: .string "%d"
	.comm _gp, 16, 4
	.text
	.global main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $10, %r8d
	movl $20, %r9d
	imull %r9d, %r8d
	movl %r8d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq %rbp, %r8
	addq $-4, %r8
	movl $7, %r9d
	movl %r9d, (%r8)
	movq %rbp, %r9
	addq $-12, %r9
	movl $3, %r10d
	movl %r10d, (%r9)
	movq %rbp, %r10
	addq $-16, %r10
	movl $4, %r11d
	movl %r11d, (%r10)
	movq %rbp, %r11
	addq $-8, %r11
	movq %rbp, %r12
	addq $-4, %r12
	movl (%r12), %r13d
	movq %rbp, %r12
	addq $-12, %r12
	movl (%r12), %r14d
	imull %r14d, %r13d
	movq %rbp, %r12
	addq $-16, %r12
	movl (%r12), %r14d
	imull %r14d, %r13d
	movl %r13d, (%r11)
	movq %rbp, %r12
	addq $-8, %r12
	movl (%r12), %r13d
	movl %r13d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
