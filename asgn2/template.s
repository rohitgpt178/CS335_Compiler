.data
x: .word 701
y: .word 701

.text
main:
   lw $t0,x              #loads $t0 with 701
   lw $t1,y              #loads $t1 with 701
   bge $t0,$t1,end       #compares $t0 and $t1, if equal, jump to address [end]

end:
   #the code segment for end label
