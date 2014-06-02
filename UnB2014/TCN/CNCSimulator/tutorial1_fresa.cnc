(adiciona peça)
$AddRegPart 1, 30, 30
(define zero máquina)
G92 X30 Y30 Z20
(seleciona ferramenta)
T1 M6 
(G0 velocidade de avanço)
G0 X15 Y15 Z2 
(liga ferramenta e define parâmetros)
F250 S2000 M3 
(desce para o primeiro furo)
G1 Z-5 
Y70
(faz o arco)
G2 X30 Y85 I15 J0
(termina o bloco)
G1 X85  
Y15 
X15
(recua para posição de segurança)
G0 Z2

T2 M6 (seleciona nova ferramenta)

G0 X30 Y30 Z2 (move para posição de segurança acima do primeiro furo)

(M3 liga a ferramenta, M8aciona agua e define ciclo de furação)
G81 Z-15 R1 M3 M8
(Z-15 é a profundidade do furo)
(R1 é o plano de segurança)
(F81 é o ciclo de furação)
Y70
X70
Y30
G80(termina ciclo de furação)
Z50 (volta para posição de segurança)
M30 (termina programa) 
