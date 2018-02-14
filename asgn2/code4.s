.data
a:	.word	0
ans:	.word	0
.text
main:
l1:
li	$a1, 5
li	$a2, 1
sw	$a1, a
sw	$a2, ans
l3:
jal	rec
lw	$a3, ans
li	$v0, 1
move	$a0, $a3
syscall
sw	$a3, ans
li 	$v0, 10
syscall
rec:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
lw	$t1, ans
lw	$t2, a
mul	$t1, $t1, $t2
sub	$t2, $t2, 1
sw	$t2, a
sw	$t1, ans
lw	$t3, a
bne	$t3, 1, l3
l10:
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
