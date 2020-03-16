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
	movl $51, %r8d
	movl $17, %r9d
	movl %r8d, %eax
	cdq
	idivl %r9d
	idivl %r9d
	movl %eax, %r9d
	movl %r8d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq %rbp, %r8
	addq $-4, %r8
	movl $100, %r9d
	movl %r9d, (%r8)
	movq %rbp, %r9
	addq $4, %r9
	movl $2, %r10d
	movl %r10d, (%r9)
	movq %rbp, %r10
	addq $8, %r10
	movl $5, %r11d
	movl %r11d, (%r10)
	movq %rbp, %r11
	addq $0, %r11
	movq %rbp, %r12
	addq $-4, %r12
	movl (%r12), %r13d
	movq %rbp, %r12
	addq $4, %r12
	movl (%r12), %r14d
	movl %r13d, %eax
	cdq
	idivl %r14d
	idivl %r14d
	movl %eax, %r14d
	movq %rbp, %r12
	addq $8, %r12
	movl (%r12), %r14d
	movl %r13d, %eax
	cdq
	idivl %r14d
	idivl %r14d
	movl %eax, %r14d
	movl %r13d, (%r11)
	movq %rbp, %r12
	addq $0, %r12
	movl (%r12), %r13d
	movl %r13d, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
