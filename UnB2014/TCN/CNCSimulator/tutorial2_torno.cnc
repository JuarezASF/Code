$AddRegPart 2 
ET1 M6
(move para plano de segurança)
G0 X40 Z80
(liga a ferramente M4, agua M8)
F250 S1000 M4 M8
(realiza o primeiro corte)
(Z está ao longo do eixo da peça)
(X está na direção radial)
G1 Z50 

(recua um pouco na diagonal)
X44 Z52
G0 Z80 
X30 
G1 Z60 
X34 Z62
(plano de segurança)
G0 Z80 
(tr0ca de ferramenta)
ET2 M6
(aproximação)
G0 X28 Z80
(usina detalhes)
G1 Z59
X38
Z49
X45
X50 Z45
(troca de ferramenta)
ET17 M6
G0 X0 Z80
(ciclo para fazer buraco)
G81 Z60 R78
(plano de segurançã)
G0 X100 Z200 

(encerra programa)
M30



