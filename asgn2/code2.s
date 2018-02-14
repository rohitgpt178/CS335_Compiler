.data
a:	.word	0
B:	.word	0
.text
main:
l1:
li	$a1, 2
li	$a2, 7
div	$a1, $a2, 2
sw	$a1, a
sw	$a2, B
j	l5
l5:
jal	foo
move 	$a3, $v0
lw	$t1, a
addi	$a3, $t1, 5
li	$v0, 1
move	$a0, $a3
syscall
sw	$t1, a
sw	$a3, B
li 	$v0, 10
syscall
foo:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
lw	$t2, a
mul	$t2, $t2, 100
sw	$t2, a
addi	$t2, $t2, 5
lw	$t3, a
li	$v0, 1
move	$a0, $t3
syscall
add 	$v0, $0, $t2
sw	$t3, a
sw	$t2, B
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
