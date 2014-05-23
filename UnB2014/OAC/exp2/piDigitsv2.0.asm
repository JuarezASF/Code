# O QUE QUEREMOS FAZER:
# 1.O objetivo dessa versão é tornar o código mais eficiente, reduzindo as chamadas sucessivas de subrotinas.
# Então em vez de usarmos uma rotina para calcular o endereço, calcularemos ela diretamente.
#
# 2.Além disso, queremos imprimir os resultados de forma mais clara. Queremos ver na tela algo do tipo 3.1415....
#
# 3.Se possível, quero aprender a utilizar alocação dinâmica
#
# 4.Além disso, cada dígito da pilha vai de 0-9, podendo ser representado em apenas 1 byte. 
# Na versão anterior do código todos os números são words, disperdissamos assim quantidades absurdas de memória
#
# 5.Outro problema a melhorar: Os tamanhos ods vetores. Apenas A[] deve ser 20n/3, os outros devem ser tamanho n


#O QUE FOI FEITO ATÉ AGORA: NADA

.data
	str_entrada : .asciiz "Entre com o numero de casas a serem calculadas: "
	str_1 : .asciiz "O tamanho do array necessario para calcular essa precisao sera: "
	str_2 : .asciiz "O vetor inicializado é :\n\t"	
	str_3 : .asciiz "O vetor A[] é :\n\t"
	str_4 : .asciiz "O vetor preDigits[] é :\n\t"	
	str_5 : .asciiz "O vetor piDigits[] é :\n\t"
	newl: .asciiz "\n"
	tab: .asciiz "\t"	
	newl_tab: .asciiz "\n\t"
	space: .asciiz " "	
.text

main:

	
	
	#imprime string de entrada
	li $v0, 4 
	la $a0 str_entrada
	syscall
	
	#la tamanho de casas a serem calculadas
	li $v0, 5
	syscall
	move $s0, $v0 #s0 = n

	#calcula tamanho do array necessario: tamanho = 10*n/3
	li $t0, 10
	mult $t0, $s0
	mflo $t1 # t1 = 10*n
	li $t0, 3
	div  $t1, $t0
	mflo $s1 # s1 = 10*n/3 : tamanho do vetor necessario
	addi $s1, $s1, 1
	
	#imprime msg para apresentar tamanho do vetor necessário
	li $v0, 4
	la $a0, str_1
	syscall
	#imprimi nova linha com tabulacao
	li $v0, 4
	la $a0, newl_tab
	syscall
	#imprime tamanho necessário calculado
	li $v0, 1
	move $a0, $s1
	syscall
	#imprimi nova linha
	li $v0, 4
	la $a0, newl
	syscall
	
	jal calcula_pi
	
	j exit_program

