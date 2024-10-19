	.file	"exercice1.c"
# GNU C17 (Ubuntu 13.2.0-23ubuntu4) version 13.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 13.2.0, GMP version 6.3.0, MPFR version 4.2.1, MPC version 1.3.1, isl version isl-0.26-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"entrer une nombre pour calculer sont factoriel: "
.LC1:
	.string	"%d"
.LC2:
	.string	"le result est: %llu\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# exercice1.c:3: int main() {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp98
	movq	%rax, -8(%rbp)	# tmp98, D.3189
	xorl	%eax, %eax	# tmp98
# exercice1.c:5: 	long long unsigned int result = 1;
	movq	$1, -16(%rbp)	#, result
.L2:
# exercice1.c:8: 		printf("entrer une nombre pour calculer sont factoriel: ");
	leaq	.LC0(%rip), %rax	#, tmp90
	movq	%rax, %rdi	# tmp90,
	movl	$0, %eax	#,
	call	printf@PLT	#
# exercice1.c:9: 		scanf("%d", &number);
	leaq	-20(%rbp), %rax	#, tmp91
	movq	%rax, %rsi	# tmp91,
	leaq	.LC1(%rip), %rax	#, tmp92
	movq	%rax, %rdi	# tmp92,
	movl	$0, %eax	#,
	call	__isoc99_scanf@PLT	#
# exercice1.c:10: 	} while(number < 0);
	movl	-20(%rbp), %eax	# number, number.0_1
	testl	%eax, %eax	# number.0_1
	js	.L2	#,
# exercice1.c:12: 	while (number > 1) {
	jmp	.L3	#
.L4:
# exercice1.c:13: 		result *= number;
	movl	-20(%rbp), %eax	# number, number.1_2
	cltq
	movq	-16(%rbp), %rdx	# result, tmp94
	imulq	%rdx, %rax	# tmp94, tmp93
	movq	%rax, -16(%rbp)	# tmp93, result
# exercice1.c:14: 		number--;
	movl	-20(%rbp), %eax	# number, number.2_4
	subl	$1, %eax	#, _5
	movl	%eax, -20(%rbp)	# _5, number
.L3:
# exercice1.c:12: 	while (number > 1) {
	movl	-20(%rbp), %eax	# number, number.3_6
	cmpl	$1, %eax	#, number.3_6
	jg	.L4	#,
# exercice1.c:17: 	printf("le result est: %llu\n", result);
	movq	-16(%rbp), %rax	# result, tmp95
	movq	%rax, %rsi	# tmp95,
	leaq	.LC2(%rip), %rax	#, tmp96
	movq	%rax, %rdi	# tmp96,
	movl	$0, %eax	#,
	call	printf@PLT	#
# exercice1.c:18: 	return (0);
	movl	$0, %eax	#, _15
# exercice1.c:19: }
	movq	-8(%rbp), %rdx	# D.3189, tmp99
	subq	%fs:40, %rdx	# MEM[(<address-space-1> long unsigned int *)40B], tmp99
	je	.L6	#,
	call	__stack_chk_fail@PLT	#
.L6:
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
