.data
k:	.word	0
i:	.word	0
f:	.word	0
g:	.word	0
z:	.word	0
a:	.word	0
q:	.word	0
c:	.word	0
d:	.word	0
.text
main:
l1:
li	$a1, 10
addi	$a2, $a1, 2
mul	$a3, $a1, 7
addi	$t1, $a1, -11
sw	$a1, a
sw	$a2, q
sw	$a3, c
sw	$t1, d
l6:
j	l10
l7:
lw	$t2, a
addi	$t3, $t2, 40
addi	$t4, $t2, -40
sw	$t3, f
sw	$t4, g
sw	$t2, a
j	l12
l10:
lw	$t5, a
addi	$t6, $t5, 20
addi	$t7, $t5, -20
sw	$t6, i
sw	$t7, z
sw	$t5, a
l12:
li	$t8, 0
sw	$t8, k
j	l18
l14:
lw	$t9, a
addi	$t9, $t9, 1
lw	$s1, i
addi	$s1, $s1, 1
lw	$s2, z
addi	$s2, $s2, 1
lw	$s3, k
addi	$s3, $s3, 1
sw	$s3, k
sw	$s1, i
sw	$s2, z
sw	$t9, a
l18:
lw	$s4, k
lw	$s5, q
l19:
j	l20
l20:
li 	$v0, 10
syscall
