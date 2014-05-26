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
	
desenhaLinha:
	#desenha uma linha de (x0,y0)=(a0,a1) at� (x1,y1)=(a2,a3)
	#a cor est� em 0($sp) 
	addi $sp, $sp, -20
	sw $s2, 16($sp)
	sw $s1, 12($sp)
	sw $s0, 8($sp)
	sw $ra, 4($sp)
	sw $fp, 0($sp)
	
	#s0 = dx
	#s1 = dy
	#s2 = err
	#s3 = x1
	#s4 = y1

	move $fp, $sp
	lw $t0, 0($fp) #carrega a cor em t0
	move $t1, $a0 # t1 = x0
	move $t2, $a1 # t2 = y0
	move $s3, $a2 # s3 = x1
	move $s4, $a3 # s4 = y1
		      #s5 = sx ; 
		      #$s6 = sy
	
	slt $t3, $a0, $a2 # x0 < x1 ?
	beqz $t3, desenhaLinha_if2_else
			li $s5, 1 #se sim, sx = 1
		desenhaLinha_if2_else: 
			li $s5, -1 # se n�o, sx = -1
		desenhaLinha_if2_end:
	
	slt $t3, $a0, $a2 # y0 < y1 ?
	beqz $t3, desenhaLinha_if3_else
			li $s6, 1 #se sim, sx = 1
		desenhaLinha_if3_else: 
			li $s6, -1 # se n�o, sx = -1
		desenhaLinha_if3_end:

	
	sub $t1, $a2, $a0
	abs $s0, $t1 #s0 = abs(x1 - x0)
	
	sub $t1, $a3, $a1
	abs $s1, $t1 #s1 = abs(y1 - y0)
	
	sub $s2, $s0, $s1 # err = dx - dy
	
	desenhaLinha_loop:
	#desenha x0,yo atual
	move $a0, $t1
	move $a1, $t2
	move $a3, $t0
	jal setPixel # plot(x0,y0)
	
	#decide se continua ou n�o
	bne $t1, $s3, desenhaLinha_loop_continue
	bne $t2, $s4, desenhaLinha_loop_continue
	j desenhaLinha_loop_end 
	
	desenhaLinha_loop_continue:	
	li $t3, 2
	mult $t3, $s2 
	mflo $t3 #t3 = e2 = 2*err
	
	li $t4, -1
	mult $s1, $t4
	mflo $t4 #t4 = -1*dy
	
	slt $t5, $t4, $t3
	beqz $t5, desenhaLinha_loop_if1_end
		add  $s2, $s2, $t4 # err = err - dy 
		add $t1, $t1, $s5 # x0 = x0 + sx
	desenhaLinha_loop_if1_end:
	
	slt $t5, $t3, $s0
	beqz $t5, desenhaLinha_loop_if4_end
		add  $s2, $s2, $s0 # err = err + dx 
		add $t2, $t2, $s6 # y0 = y0 + sy
	desenhaLinha_loop_if4_end:
	
	j desenhaLinha_loop

	desenhaLinha_loop_end:
	

	lw $ra, 4($sp)
	lw $fp, 0($sp)
	addi $sp, $sp, 8	
	