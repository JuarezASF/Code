.data
	const05: .double 0.5
	const1: .double 1.0
	const9: .double 9.0
	const25: .double 25.0
	const2: .double 2.0
	const0: .double 0.0
.text

#TODAS AS ROTINAS EST�O FUNCIONANDO
main:
	l.d $f0, const2
	jal raiz_quadrada_positiva

	li $v0, 3
	mov.d $f12, $f30
	syscall

	j exit_program
		
raiz_quadrada_positiva:
#calcula a raíz quadrada de um número positivo pelo método da bisseção
#L = f2; M = f4, R = f6 (double)
#recebe x = f0	
#utiliza f0, f2, f4, f6, f8, f10, t0, t1, ra
#retorna sqrt(X) em f30


	addi $sp, $sp, -52
	sw   $ra, 48($sp)
	sw   $t0, 44($sp)
	sw   $t1, 40($sp)
	swc1 $f2, 36($sp)
	swc1 $f3, 32($sp)
	swc1 $f4, 28($sp)
	swc1 $f5, 24($sp)
	swc1 $f6, 20($sp)
	swc1 $f7, 16($sp)
	swc1 $f8, 12($sp)
	swc1 $f9, 8($sp)
	swc1 $f10, 4($sp)
	swc1 $f11, 0($sp)
	
	#guarda argumento de entrada em f8
	mov.d $f10, $f0
	
	#se t0 =i > 100 => termina
	li $t0, 0
	
	#L = 0;
	l.d $f2, const0

	#R = x	
	mov.d $f6, $f0

	for1:
		li $t1, 100
		beq $t0, $t1, exit_sqrt_positiva #sai se i==100
		addi $t0, $t0, 1 #i++
	
		#f4 = M = (L+R)*0.5
		add.d $f4, $f2, $f6	
		l.d $f8, const05
		mul.d $f4, $f4, $f8
	
		#calcula M^2 em f30
		mov.d $f0, $f4
		jal square
	
		#M^2 == x? se sim, retorna M
		c.eq.d $f30, $f10
		bc1t	exit_sqrt_positiva

		#se M^2 < x => L = M
		#se M^2 > x => R = M
		c.lt.d $f30, $f10
			bc1t	for1_case_1
			bc1f	for1_case_2
		

		#se M^2 > x => D = M
		for1_case_1:
			mov.d $f2, $f4
			j for1		
		for1_case_2:
			mov.d $f6, $f4
			j for1
		
	exit_sqrt_positiva:
	#retorna M = f4 em f30
	mov.d $f30, $f4
	
	#restaura estado 
	lw   $ra, 48($sp)
	lw   $t0, 44($sp)
	lw   $t1, 40($sp)
	lwc1 $f2, 36($sp)
	lwc1 $f3, 32($sp)
	lwc1 $f4, 28($sp)
	lwc1 $f5, 24($sp)
	lwc1 $f6, 20($sp)
	lwc1 $f7, 16($sp)
	lwc1 $f8, 12($sp)
	lwc1 $f9, 8($sp)
	lwc1 $f10, 4($sp)
	lwc1 $f11, 0($sp)
	addi $sp, $sp, 52

	jr $ra
square:
#recebe x(double) em f0 e retorna x^2 em f30
	mul.d $f30, $f0, $f0
	jr $ra 	

exit_program:
	li $v0, 10
	syscall	

	
