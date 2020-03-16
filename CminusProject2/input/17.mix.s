	.section	.rodata
.int_wformat: .string "%d\n"
.str_wformat: .string "%s\n"
.int_rformat: .string "%d"
	.comm _gp, 20, 4
	.text
	.global main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movq $_gp, %r8
	addq $0, %r8
	movl $1, %r9d
	movl %r9d, (%r8)
	movq $_gp, %r9
	addq $4, %r9
	movl $2, %r10d
	movl %r10d, (%r9)
	movq $_gp, %r10
	addq $8, %r10
	movl $3, %r11d
	movl %r11d, (%r10)
	movq $_gp, %r11
	addq $12, %r11
	movl $4, %r12d
	movl %r12d, (%r11)
	movq $_gp, %r12
	addq $16, %r12
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %r14d
	movq $_gp, %r13
	addq $4, %r13
	movl (%r13), %r15d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %eax
	addl %eax, %r15d
	cmpl %r15d, %r14d
	movl $0, %r14d
	movl $1, %r13d
	cmovl %r13d, %r14d
	movl %r14d, (%r12)
	movq $_gp, %r13
	addq $16, %r13
	movl (%r13), %r14d
	movl %r14d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp, %r13
	addq $0, %r13
	movl (%r13), %r14d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %r15d
	imull %r15d, %r14d
	movq $_gp, %r13
	addq $4, %r13
	movl (%r13), %r15d
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %eax
	imull %eax, %r15d
	cmpl %r15d, %r14d
	movl $0, %r14d
	movl $1, %r13d
	cmovg %r13d, %r14d
	movl %r14d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %r14d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %r15d
	imull %r15d, %r14d
	movq $_gp, %r13
	addq $4, %r13
	movl (%r13), %r15d
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %eax
	addl %eax, %r15d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %eax
	addl %eax, %r15d
	cmpl %r15d, %r14d
	movl $0, %r14d
	movl $1, %r13d
	cmovg %r13d, %r14d
	movl %r14d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %r14d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %r15d
	movq $_gp, %r13
	addq $4, %r13
	movl (%r13), %eax
	cmpl %eax, %r15d
	movl $0, %r15d
	movl $1, %r13d
	cmovg %r13d, %r15d
	imull %r15d, %r14d
	movq $_gp, %r13
	addq $8, %r13
	movl (%r13), %r15d
	addl %r15d, %r14d
	movq $_gp, %r13
	addq $12, %r13
	movl (%r13), %r15d
	addl %r15d, %r14d
	movl %r14d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
