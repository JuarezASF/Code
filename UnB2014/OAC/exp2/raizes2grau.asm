
#Estado atual
#	* %f tá bom ou tem que ser %.4f ?
#

.data
	str_entrada : .asciiz "Consideramos o polinômio p(x) = a*x^2 + b*x + c. \n\n"
	str_entre_a : .asciiz " Entre com o coeficiente a: "
	str_entre_b : .asciiz " Entre com o coeficiente b: "
	str_entre_c : .asciiz " Entre com o coeficiente c: "

	newl: .asciiz "\n"
	tab: .asciiz "\t"	
	plus: .asciiz " + "
	minus: .asciiz " - "
	imag: .asciiz " i "
	
	str_1: .asciiz "\n\nAs raízes do polinômio são: \n \tR(1) = "
	str_2: .asciiz "R(2) = "

	caso_deg_str1: .asciiz "So existe uma raiz: \n \tR(1) = "
	caso_deg_str2: .asciiz "Nao existe raiz no plano complexo \n"
	caso_deg_str3: .asciiz "Todos os pontos no plano complexo são raízes \n"
	
	#Um jeito mais maroto de se obter alguns numeros
	d_const4:  .double 4.0
	d_const0neg: .double -0.0
.text

main:
	jal	read_pol		#Leio e volto com A em sp, B em sp+4 e C em sp+8
	lw	$s0, 0($sp)
	lw	$s1, 4($sp)
	lw	$s2, 8($sp)
	addi	$sp, $sp, 12
	
	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s2
	jal	casos_degenerados	#A0, A1 e A2 são os argumentos (format: F.P.)
	bne	$v0, $zero, exit_program
	
	move	$a0, $s0
	move	$a1, $s1
	move	$a2, $s2
	jal	calcula_raizes_grau_2	#A0, A1 e A2 são os argumentos (format: F.P.)
	
	lw	$a0, 0($sp)
	lw	$a1, 4($sp)
	lw	$a2, 8($sp)
	lw	$a3, 12($sp)
	addi	$sp, $sp, 16
	jal	mostra_raizes_grau_2	#A0, A1, A2 e A3 são os argumentos (format: F.P.)
	
	j exit_program

#recebe: nada
#retorna: sp(0) = a ; sp(4) = b ; sp(8) = c	
read_pol: 	
	addi	$sp, $sp, -12
	
	#Imprime a mensagem pedindo os dados.
	li	$v0, 4
	la	$a0, str_entrada
	syscall
	
	#Imprime a mensagem pedindo a
	li	$v0, 4
	la	$a0, str_entre_a
	syscall
	
	#Lê float e salva na pilha
	li	$v0, 6
	syscall
	swc1	$f0, 0($sp)
	
	#pede coeficiente b
	li	$v0, 4
	la	$a0, str_entre_b
	syscall	
	
	#Lê float e salva na pilha
	li	$v0, 6
	syscall
	swc1	$f0, 4($sp)
	
	#pede coeficiente c
	li	$v0, 4
	la	$a0, str_entre_c
	syscall	
	
	#Lê float e salva na pilha
	li	$v0, 6
	syscall
	swc1	$f0, 8($sp)
	
	jr $ra


#recebe: A0 = A, A1=B, A2=C
#retorna 0 se a0!= 0, 1 se a1!=0
casos_degenerados:
	
	#Salva estado inicial
	addi	$sp, $sp, -8
	swc1	$f0, -4($sp)
	swc1	$f12, 0($sp)
	
	#Se for um caso degenerado, vá para caso_degenerado1, caso contrário restaura e retorna
	mtc1	$a0, $f0
	sub.s	$f12, $f12, $f12
	c.eq.s	0, $f12, $f0
	bc1t	caso_degenerado1	#se a=0 va para algum dos casos, se não libera a pilha e volta
	
	#Restaura estado inicial e retorna
	lwc1	$f0, -4($sp)
	lwc1	$f12, 0($sp)
	addi	$sp, $sp, 8
	li	$v0, 0
	jr	$ra

