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
ble	$a2, 5, l2
sw	$a2, a
l5:
jal	foo
li 	$v0, 10
syscall
foo:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
	li $v0, 1
lw $a0, a
syscall
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
