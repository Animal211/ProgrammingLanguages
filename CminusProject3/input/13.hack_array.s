	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 28, 4
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movq $_gp,%rbx
	addq $0, %rbx
	movl $3, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl $4, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $8, %rbx
	movl $5, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $16, %rbx
	movl $13, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $20, %rbx
	movl $14, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $24, %rbx
	movl $15, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl $0, %ecx
	movq $_gp,%r8
	addq $0, %r8
	movl (%r8), %r9d
	subl %r9d, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movq $_gp, %rbx
	addq $12, %rbx
	movslq %ecx, %rcx
	imulq $4, %rcx
	addq %rcx, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movl $11, %ebx
	movq $_gp, %rcx
	addq $12, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl (%rcx), %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $24, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	movl $12, %ebx
	movq $_gp, %rcx
	addq $12, %rcx
	movslq %ebx, %rbx
	imulq $4, %rbx
	addq %rbx, %rcx
	movl $100, %ebx
	movl %ebx, (%rcx)
	movq $_gp,%rbx
	addq $24, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
