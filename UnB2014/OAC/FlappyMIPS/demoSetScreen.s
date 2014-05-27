.data  
	bitmap : .word 0x10040000
	bitmap_x_max : .word 64 # width in pixels
	bitmap_y_max : .word 64 # heigh in pixels
.text

	lw $s1, bitmap # endereco base do bitmap
	li $s2, 0x000FFFFF #cor a ser salva
	lw  $v0, bitmap_x_max # numero de colunas(x_max)
	lw  $v1, bitmap_y_max # numero de linhas(y_max)
	
	move $t0, $zero # i = 0

	
	loop_i:
		beq $t0, $v0, loop_i_end
		move $t1, $zero # j = 0
	loop_j:
		beq $t1, $v1, loop_j_end
		
		move $a0, $t0
		move $a1, $t1
		move $a2, $s2
		jal setPixel
		
		addi $t1, $t1, 1 #j++
		j loop_j
	loop_j_end:
	addi $t0, $t0, 1 #i++
	j loop_i
	loop_i_end:
	
	


	li $v0, 10
	syscall
	
setPixel:
	#recebe posicaoo x em $a0, y em $a1 e cor em $a2
	# pinta o bit_map com a cor indicada no pixel indicado
	
	addi $sp, $sp, -8
	sw   $t0, 4($sp)
	sw   $t1, 0($sp)
	
	lw $t0, bitmap # endereco base
	lw $t1, bitmap_x_max# x_max: n de colunas maxima
	
	# t1 = y*n_linhas
	mult $a1, $t1
	mflo $t1 # t1 = y*colunas
	
	# t1 = y*n_colunas + x
	add $t1, $t1, $a0 # t1 = y*n_colunas + x
	sll $t1, $t1, 2 # t1 = 4*(y*n_colunas + x)
	add $t1, $t1, $t0# t1 = base + 4*(y*n_colunas + x)
	
	sw $a2, 0($t1)
	
	
	lw   $t0, 4($sp)
	lw   $t1, 0($sp)
	addi $sp, $sp, 8
	
	jr $ra
