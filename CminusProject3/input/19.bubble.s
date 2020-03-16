	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 76, 4
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $0, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $32, %ebx
	movl %ebx, (%rcx)
	movl $1, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $11, %ebx
	movl %ebx, (%rcx)
	movl $2, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $111, %ebx
	movl %ebx, (%rcx)
	movl $3, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $88, %ebx
	movl %ebx, (%rcx)
	movl $4, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $11, %ebx
	movl %ebx, (%rcx)
	movl $5, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $44, %ebx
	movl %ebx, (%rcx)
	movl $6, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $33, %ebx
	movl %ebx, (%rcx)
	movl $7, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $33, %ebx
	movl %ebx, (%rcx)
	movl $8, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $22, %ebx
	movl %ebx, (%rcx)
	movl $9, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $77, %ebx
	movl %ebx, (%rcx)
	movl $10, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $45, %ebx
	movl %ebx, (%rcx)
	movl $11, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $65, %ebx
	movl %ebx, (%rcx)
	movl $12, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $76, %ebx
	movl %ebx, (%rcx)
	movl $13, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $87, %ebx
	movl %ebx, (%rcx)
	movl $14, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $34, %ebx
	movl %ebx, (%rcx)
	movq $_gp,%rbx
	addq $60, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
.L0:	nop
	movq $_gp,%rbx
	addq $60, %rbx
	movl (%rbx), %ecx
	movl $14, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L1
	movq $_gp,%rbx
	addq $72, %rbx
	movq $_gp,%rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $64, %rbx
	movq $_gp,%rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
.L2:	nop
	movq $_gp,%rbx
	addq $64, %rbx
	movl (%rbx), %ecx
	movl $15, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L3
	movq $_gp,%rbx
	addq $64, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	movq $_gp,%rbx
	addq $72, %rbx
	movl (%rbx), %r8d
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %r8d, %r8
	imulq $4, %r8
	addq %r8, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L4
	movq $_gp,%rbx
	addq $72, %rbx
	movq $_gp,%rcx
	addq $64, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	jmp .L5
.L4:	nop
.L5:	nop
	movq $_gp,%rbx
	addq $64, %rbx
	movq $_gp,%rcx
	addq $64, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L2
.L3:	 nop
	movq $_gp,%rbx
	addq $68, %rbx
	movq $_gp,%rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %r8d, %r8
	imulq $4, %r8
	addq %r8, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $60, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq $_gp,%rcx
	addq $72, %rcx
	movl (%rcx), %r8d
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %r8d, %r8
	imulq $4, %r8
	addq %r8, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $72, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movq $_gp,%rcx
	addq $68, %rcx
	movl (%rcx), %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $60, %rbx
	movq $_gp,%rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L0
.L1:	 nop
	movq $_gp,%rbx
	addq $60, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
.L6:	nop
	movq $_gp,%rbx
	addq $60, %rbx
	movl (%rbx), %ecx
	movl $15, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L7
	movq $_gp,%rbx
	addq $60, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $60, %rbx
	movq $_gp,%rcx
	addq $60, %rcx
	movl (%rcx), %r8d
	movl $1, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	jmp .L6
.L7:	 nop
	leave
	ret
