	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 8, 4
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $3, %ebx
	movq $_gp, %rcx
	addq $0, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $4, %ebx
	movl %ebx, (%rcx)
	movl $3, %ebx
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
	movq $_gp,%rbx
	addq $4, %rbx
	movl $3, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl $7, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
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
	addq $4, %rbx
	movq $_gp,%rcx
	addq $4, %rcx
	movl (%rcx), %r8d
	movl $2, %ecx
	addl %ecx, %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $0, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl $22, %ecx
	movl %ecx, (%rbx)
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
	leave
	ret