caso_degenerado1:
	
	#Checando se este é o caso linear
	mtc1	$a1, $f0
	c.eq.s	0, $f12, $f0
	bc1t	caso_degenerado2
	
	#Raiz = -c/b
	#mtc1	$a2, $f12	
	mtc1	$a2, $f12
	l.s	$f13, d_const0neg
	c.eq.s	$f12, $f13
	neg.s	$f12, $f12
	bc1t	prob_minus0_1
	neg.s	$f12, $f12
prob_minus0_1:
	neg.s	$f12, $f12
	div.s	$f12, $f12, $f0
		
	#Imprime a mensagem da raiz
	li	$v0, 4
	la	$a0, caso_deg_str1
	syscall
	li	$v0, 2
	syscall
	
	#Retorna estado inicial e finaliza
	lwc1	$f0, -4($sp)
	lwc1	$f12, 0($sp)
	addi	$sp, $sp, 8
	li	$v0, 1
	jr	$ra
	
caso_degenerado2:
	
	#Confirma se c=0 ou nao
	mtc1	$t2, $f0
	c.eq.s	0, $f12, $f0
	
	la	$a0, caso_deg_str3
	bc1t	caso_degenerado3	#se c=0 pula a prox instrução
	la	$a0, caso_deg_str2
caso_degenerado3:
	li	$v0, 4
	syscall
	
	#Retorna estado inicial e finaliza
	lwc1	$f0, -4($sp)
	lwc1	$f12, 0($sp)
	addi	$sp, $sp, 8
	li	$v0, 1
	jr	$ra

calcula_raizes_grau_2:
#recebe: coeficientes a,b,c em A0,A1,A2 (single)
#retorna: 0($sp)=real1 ; 4($sp)=complex1 ; 8($sp)=real2 ; 12($sp) = complex2
	
	#Salvando o estado inicial
	addi	$sp, $sp, -32
	swc1	$f0, 0($sp)
	swc1	$f1, 4($sp)
	swc1	$f2, 8($sp)
	swc1	$f3, 12($sp)
	swc1	$f4, 16($sp)
	swc1	$f6, 20($sp)
	swc1	$f6, 24($sp)
	swc1	$f7, 28($sp)
	
	# conversão para double
	mtc1	$a0, $f0
	mtc1	$a1, $f2
	mtc1	$a2, $f4
	cvt.d.s	$f0, $f0
	cvt.d.s	$f2, $f2
	cvt.d.s	$f4, $f4
	
	#f4 = delta (f6=b^2)
	l.d   $f6, d_const4
	mul.d $f4, $f4, $f6
	mul.d $f4, $f4, $f0
	mul.d $f6, $f2, $f2
	sub.d $f4, $f6, $f4
	
	#Seletor de delta>0 ou delta<0
	sub.d $f6, $f6, $f6
	c.lt.d $f4, $f6
	bc1t calcula_raizes_grau_2__delta_negativo
	
	#DELTA POSITIVO AQUI!
	sqrt.d	$f4, $f4
	sub.d	$f6, $f4, $f2
	add.d	$f4, $f2, $f4
	neg.d	$f4, $f4
	add.d	$f0, $f0, $f0
	div.d	$f4, $f4, $f0		#f0 = [-b + sqrt (delta)] /2a
	div.d	$f6, $f6, $f0		#f2 = [-b - sqrt (delta)] /2a
		
	#converte resultado para single
	cvt.s.d $f0, $f6
	cvt.s.d $f1, $f4		
	mfc1	$v0, $f0
	mfc1	$v1, $f1
	
	#Restura o estado inicial
	lwc1	$f0, 0($sp)
	lwc1	$f1, 4($sp)
	lwc1	$f2, 8($sp)
	lwc1	$f3, 12($sp)
	lwc1	$f4, 16($sp)
	lwc1	$f6, 20($sp)
	lwc1	$f6, 24($sp)
	lwc1	$f7, 28($sp)
	addi	$sp, $sp, 16		#vou deixar 4 espaços para deixar os resultados
	
	sw	$v0, 0($sp)
	sw	$zero, 4($sp)
	sw	$v1, 8($sp)
	sw	$zero, 12($sp)	
	li	$v0, 1			#o roteiro pediu
	jr	$ra
	
