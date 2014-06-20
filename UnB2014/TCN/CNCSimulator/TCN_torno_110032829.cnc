$AddRegPart 1
G90 // coordenadas absolutas
G21 // unidades em milimitros
G40 //cancela compensação de raio  
ET8 M6 //seleciona e troca ferramenta
G92 X0 Z128

(move para plano de segurança)
G0 X28 Z2

F250 S1000 M4 (liga a ferramente M4)

G1 	X26.5
	Z-100(tira 1mm para homogeneizar)
	X28
	(rasgos iniciais - começo)
	//primeiro rasgo profundidade 6
	Z-95 //G0
	X24.5 (tira 2cm)
	X22.5
	X20.5
	X28 (segurança)


	//segundo rasgo profundidade 4
	Z-88 //G0
	X24.5
	X22.5
	X28 (segurança)

	//terceiro rasgo profundidade 2
	Z-81 //G0
	X24.5
	X28 (segurança)
	(rasgos iniciais - fim)
	
	(declividade trapezoidal - inicio)
	(rasgo trapezoidal primeiro passe)
	Z-56 //G0 extremidade direita 
	X26.5 //aproximação
	X24.5 Z-58
	Z-72
	X26.5 Z-74
	X28 (segurança)
	(rasgo trapezoidal - segundo passe)
	Z-56 //G0 extremidade direita 
	X26.5 //aproximação
	X22.5 Z-60
	Z-70
	X26.5 Z-74
	X28 (segurança)
	(rasgo trapezoidal - terceiro passe)
	Z-56 //G0 extremidade direita 
	X26.5 //aproximação
	X20.5 Z-62
	Z-68
	X26.5 Z-74
	X28 (segurança)
	(declividade trapezoidal - fim)
	
	(declividade circular - inicio)
	(rasgo circular primeiro passe)
	Z-36 //G0 extremidade direita 
	X26.5 //aproximação
	X24.5 Z-38
	Z-50
	X26.5 Z-52
	X28 (segurança)
	(rasgo circular segundo passe)
	Z-38 //G0 extremidade direita 
	X26.5 //aproximação
	X22.5 Z-40
	Z-48
	X26.5 Z-52
	X28 (segurança)
	(rasgo circular terceiro passe)
	Z-38 //G0 extremidade direita 
	X26.5 //aproximação
	X20.5 Z-42
	Z-46
	X26.5 Z-52
	X28 (segurança)
	(rasco circular - acabamento)
	Z-38 // G0 extremidade direita
	X26.5
G2 X20.5 Z-42 R6  
G1 Z-46
G2 X26.5 Z-52 R6
G1 X28 (segurança) 
	(declividade circular - fim)
	
	(declividade circular com rasgos - início)
	(primeiro passe)
	Z-16 //G0 extremidade direita 
	X26.5 //aproximação
	X24.5 Z-18
	Z-28
	X26.5 Z-30
	X28 (segurança)
	(segundo passe)
	Z-16 //G0 extremidade direita 
	X26.5 //aproximação
	X22.5 Z-20
	Z-26
	X26.5 Z-30
	X28 (segurança)

	(primeiro rasgo)
	Z-25
	X24.5
	X22.5
	X20.5
	X28(segurança)
	(segundo rasgo)
	Z-21
	X24.5
	X22.5
	X20.5
	X28(segurança)
	(declividade circular com rasgos - FIM)
	
	(detalhe da ponta direita - inicio)
	(primeiro passe)
	Z0
	X24.5
	X26.5 Z-2
	(segundo passe)
	Z0
	X22.5
	X26.5 Z-4
	(terceiro passe)
	Z0
	X20.5
	X26.5 Z-6
	(acabamento)
	Z0 
	X20.5
	G2 X26.4 Z-6 R6 
	X28(segurança)
	(detalhe da ponta direita - FIM)
	
	(rasgo na ponta direita - início)
	Z-11
	X26.5 (aproximação)
	X24.5 (usinagem)
	X22.5 (usinagem)
	X20.5 (usinagem)
	X28 (segurança)
	(rasgo na ponta direita - FIM)
	
G0	X40 Z40 
	
M30 (encerra programa)