calcula_pi:
	#fp aponta para o ponto onde a pilha deve retornar ao final
	move $fp, $sp
	sw $ra, -4($fp)
	addi $sp ,$sp, -4
	
	#step 1: inicializa vetores
	jal calcula_pi_inicializa_vetores
	#essa função coloca em :
		#s2: A[], tamanho dado por $s1, todas as entradas em 2
		#s3:  preDigits[], tamanho 0, incializados em -1
		#s4:  piDigits[], tamanho 0, incializados em -1
		#todos eles podem ter, possivelmente, o tamanho necessário dado por $s1
		#TODOS eles estão na pilha, tendo sido deixado reservado espaço para crescerem até tamanho máximo
		#tamanho máximo dado em $s1
		#ideia: o número de pré-digitos e pi-digitos não pode passar do número de casas utilizadas para conta
		#em geral, o tamanho de piDigitos será menor que o tamanho de casas utilizadas
	
	li $s7, 0 #s7 = 1:n
	addi $s0, $s0, 1
	calcula_pi_loop:
		#continua no loop?
		beq $s7, $s0, calcula_pi_loop_exit #se i == n : saia

		#step 2.1: multiplica por 10
		move $a0, $s2
		li $a1, 10
		jal vetor_dot_escalar
		
		#step 2.2: regulariza de A[i = n-1:1]
		move $t0, $s1
		addi $t0, $t0, -1 #t0 = j = n-1:1  : indice de vetor
		calcula_pi_loop_reduz:
			beq $t0, $zero, calcula_pi_loop_reduz_exit #sai se chegou no primeiro indice do vetor
			addi $t1, $t0, 1 #indice = indice no vetor + 1 
			
			#pega A[i]
			move $a0, $s2
			move $a1, $t0
			jal vetor_get_i_value
			move $a0, $v0
			
			#pega t2 = 2*indice-1
			add $t2, $t1, $t1 #t2 = 2*indice
			addi $t2, $t2, -1#t2 = 2*indice - 1
			move $a1, $t2
			
			#reduz A[i], mod 2*indice -1		
			jal reduz#Q = v0 e R = v1
			move $a0, $s2
			move $a1, $t0
			move $a2, $v1
			jal vetor_set_i_value

			# A[i-1]+=carry		
			mult $v0,$t0 # carry = q*(indice-1) = q*(indice de vetor)
			mflo $t2#t2 = carry 
			move $a2, $t2
			move $a0, $s2
			addi $t2, $t0, -1 # t1= indice no vetor - 1
			move $a1, $t2
			jal vetor_add_to_i_value
						
			addi $t0, $t0, -1 #indice_vetor --
			
			j calcula_pi_loop_reduz #loop_reduz

		calcula_pi_loop_reduz_exit:
		
		#step2.3: calcula próximo pré-digito
		#pega A[0]
		move $a0, $s2
		li   $a1, 0
		jal vetor_get_i_value
		move $a0, $v0
	
		#reduz A[0], mod 10
		li $a1, 10				
		jal reduz#Q = v0 e R = v1
		move $a0, $s2
		li   $a1, 0
		move $a2, $v1
		jal vetor_set_i_value

		# t0 = q		
		move $t0, $v0
		#decide qual caso
		li $t1, 9
		beq $t0, $t1, calcula_pi_loop_case9
		li $t1, 10
		beq $t0, $t1, calcula_pi_loop_case10
		j calcula_pi_loop_else
		
		calcula_pi_loop_case9:
			#predigits.add(t0)
			move $a0, $s3
			move $a1, $t0
			jal vetor_add_int
			j calcula_pi_loop_case_exit
			
		calcula_pi_loop_case10:
			#q = 0
			li $t0, 0
			#adiciona 1 a todos os preDigitos(9->0)
			move $a0, $s3
			li   $a1, 1 
			jal vetor_add_X_to_each_entry
			
			#piDigits.add(preDigits()
			move $a0, $s3
			move $a1, $s4
			jal vetor_add_vetor_int
			
			#esvazia predigitos
			move $a0, $s3
			jal vetor_clear
			
			#adicoina q=0 ao preDigits
			move $a0, $s3
			move $a1, $t0
			jal vetor_add_int
			
			j calcula_pi_loop_case_exit
			
		calcula_pi_loop_else:
			#piDigits.add(preDigits()
			move $a0, $s3
			move $a1, $s4
			jal vetor_add_vetor_int
			
			#esvazia predigitos
			move $a0, $s3
			jal vetor_clear
			
			#adicoina q ao preDigits
			move $a0, $s3
			move $a1, $t0
			jal vetor_add_int
			
			j calcula_pi_loop_case_exit
		calcula_pi_loop_case_exit:
																				

		#loop calcula_pi_loop, n vezes
		addi $s7, $s7, 1 #i++
		j calcula_pi_loop

		
	calcula_pi_loop_exit:
	
		jal mostra_dados_atuais
		
		
	calcula_pi_exit:
		#restaura ra e sp
		lw $ra, -4($fp)
		#a pilha não está sendo restaurada! cuidado!!
		#também não podemos restaurá-la pois pi-digitos está nela, não sei bem aonde
		
		jr $ra


