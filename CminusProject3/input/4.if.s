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
	movq $_gp,%rbx
	addq $0, %rbx
	movl $0, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movq $_gp,%rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	movl $2, %ecx
	subl %ecx, %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
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
	movl $0, %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
.L1:	nop
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L2
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L3
	movl $0, %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	jmp .L4
.L3:	nop
	movl $1, %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
.L4:	nop
	jmp .L5
.L2:	nop
	movl $0, %ebx
	movl %ebx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
.L5:	nop
	leave
	ret
