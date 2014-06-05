$AddRegPart 1
G90 G18 G40
(G40: cancela raio de compensação)
(G90: coordenadas aabsolutas)
ET8 M6
G92 X0 Z128 

(plano de segurança)
N10 G0 X57 Z2

(liga ferramenta)
M3

(tira primeira camada)
G1 X49
Z-100
X51
(rasgos iniciais)

(1º rasgo)
G0 Z-94 
G1 x47
	z-92
   x45
   z-94
x51   
(2º rasgo)
G0 Z-84 
G1 x47
	z-80
   x45
   z-84
   x43
   z-80
x51


(3º rasgo)
G0 Z-72 
G1 x47
	z-68
   x45
   z-72
   x43
   z-68
   x41
   z-72
x51

(rasgos finais)
(1º rasgo final)
G0 Z-20 
G1 x47
	z-16
   x45
   z-20
   x43
   z-16
   x41
   z-20
x51

(2º rasgo final)
G0 Z-12 
G1 x47
	z-10
   x45
   z-12
x51   
(3º rasgo final)
G0 Z-5 
G1 x47
	z-2
   x45
   z-5
   x43
   z-2
x51




M30
