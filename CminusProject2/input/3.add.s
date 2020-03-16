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
	addl %r9d, %r8d
	movl %r8d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp, %r8
	addq $0, %r8
	movl $1, %r9d
	movl %r9d, (%r8)
	movq $_gp, %r9
	addq $8, %r9
	movl $3, %r10d
	movl %r10d, (%r9)
	movq $_gp, %r10
	addq $12, %r10
	movl $4, %r11d
	movl %r11d, (%r10)
	movq $_gp, %r11
	addq $4, %r11
	movq $_gp, %r12
	addq $0, %r12
	movl (%r12), %r13d
	movq $_gp, %r12
	addq $8, %r12
	movl (%r12), %r14d
	addl %r14d, %r13d
	movq $_gp, %r12
	addq $12, %r12
	movl (%r12), %r14d
	addl %r14d, %r13d
	movl %r13d, (%r11)
	movq $_gp, %r12
	addq $4, %r12
	movl (%r12), %r13d
	movl %r13d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
