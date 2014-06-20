$AddRegPart 1
#1
G90 G21 G40
(G40: cancela raio de compensação)
(G90: coordenadas aabsolutas)
ET8 M6 (seleciona ferramenta e troca)

G92 X0 Z128 //redefine o zero 

N10 G0 X57 Z2(plano de segurança)


M3 (liga ferramenta)

//tira primeira camada para homogeneizar
G1 	X24
	Z-100
	X26 (plano de segurança)
G0	Z0

M30