calcula_pi_inicializa_vetores:
#cria vetores a serem utilizados e coloca-os na pilha
#todos os vetores podem chegar a ter o mesmo tamanho, há espaço para isso
#não gostei de ter os vetores na pilha, provavelmente eles deveriam ficar em outra parte da memória

	addi $sp $sp, -8
	sw $fp, 4($sp)
	sw $ra, 0($sp)
	move $fp, $sp #fp guarda informação para recuperar ra

	#abre espaço na pilha para A[] e seta todas as entradas para 2
	move $a0, $s1
	li   $a1, 2
	jal inicializa_array
	move $s2, $sp # S2 = A[]
	#os bytes de cima(endereços mais altos que valor de s2) contém os dados do vetor

	#abre espaço na pilha para o número de possíveis pré-digito
	move $a0, $s1
	li   $a1, -1 #inicializa com -1 para percebermos erros
	jal inicializa_array
	move $s3, $sp # S3 = preDigits
	sw   $zero, 0($s3) # o tamanho do vetor, no entanto é 0

	#abre espaço da pilha para possíveis números de pi
	move $a0, $s1
	li   $a1, -1 #inicializa com -1 para percebermos erros
	jal inicializa_array
	move $s4, $sp # S3 = piDigits
	sw   $zero, 0($s4) #o tamanho do vetor, no entando, é inicializado com zero
	
	
	#restaura pilha
	lw $ra, 0($fp)
	lw $fp, 4($fp)
	
	jr $ra
		
mostra_dados_atuais:
	addi $sp $sp, -4
	sw $ra, 0($sp)

	#mostra dados criados:
	#imprime msg de A[]
	li $v0, 4
	la $a0, str_3
	syscall

	#mostra A[]
	move $t0, $s2
	addi $a0, $t0, 4#pula o primeiro byte que indica o tamanho do vetor
	lw $a1, 0($s2)  #o primeiro byte indica o tamanho do vetor
	jal mostra_array

	#mostra predigitos
	#imprime msg de preDigitos
	li $v0, 4
	la $a0, str_4
	syscall

	#mostra preDigitos[]
	move $t0, $s3
	addi $a0, $t0, 4#pula o primeiro byte que indica o tamanho do vetor
	lw $a1, 0($s3)  #o primeiro byte indica o tamanho do vetor
	jal mostra_array
	
	#mostra piDigitos
	#imprime msg de piDigitos
	li $v0, 4
	la $a0, str_5
	syscall

	#mostra piDigitos
	move $t0, $s4
	addi $a0, $t0, 4#pula o primeiro byte que indica o tamanho do vetor
	lw $a1, 0($s4)  #o primeiro byte indica o tamanho do vetor
	jal mostra_array
	

	lw $ra, 0($sp)
	addi $sp $sp, 4
	
	jr $ra			
inicializa_array:
#recebe n = $a0, valor_base = $a1
#faz: 	coloca na pilha um array do tamanho indicado preenchido com valor_base em todas as entradas
#	salva na pilha também o tamanho do vetor criado logo após o vetor
#altera: $sp e os próximo 4*(n+1) bytes da pilha, $t0, $t1, $t2
#sp[0]:tamanho do array
#sp[1-n]:elementos do array

	#calcula tamanho da pilha a ser alterado
	sll $t0, $a0, 2 #multiplica por 4 para calcular tamanho em bytes do número n de words
	addi $t0, $t0, 4 #soma 4 bytes para acrescentar o tamanho do vetor da pilha
	
	#cria espaço da pilha
	sub $sp, $sp, $t0
	
	#salva tamanho do vetor na primeira entrada da pilha
	sw $a0, 0($sp)
	
	li $t1, 1#t1 = i = 1:n
	move $t0, $a1 # t0 = 2: valor a ser salvo no vetor
	inicializa_array_for_1:	
		sll $t2, $t1, 2 #$t2 = salto necessário para acessar A[i-1]; i = 1:n
		add $t2, $sp, $t2 #t2 = pilha + salto necessário
		sw $t0, 0($t2) # A[i-1] = 2
		
		#se i == n, pula para saída
		beq $t1, $a0, inicializa_array_exit
		
		addi $t1, $t1, 1 # i++
		j inicializa_array_for_1
		
	inicializa_array_exit:
	jr $ra