#DELTA MENOR QUE ZERO
calcula_raizes_grau_2__delta_negativo:
	neg.d	$f4, $f4		#f4 = -delta
	sqrt.d	$f4, $f4
	add.d	$f0, $f0, $f0
	div.d	$f6, $f4, $f0		#f6 = parte imaginaria
	neg.d	$f2, $f2
	div.d	$f2, $f2, $f0		#f2 = parte real
					
	#converte resultado para single
	cvt.s.d $f0, $f2
	cvt.s.d	$f1, $f6
	mfc1	$a0, $f0		#r1
	mfc1	$a1, $f1		#im1
	neg.s	$f1, $f1
	mfc1	$a2, $f1		#im2
	
	#Restura o estado inicial
	lwc1	$f0, 0($sp)
	lwc1	$f1, 4($sp)
	lwc1	$f2, 8($sp)
	lwc1	$f3, 12($sp)
	lwc1	$f4, 16($sp)
	lwc1	$f6, 20($sp)
	lwc1	$f6, 24($sp)
	lwc1	$f7, 28($sp)
	addi	$sp, $sp, 16		#vou deixar 4 espaços para deixar os resultados
	
	sw	$a0, 0($sp)
	sw	$a1, 4($sp)
	sw	$a0, 8($sp)
	sw	$a2, 12($sp)
	li	$v0, 1			#o roteiro pediu
	jr	$ra

mostra_raizes_grau_2:
#recebe: a0=real1; a1=im1; a2=real2; a3-im3
#faz: imprime na tela as raízes
	
	#salva status inicial
	addi	$sp, $sp, -8
	swc1	$f12, 0($sp)
	swc1	$f13, 4($sp)
	move	$t0, $a0		#libera o a0 pros syscalls
	
	#Mostra a parte real da raiz 1
	mtc1	$t0, $f12
	l.s	$f13, d_const0neg
	c.eq.s	0, $f12, $f13
	neg.s	$f12, $f12
	bc1t	0, prob_minus0_3
	neg.s	$f12, $f12
prob_minus0_3:
	li	$v0, 4
	la	$a0, str_1
	syscall
	li	$v0, 2
	syscall
	
	beq	$a1, $zero, pula_imaginario1
	
	#Mostra a parte imaginaria da raiz 1
	mtc1	$a1, $f12		#f12=im(r1)
	sub.s	$f13, $f13, $f13	#f13=0
	c.lt.s	0, $f12, $f13		
	
	la	$a0, minus
	neg.s	$f12, $f12
	
	bc1t	mostra_r1_minus	#se o sinal for negativo, eu mudei pra positivo so pra printar mais bonitinho
	la	$a0, plus
	neg.s	$f12, $f12
mostra_r1_minus:
	li	$v0, 4
	syscall
	li	$v0, 2
	syscall
	la	$a0, imag
	li	$v0, 4
	syscall
	
pula_imaginario1:
	
	#\n\t
	li $v0, 4
	la $a0, newl
	syscall
	li $v0, 4
	la $a0, tab
	syscall
	
	#Mostra a parte real da segunda raíz
	mtc1	$a2, $f12
	l.s	$f13, d_const0neg
	c.eq.s	$f12, $f13
	neg.s	$f12, $f12
	bc1t	prob_minus0_2
	neg.s	$f12, $f12
prob_minus0_2:
	li	$v0, 4
	la	$a0, str_2
	syscall
	li	$v0, 2
	syscall
	
	beq	$a3, $zero, exit_show_raizes
	
	#Mostra a parte imaginaria da segunda raiz
	mtc1	$a3, $f12		#f12=im(r2)
	sub.s	$f13, $f13, $f13	#f13=0
	c.lt.s	0, $f12, $f13		
	
	la	$a0, minus
	neg.s	$f12, $f12
	
	bc1t	mostra_r2_minus	#se o sinal for negativo, eu mudei pra positivo so pra printar mais bonitinho
	la	$a0, plus
	neg.s	$f12, $f12
mostra_r2_minus:
	li	$v0, 4
	syscall
	li	$v0, 2
	syscall
	la	$a0, imag
	li	$v0, 4
	syscall
	
exit_show_raizes:
	lwc1	$f12, 0($sp)
	lwc1	$f13, 4($sp)
	addi	$sp, $sp, 8
	jr	$ra

exit_program:
	li $v0, 10
	syscall