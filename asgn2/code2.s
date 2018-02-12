.data
a:	.word	0
B:	.word	0
.text
main:
l1:
li	$a1, 2
sw	$a1, a
li	$a1, 7
sw	$a1, B
div	$a1, $a1, 2
sw	$a1, a
j	l5
l5:
jal	foo
move 	$a1, $v0
sw	$a1, B
lw	$a1, a
sw	$a1, a
addi	$a1, $a1, 5
li	$v0, 1
move	$a0, $a1
syscall
sw	$a1, B
li 	$v0, 10
syscall
foo:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
lw	$a1, a
mul	$a1, $a1, 100
sw	$a1, a
addi	$a1, $a1, 5
sw	$a1, B
lw	$a1, a
li	$v0, 1
move	$a0, $a1
syscall
sw	$a1, a
lw 	$v0, B
sw	$a1, B
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
