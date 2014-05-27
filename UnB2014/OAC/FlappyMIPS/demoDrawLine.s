.data  
	bitmap : 	.word 0x10040000
	bitmap_x_max : 	.word 256 # width in pixels
	bitmap_y_max : 	.word 256 # heigh in pixels
	s_zero : 	.float 0.0
	s_meio : 	.float 0.5
	s_neg_one : 	.float -1.0
	w_one:		.word 1
	w_neg_one:	.word -1
	w_two:		.word 2
	w_68:		.word 256
.text
	
	#valores fixos em cada chamda
	li   $a0, 32	
	li   $a1, 32
	addi $sp, $sp, -4
	li $t0, 0x000FFFFF 
	sw $t0, 0($sp)# coloca cor na pilha


	move $t0, $zero #i = 0
	lw   $s0, w_68 #final do loop
	main_for:
		slt $t1, $t0, $s0 #atual < máximo?	
		beqz $t1, main_for_end
	
		li   $a0, 128
		li   $a1, 128
		move $a2, $t0
		li   $a3, 0
		
		jal desenhaLinha_bom

		li   $a0, 128	
		li   $a1, 128
		move $a2, $t0
		li   $a3, 256
		
		jal desenhaLinha_bom

		
		addi $t0, $t0, 32
		j main_for
	main_for_end:	

	li $t0, 0x00000FFF 
	sw $t0, 0($sp)# coloca cor na pilha


	move $t0, $zero #i = 0
	lw   $s0, w_68 #final do loop
	main_for2:
		slt $t1, $t0, $s0 #atual < máximo?	
		beqz $t1, main_for2_end
	
		li   $a0, 128
		li   $a1, 128
		li   $a2, 0
		move $a3, $t0
				
		jal desenhaLinha_bom

		li   $a0, 128	
		li   $a1, 129
		li   $a2, 256
		move $a3, $t0
				
		jal desenhaLinha_bom

		
		addi $t0, $t0, 32
		j main_for2
	main_for2_end:	
	
	
	
	

	
	li $v0, 10
	syscall
	
SetPixel:
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
	


desenhaLinha_bom:
	#desenha uma linha de (x0,y0)=(a0,a1) ate (x1,y1)=(a2,a3)
	#a cor esta em 0($sp) 
	#altera fp! CUIDADO!!!
		
	move $fp, $sp # guarda ponto inicial da pilha
	addi $sp, $sp, -52 # abre espaco para 5 variaveis a serem restauradas
	sw $t4, 48($sp)
	sw $t3, 44($sp)
	sw $t2, 40($sp)
	sw $t1, 36($sp)
	sw $t0, 32($sp)
	sw $s6, 28($sp)
	sw $s5, 24($sp)
	sw $s4, 20($sp)
	sw $s3, 16($sp)
	sw $s2, 12($sp)
	sw $s1, 8($sp)
	sw $s0, 4($sp)
	sw $ra, 0($sp)
		
	# |	registrador	|	variável	|
	# |	t0		|	x_atual		|	
	# |	t1		|	y_atual		|
	# |	t2		|	erro_atual	|	
	# |	t3		|	erro_2|aux1	|
	# |	t4		|	aux2		|
	# |	s0		|	cor		|
	# |	s1		|	x_final		|
	# |	s2		|	y_final		|
	# |	s3		|	dx		|
	# |	s4				dy|-dy		|
	# |	s5		|	sx		|
	# |	s6		|	sy		|
	
	
	lw $s0, 0($fp) #carrega a cor em s0
	
	#calcula DX e DY
	sub $s3, $a2, $a0 #s3 = x1 - x0
	abs $s3, $s3 #s3 = dx = |x1 - x0|

	sub $s4, $a3, $a1 #s2 = y1 - y0
	abs $s4, $s4 #s4 = dy = |y1 - y0|

	# if x0 < x1 then sx := 1 else sx := -1
	slt $t0, $a0, $a2 # t0 = (x0 < x1)?
	beq $t0, $zero, desenhaLinha_if1_else  
	desenhaLinha_if1_then:
		lw $s5, w_one
		j desenhaLinha_if1_exit
	desenhaLinha_if1_else:
		lw $s5, w_neg_one
	desenhaLinha_if1_exit:

	# if y0 < y1 then sy := 1 else sy := -1
	slt $t0, $a1, $a3 # t0 = (y0 < y1)?
	beq $t0, $zero, desenhaLinha_if2_else  
	desenhaLinha_if2_then:
		lw $s6, w_one
		j desenhaLinha_if2_exit
	desenhaLinha_if2_else:
		lw $s6, w_neg_one
	desenhaLinha_if2_exit:
	
	sub $t2, $s3, $s4 #  err := dx-dy
		
	lw $t0, w_neg_one
	mult $t0, $s4
	mflo $s4 # s4 = -dy
		
	move $t0, $a0 # t0 = x = x0 (estado inicial)
	move $t1, $a1 # t1 = y = y0 (estado inicial)
	move $s1, $a2 # s1 = x1 (x_fim)
	move $s2, $a3 # s2 = y1 (y_fim)
	
	desenhaLinha_for1:
		#plot(x0,y0)
		move $a0, $t0
		move $a1, $t1
		move $a2, $s0
		jal SetPixel # plot(x_atual, y_atual)
		
		#testa saida do loop
		sub $t3, $s1, $t0 #t3 = x_final - x_atual
		sub $t4, $s2, $t1 #t4 = y_final - y_atual
		add $t3, $t3, $t4 #se (x_atual == x_final) && (y_atual == y_final), t3 = 0
		beqz $t3, desenhaLinha_for1_end # if x0 = x1 and y0 = y1 exit loop
		
		lw $t3, w_two
		mult $t3, $t2
		mflo $t3 #t3 = err2 = 2*Erro_atual 
		
		slt $t4, $s4, $t3 # -dy < err2 ?
		beqz $t4, desenhaLinha_for1_if1_end
		desenhaLinha_for1_if1_then:
			add $t2, $t2, $s4 # t2 = erro_atual = erro_atual + (-dy)
			add $t0, $t0, $s5 # x_atual += sx
		desenhaLinha_for1_if1_end:

		slt $t4, $t3, $s3 # err2 < dx ?
		beqz $t4, desenhaLinha_for1_if2_end
		desenhaLinha_for1_if2_then:
			add $t2, $t2, $s3 # t2 = erro_atual = erro_atual + dx
			add $t1, $t1, $s6 # y_atual += sy
		desenhaLinha_for1_if2_end:
		
		j desenhaLinha_for1 #loop
	desenhaLinha_for1_end:
	

	
	lw $t4, 48($sp)
	lw $t3, 44($sp)
	lw $t2, 40($sp)
	lw $t1, 36($sp)
	lw $t0, 32($sp)
	lw $s6, 28($sp)
	lw $s5, 24($sp)
	lw $s4, 20($sp)
	lw $s3, 16($sp)
	lw $s2, 12($sp)
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 52
	
	jr $ra

