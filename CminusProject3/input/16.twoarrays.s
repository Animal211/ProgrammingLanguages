	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 20, 4
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movq $_gp,%rbx
	addq $4, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
.L0:	nop
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $50, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L1
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movq $_gp,%rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L0
.L1:	 nop
	movq $_gp,%rbx
	addq $8, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
.L2:	nop
	movq $_gp,%rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	movl $50, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L3
	movq $_gp,%rbx
	addq $8, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $16, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq $_gp,%rcx
	addq $8, %rcx
	movl (%rcx), %r8d
	movl $50, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $8, %rbx
	movq $_gp,%rcx
	addq $8, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L2
.L3:	 nop
	movq $_gp,%rbx
	addq $4, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $12, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
.L4:	nop
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $100, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L5
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $50, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L6
	movq $_gp,%rbx
	addq $12, %rbx
	movq $_gp,%rcx
	addq $12, %rcx
	movl (%rcx), %r8d
	movq $_gp,%rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %r9d, %r9
	imulq $4, %r9
	addq %r9, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	jmp .L7
.L6:	nop
	movq $_gp,%rbx
	addq $12, %rbx
	movq $_gp,%rcx
	addq $12, %rcx
	movl (%rcx), %r8d
	movq $_gp,%rcx
	addq $4, %rcx
	movl (%rcx), %r9d
	movl $50, %ecx
	subl %ecx, %r9d
	movq $_gp, %rcx
	addq $16, %rcx
	movslq %r9d, %r9
	imulq $4, %r9
	addq %r9, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
.L7:	nop
	movq $_gp,%rbx
	addq $4, %rbx
	movq $_gp,%rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L4
.L5:	 nop
	movq $_gp,%rbx
	addq $12, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movl $5, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl (%rcx), %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movl $10, %ebx
	movq $_gp, %rcx
	addq $16, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl (%rcx), %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
