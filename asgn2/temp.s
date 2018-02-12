.data
B:	.word	0
a:	.word	0
.text
main:
l1:
li	$a1, 2
sw	$a1, a
l2:
li	$a2, 7
sw	$a2, B
addi	$a2, $a2, 5
sw	$a2, a
lw	$a1, a
ble	$a1, 5, l2
l5:
jal	foo
sw	$a1, a
li 	$v0, 10
syscall
foo:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
lw	$a2, a
li	$v0, 1
move	$a0, $a2
syscall
sw	$a2, a
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
