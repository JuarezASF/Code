$AddRegPart 1, 30, 30
T1 M6
(define zero máquina)
G92 X30 Y230 Z20
(liga ferramenta e define parâmetros)
F250 S2000 M3 

	(cabeça - incío)
G0 X83 Y-109
G1  Z-1.5
	X67 Y-91
	X66 Y-85
	X68 Y-80
	X75 Y-85
	X83 Y-109
	Z2 (segurança)
	(cabeça - fim)
	
	(corpo - início)
	(corpo - 1)
	X74 Y-82
	Z-1.5
	X78 Y-78
	X83 Y-78
	Z2
	
	X97 Y-87
	Z-1.5
	X97 Y-87
	X108 Y-95
	X115 Y-108
	X120 Y-118
	X123 Y-123
	X128 Y-129
	X120 Y-124
	X112 Y-114
	X104 Y-111
	X96	 Y-120
	X98	 Y-111
	X98	 Y-99
	z2
	
	X101 Y-97
	Z-1.5
	X95	 Y-97
	X87	 Y-95
	X80	 Y-91
	X77	 Y-90
	Z2
	(corpo + calda - FIM)
	
	(1ª asa - início)
	X83 	Y-83
	Z-1.5
	X94		Y-71
	X102	Y-67
	X115	Y-65
	X121	Y-63
	X131	Y-58
	X127	Y-65
	X123	Y-69
	X113	Y-75
	X109	Y-77
	X99		Y-86
	Z2
	(1ª asa - FIM)
	
	(2ª asa - Início)
	X78 Y-77
	Z-1.5
	X76	Y-71
	X73	Y-64
	X73	Y-57
	X75	Y-50
	X79	Y-43
	X87	Y-36
	X93	Y-33
	X89	Y-43
	X87	Y-51
	X87	Y-59
	X91	Y-62
	X93	Y-67
	X93 Y-69
	Z2
	(2ª asa - fim)
	
	(Flecha - início)
	X144 Y-81
	Z-1.5
	X148	Y-84
	X159	Y-80
	X155	Y-77
	X156	Y-72
	X146	Y-76
	X144	Y-81
	X113	Y-91
	Z2
	
	X88 Y-100
	Z-1.5
	X84	Y-102
	Z2

	X74 Y-105
	Z-1.5
	X50	Y-113
	X47	Y-110
	X40	Y-116
	X50	Y-116
	X50	Y-113
	Z2
	(flecha - fim)
	
	(círculo - início)
	X58 Y-102
	Z-1.5
G2  X68 Y-54 R42  
G1	Z2

	X97 Y-43
	Z-1.5
G2  X123 Y-54 R42  
G1	Z2
	
	X137 Y-94
	Z-1.5
G2  X125 Y-115 R42  
G1	Z2

	X111 Y-125
	Z-1.5
G2  X66 Y-115 R42  
G1	Z2
	(círculo - fim)
	
	(moldura - iníco)
	X10 Y-5
	Z-1.5
	X195 Y-5 
	X195 Y-195
	X5	 Y-195
	X5	 Y-5
	Z2
	
	X10 Y-5
	Z-3.0
	X195 Y-5 
	X195 Y-195
	X5	 Y-195
	X5	 Y-5
	Z2
	(moldura - fim)
Z30
M30
