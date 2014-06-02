$AddRegPart 1, 30, 30
(zero peça)
G92 X30 Y30 Z20
(seleciona ferramenta)
T1 M6 
(G0 velocidade de avanço)
G0 X15 Y15 Z2 
(liga ferramenta e define parâmetros)
F250 S2000 M3 

G0 X50 Y70 
Z-5
G3  X10 Y70 I-20 J0
G1 X50 Y10
X90 Y70
G3  X50 Y70 I-20 J0

G1 Z20
M30

