	.file	"cosine.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%lf %lf"
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC3:
	.string	"Cosine of a= %lf \nCosine of b= %lf \n"
	.text
	.p2align 4,,15
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$80, %esp
	leal	64(%esp), %eax
	movl	%eax, 8(%esp)
	leal	72(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	__isoc99_scanf
	fldl	.LC1
	fldl	64(%esp)
	fmul	%st(1), %st
	flds	.LC2
	fdivr	%st, %st(1)
	fxch	%st(1)
	fstpl	(%esp)
	fstpl	32(%esp)
	fstpl	48(%esp)
	call	cos
	fldl	48(%esp)
	fmull	72(%esp)
	fldl	32(%esp)
	fdivrp	%st, %st(1)
	fstpl	(%esp)
	fstpl	48(%esp)
	call	cos
	movl	$.LC3, 4(%esp)
	movl	$1, (%esp)
	fldl	48(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	call	__printf_chk
	xorl	%eax, %eax
	leave
	ret
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	1413754136
	.long	1074340347
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC2:
	.long	1127481344
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5.1) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
