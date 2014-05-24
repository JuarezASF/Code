.data  
	bitmap : .word 0x10010000
	bitmap_x_max : .word 64
	bitmap_y_max : .word 128
.text

	la $s1 0x10010000 # endere�o base
	#li $s2 0x00000007
	li $s2 0x000FFFFF #cor a ser salva
	li $v0, 128 # n�mero de linhas
	li $v1, 128 # n�mero de colunas, ou ao contr�rio
	
	move $t0, $zero # i = 0
	move $t1, $zero # j = 0
	
	loop_i:
		beq $t0, $v0, loop_i_end
	loop_j:
		beq $t1, $v1, loop_j_end
		
		move $a0, $t0
		move $a1, $t1
		move $a2, $s2
		jal paint_pixel
		
		addi $t1, $t1, 1 #j++
		j loop_j
	loop_j_end:
	addi $t0, $t0, 1 #i++
	j loop_i
	loop_i_end:


	li $v0, 10
	syscall
	
paint_pixel:
	#recebe posicaoo x em $a0, y em $a1 e cor em $a2
	# pinta o bit_map com a cor indicada no pixel indicado
	
	addi $sp, $sp, -8
	sw   $t0, 4($sp)
	sw   $t1, 0($sp)
	
	la $t0 0x10010000 # endereco base
	lw $t1, bitmap_y_max# numero de linhas
	
	# t1 = x*n_linhas
	mult $a0, $t1
	mflo $t1 # t1 = x*n_linhas
	
	# t1 = x*n_linhas + y
	add $t1, $t1, $a1 # t1 = x*n_linhas + y
	sll $t1, $t1, 2 # t1 = 4*(x*n_linhas + y)
	add $t1, $t1, $t0# t1 = base + 4*(x*n_linhas + y)
	
	sw $a2, 0($t1)
	
	
	lw   $t0, 4($sp)
	lw   $t1, 0($sp)
	addi $sp, $sp, 8
	
	jr $ra
	
