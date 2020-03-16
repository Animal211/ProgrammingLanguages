	.section	.rodata
.int_wformat: .string "%d\n"
.str_wformat: .string "%s\n"
.int_rformat: .string "%d"
	.string_const0: .string "Hello world!"
	.text
	.global main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $.string_const0, %ebx
	movl %ebx, %esi
	movl $.str_wformat, %edi
	movl $0, %eax
	call printf
	leave
	ret
