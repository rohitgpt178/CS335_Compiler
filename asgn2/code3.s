.data
a:	.word	0
B:	.word	0
.text
main:
l1:
li	$a1, 5
li	$a2, 3
mul	$a1, $a2, 5
sw	$a1, a
sw	$a2, B
lw	$a3, a
ble	$a3, 10, l6
l5:
jal	foo
l6:
lw	$t1, a
li	$v0, 1
move	$a0, $t1
syscall
sw	$t1, a
li 	$v0, 10
syscall
foo:
	addi	$sp,$sp,-4
	sw	$t0, 0($sp)
li	$t2, 10
sw	$t2, a
lw 	$t0, 0($sp)
addi 	$sp,$sp,4
jr 	$ra