mostra_array:
#recepe endereço de memória com começo do vetor A em $a0
#recebe tamanho n do vetor em $a1
#imprmi do endereço em $a0, n inteiros subindo na pilha
#modifica: $t0, $t1, t2, t3, t4
# usa e restaura: v0, a0

	# t0: i; t1: salto; t2: indice final; t3:&A[0]; t4: &A[i]

	beq $a1, $zero, mostra_array_exit # se tamanho = 0, sai 

	move $t3, $a0#t3 contém endereço de começo do vetor
	li $t0, 0 #t0 = 1 = 0:n-1
	sub $t2, $a1, 1 # t2 = a1-1
	
	mostra_array_for1:
	#calcula salto
	sll $t1, $t0, 2 #calcula salto(= ix4)
	add $t4, $t3, $t1 # t4 = endereço base + salto
	
	#imprime A[i]
	li $v0,1
	lw $a0, 0($t4)
	syscall
	
	#imprime espaço
	li $v0,4
	la $a0, space
	syscall	
	
	#decide se continua ou não
	beq $t0, $t2, mostra_array_exit # se i == tamanho - 1, sai 
	
	addi $t0, $t0, 1 #i++
	j mostra_array_for1
	
	mostra_array_exit:
	
	#imprime espaço
	li $v0,4
	la $a0, newl
	syscall	
	
	jr $ra


reduz:
#recebe $a0 = n, $a1 = p
#calcula $v0 = Q e $v1 = R, tal que n = p*Q + R
#altera hi e lo
	div $a0, $a1 #calcula n/p; quociente está em LO e resto em HI
	mflo $v0
	mfhi $v1
	jr $ra
	
vetor_add_int:
#recebe: endereço base em $a0, elemento a ser adicionaod em $a1
#supoe que o tamanho do vetor é o elemento A[0]
# coloca elemento novo em $a0 = 4*(a0[0]_antigo + 1)
# adiciona um ao tamanho do vetor(em a0[0])
#utiliza: $t0
#como usar(exemplo):
	#adiciona elemento 12 ao vetor que começa em $s3. 
	#move $a0, $s3,
	#li  $a1, 12
	#jal vetor_add_int
	
	lw $t0, 0($a0) #carrega tamanho antigo do vetor em t0
	addi $t0, $t0, 1 #calcula novo tamanho do vetor
	sw $t0, 0($a0) #coloca novo tamanho no vetor
	sll $t0, $t0, 2 #calcula tamanho do salto
	add $t0, $t0, $a0 #calcula endereço para colocar novo elemento
	sw $a1, 0($t0) #salva novo elemento
	
	jr $ra
	
vetor_clear:
#recebe vetor em $a0 e seta tanaho(A[0]) para zero
#utiliza: nada

	sw $zero, 0($a0)
	jr $ra
	
vetor_set_size:
#recebe vetor em $a0 e tamanho em $a1
#utiliza: nada
	sw $a1, 0($a0)
	jr $ra
	
vetor_dot_escalar:
#recebe vetor em $a0, escalar em $a1 e realiza a multiplicação
#supoe que A[0] contém o tamanho do vetor
#utiliza $t1, $t2, $t3, $t4
#exemplo:
	#move $a0, $s2
	#li $a1, 2
	#jal vetor_dot_scalar
	
	addi $sp, $sp, -28
	sw $t0, 24($sp)
	sw $ra, 20($sp)
	sw $a1, 16($sp)
	sw $a2, 12($sp)
	sw $v0, 8($sp)
	sw $t2, 4($sp)
	sw $t1, 0($sp)

	li $t1, 0 #t1 = i = 0:size-1
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	beq $t2, $zero, vetor_dot_escalar_exit # se n ==0, sai
	
	move $t0, $a1 #t0 contém o valor a ser multiplicado por 
	
	vetor_dot_escalar_loop:
		beq $t1, $t2, vetor_dot_escalar_exit # sai se i == size
		#calcula salto

		#carrega A[i]
		move $a1, $t1
		jal vetor_get_i_value #v0 vai conter A[i]
		
		#realiza multiplicação
		mult $v0, $t0
		mflo $a2 #t4 = escalar*A[i]
		
		#salva valor calculado
		jal vetor_set_i_value
		
		addi $t1, $t1, 1 #i++
		
		j vetor_dot_escalar_loop
		
	
	vetor_dot_escalar_exit:
		#restaura estado
		lw $t0, 24($sp)
		lw $ra, 20($sp)
		lw $a1, 16($sp)
		lw $a2, 12($sp)
		lw $v0, 8($sp)
		lw $t2, 4($sp)
		lw $t1, 0($sp)
		addi $sp, $sp, 28
	
		jr $ra
	
