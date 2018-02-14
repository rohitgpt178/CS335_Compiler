main:
li	$t1,5
li 	$t2,10
mul	$t1,$t1,$t2
li	$v0, 1
move	$a0, $t1
syscall
li 	$v0, 10
syscall
