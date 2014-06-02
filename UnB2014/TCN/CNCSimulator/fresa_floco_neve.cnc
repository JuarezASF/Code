$AddRegPart 1, 30, 30
T3 M6
(define zero máquina)
G92 X30 Y30 Z20
(G0 velocidade de avanço)
G0 X15 Y15 Z2 
(liga ferramenta e define parâmetros)
F250 S2000 M3 

G0 X32.68 Y50 (meio da lateral esquerda)
G1 Z-5
Y60(quina superior esquerda)
X50 Y70(quina superior)
X67.32 Y60(quina superior direita)
Y40(quina inferior direita)
X50 Y30(quina inferior)
X32.68 Y40(quina inferior esquerda)
Y50
Z2

G0 X50 Y70(quina superior)
G1 Z-5
Y90
Z2

G0 X50 Y30(quina inferior)
G1 Z-5
Y10
Z2

G0 X67.32 Y40(quina inferior direita)
G1 Z-5
X84.64 Y30
Z2

G0 X58.65 Y55(quina superior direita)
G1 Z-5
X67.3 Y60
Z2

G0 X41.35 Y55(quina superior esquerda)
G1 Z-5
X32.7 Y60
Z2

G0 X41.35 Y45(quina inferior esquerda)
G1 Z-5
X32.7 Y40
Z2

Z60
M30