vetor_get_i_adress:
#recebe A[] em $a0 e i em $a1
#supoe que 0(A) contém tamanho do vetor
#coloca em v0 o endereço de A[i]
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#utiliza e restaura t2, t3

	addi $sp, $sp, -8
	sw $t2, 4($sp)
	sw $t3, 0($sp)
		
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	beq $t2, $zero, vetor_get_i_adress_exit # se n ==0, sai
	
	slt $t2, $a1, $t2 # se i < n : ok, else: saia
	beq $t2, $zero,  vetor_get_i_adress_exit
	
	#calcula salto
	addi $t3, $a1, 1 #calcula salto em words
	sll $t3, $t3, 2 #calcula salto em bytes
	add $t3, $a0, $t3 #calcula endereço de A[i](i=0:size-1)
	
	move $v0, $t3
	
	vetor_get_i_adress_exit:
		#restaura estado
		lw $t2, 4($sp)
		lw $t3, 0($sp)
		addi $sp, $sp, 8	
		jr $ra

vetor_get_i_value:
#testado e parece funcionar
#recebe A[] em $a0 e i em $a1
#supoe que 0(A) contém tamanho do vetor
#coloca em v0 o conteudo de A[i]
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#chama vetor_get_i_adress para calcular endereço e calcula o valor
#utiliza e restaura t2
	#salva endereço de retorno
	addi $sp, $sp, -8
	sw $ra, 4($sp)
	sw $t2, 0($sp)

	#verifica casos degenerados	
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	beq $t2, $zero, vetor_get_i_value_exit # se n ==0, sai
	
	slt $t2, $a1, $t2 # se i < n : ok, else: saia
	beq $t2, $zero,  vetor_get_i_value_exit

	jal vetor_get_i_adress
	
	lw $v0, 0($v0)
	
	vetor_get_i_value_exit:	
		#restora estado
		lw $ra, 4($sp)
		lw $t2, 0($sp)
		addi $sp, $sp, 8
		
		jr $ra

vetor_set_i_value:
#testado e funcionando
#recebe A[] em $a0, i em $a1 e X em $a2
#supoe que 0(A) contém tamanho do vetor
#set  o conteúdo de A[i] para X
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#chama vetor_get_i_adress para calcular endereço e seta o valor
#utiliza e rastaura: v0, ra e t2
	#salva endereço de retorno
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $v0, 4($sp)
	sw $t2, 0($sp)
	
	#verifica casos degenerados	
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	beq $t2, $zero, vetor_set_i_value_exit # se n ==0, sai
	
	slt $t2, $a1, $t2 # se i < n : ok, else: saia
	beq $t2, $zero,  vetor_set_i_value_exit

	
	jal vetor_get_i_adress # coloca em v0 o valor desejado
	
	sw $a2, 0($v0)
	
	vetor_set_i_value_exit:	
		#restora estado
		lw $ra, 8($sp)
		lw $v0, 4($sp)
		lw $t2, 0($sp)
		addi $sp, $sp, 12
		
		jr $ra

vetor_add_to_i_value:
#recebe A[] em $a0, i em $a1 e X em $a2
#supoe que 0(A) contém tamanho do vetor
#set  o conteúdo de A[i]_new para A[i]_old + X
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#chama vetor_get_i_adress para calcular endereço e seta o valor
#utiliza e rastaura: v0, ra e t2
	#salva endereço de retorno
	addi $sp, $sp, -12
	sw $ra, 8($sp)
	sw $v0, 4($sp)
	sw $t2, 0($sp)
	
	#verifica casos degenerados	
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	beq $t2, $zero, vetor_add_to_i_value_exit # se n ==0, sai
	
	slt $t2, $a1, $t2 # se i < n : ok, else: saia
	beq $t2, $zero, vetor_add_to_i_value_exit

	
	jal vetor_get_i_adress # coloca em v0 o valor desejado
	
	lw $t2, 0($v0)#carrega dado antigo
	add $t2, $t2, $a2 #calcula dado novo
	sw $t2, 0($v0) #salva dado novo
	
	vetor_add_to_i_value_exit:	
		#restora estado
		lw $ra, 8($sp)
		lw $v0, 4($sp)
		lw $t2, 0($sp)
		addi $sp, $sp, 12
		
		jr $ra

