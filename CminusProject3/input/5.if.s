	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 8, 4
.string_const0: .string "enter a:"
.string_const1: .string "enter b:"
.string_const2: .string "a = "
.string_const3: .string "b = "
.string_const4: .string "a = "
.string_const5: .string "b = "
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
	movl $.string_const1, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $4, %rbx
	movq %rbx, %rsi
	movl $.int_rformat, %edi
	movl $0, %eax
	call scanf
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %r8d
	cmpl %r8d, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovg %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L0
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovg %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L1
	movl $.string_const2, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	jmp .L2
.L1:	nop
	movl $.string_const3, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
.L2:	nop
	jmp .L3
.L0:	nop
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl $0, %ebx
	cmpl %ebx, %ecx
	movl $0, %ecx
	movl $1, %ebx
	cmovl %ebx, %ecx
	movl $-1, %ebx
	testl %ecx, %ebx
	je .L4
	movl $.string_const4, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $0, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
	jmp .L5
.L4:	nop
	movl $.string_const5, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $.int_wformat, %edi
	movl $0, %eax
	call printf
.L5:	nop
.L3:	nop
	leave
	ret
