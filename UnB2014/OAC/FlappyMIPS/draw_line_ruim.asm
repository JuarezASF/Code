desenhaLinha_ruim:
	#desenha uma linha de (x0,y0)=(a0,a1) ate (x1,y1)=(a2,a3)
	#a cor esta em 0($sp) 
	#altera fp! CUIDADO!!!
		
	move $fp, $sp # guarda ponto inicial da pilha
	addi $sp, $sp, -36 # abre espaco para 5 variaveis a serem restauradas
	sw $t1, 32($sp)
	sw $t0, 28($sp)
	swc1 $f2, 24($sp)
	swc1 $f1, 20($sp)
	swc1 $f0, 16($sp)
	sw $s2, 12($sp)
	sw $s1, 8($sp)
	sw $s0, 4($sp)
	sw $ra, 0($sp)
		
	# |	registrador	|	variável	|
	# |	t0		|	x_atual		|	
	# |	t1		|	y_atual		|
	# |	s0		|	cor		|
	# |	s1		|	x_final		|
	# |	s2		|	y_final		|
	# |	f0		|	erro_atual	|
	# |	f1		|	incremento	|
	
	
	lw $s0, 0($fp) #carrega a cor em t0
	
	#calcula inclinação da curva
	sub $s2, $a3, $a1 #s2 = y1 - y0
	mtc1 $s2, $f0  
	cvt.s.w $f0, $f0#f0 = delta Y
	
	sub $t0, $a2, $a0 #t0 = x1 - x0
	mtc1 $t0, $f1
	cvt.s.w $f1, $f1#f1 = delta X
	
	div.s $f1, $f0, $f1
	abs.s $f1, $f1 #f0 = m = inclinacao = abs(delta Y/delta X)
	
	l.s $f0, s_zero # f1 = erro = 0(estado inicial)
		
	move $t0, $a0 # t0 = x = x0 (estado inicial)
	move $t1, $a1 # t1 = y = y0 (estado inicial)
	move $s1, $a2 # s1 = x1 (x_fim)
	move $s2, $a3 # s2 = y1 (y_fim)
	
	desenhaLinha_for1:
		beq $t0, $s1, desenhaLinha_for1_end
		move $a0, $t0
		move $a1, $t1
		move $a2, $s0
		jal SetPixel # plot(x_atual, y_atual)
		
		add.s $f0, $f0, $f1 #erro_atual += incremento
		
		l.s $f2, s_meio # f2 = 0.5
		c.le.s $f2, $f0
		bc1f desenhaLinha_fo1_if1_false
			addi $t1, $t1, 1
			l.s $f2, s_neg_one
			add.s $f0, $f0, $f2 #erro = erro + (-1)
		desenhaLinha_fo1_if1_false:
		 
		
		addi $t0, $t0, 1 # x += 1
		j desenhaLinha_for1 #loop
	desenhaLinha_for1_end:
	

	lw $t1, 32($sp)
	lw $t0, 28($sp)
	lwc1 $f2, 24($sp)
	lwc1 $f1, 20($sp)
	lwc1 $f0, 16($sp)
	lw $s2, 12($sp)
	lw $s1, 8($sp)
	lw $s0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 36 # restaura pilha original
	
	jr $ra