vetor_add_X_to_each_entry:
#recebe A[] em $a0 e X em $a1 
#supoe que 0(A) contém tamanho do vetor
#para todo elemento de A[], acrescenta X. Se A[i}_novo == 10, A[i]_novo = 0
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#chama vetor_get_i_adress para calcular endereço e seta o valor
#utiliza e rastaura: v0, ra e t2
	addi $sp, $sp, -32
	sw $t3, 28($sp)
	sw $t0, 24($sp)
	sw $ra, 20($sp)
	sw $a1, 16($sp)
	sw $a2, 12($sp)
	sw $v0, 8($sp)
	sw $t2, 4($sp)
	sw $t1, 0($sp)

	li $t1, 0 #t1 = i = 0:size-1
	lw $t2, 0($a0) #t2 é o tamanho do vetor
	#testa caso degenerado
	beq $t2, $zero, vetor_dot_escalar_exit # se n ==0, sai
	
	move $t0, $a1 #t0 contém o valor a ser somado
	
	vetor_add_X_to_each_entry_loop:
		beq $t1, $t2, vetor_add_X_to_each_entry_exit # sai se i == size
		#calcula salto

		#carrega A[i]
		move $a1, $t1
		jal vetor_get_i_value #v0 vai conter A[i]
		
		#realiza soma
		add $a2, $v0, $t0
		li $t3, 10
		bne $a2, 10,  vetor_add_X_to_each_entry_loop_case_exit 
		li $a2, 0 #se novo valor == 10, novo valor = 0
		vetor_add_X_to_each_entry_loop_case_exit:
		
		#salva valor calculado
		jal vetor_set_i_value
		
		addi $t1, $t1, 1 #i++
		
		j vetor_add_X_to_each_entry_loop
		
	
	vetor_add_X_to_each_entry_exit:
		#restaura estado
		lw $t3, 28($sp)
		lw $t0, 24($sp)
		lw $ra, 20($sp)
		lw $a1, 16($sp)
		lw $a2, 12($sp)
		lw $v0, 8($sp)
		lw $t2, 4($sp)
		lw $t1, 0($sp)
		addi $sp, $sp, 32
	
		jr $ra

vetor_add_vetor_int: 
#recebe preDigits em $a0 e piDigits em $a1
#supoe que 0(A) contém tamanho do vetor
#acrescenta elementos de preDigits em piDigits, mantém pré-digits inalterado
#utilizamos notação de de C onde o primeir elemento é A[0] e o úlrimo é A[n-1]
#chama vetor_get_i_adress para calcular endereço e seta o valor
#utiliza e rastaura: v0, ra e t2
	addi $sp, $sp, -40
	sw $s0, 36($sp)
	sw $s1, 32($sp)
	sw $t3, 28($sp)
	sw $t0, 24($sp)
	sw $ra, 20($sp)
	sw $a1, 16($sp)
	sw $a2, 12($sp)
	sw $v0, 8($sp)
	sw $t2, 4($sp)
	sw $t1, 0($sp)

	move $s0, $a0 #s0 recebe predigitos
	move $s1, $a1#s1 recebe piDigitos

	li $t1, 0 #t1 = i = 0:size-1
	lw $t2, 0($s0) #t2 é o tamanho do vetor preDigits
	lw $t3, 0($s1) #t2 é o tamanho do vetor piDigits
	#testa caso degenerado
	beq $t2, $zero, vetor_add_vetor_int_exit # se n ==0, sai
	
	vetor_add_vetor_int_loop:
		beq $t1, $t2, vetor_add_vetor_int_exit # sai se i == preDigits.size()

		#carrega preDigits[i]
		move $a0, $s0
		move $a1, $t1
		jal vetor_get_i_value #v0 vai conter A[i]
		
		#adiciona preDigitis[i] em pidigits
		move $a0, $s1
		move $a1, $v0
		jal vetor_add_int
		
		addi $t1, $t1, 1 #i++
		
		j vetor_add_vetor_int_loop
		
	vetor_add_vetor_int_exit:
		#restaura estado
		lw $s0, 36($sp)
		lw $s1, 32($sp)
		lw $t3, 28($sp)
		lw $t0, 24($sp)
		lw $ra, 20($sp)
		lw $a1, 16($sp)
		lw $a2, 12($sp)
		lw $v0, 8($sp)
		lw $t2, 4($sp)
		lw $t1, 0($sp)
		addi $sp, $sp, 40
	
		jr $ra

exit_program:
	li $v0, 10
	syscall	
