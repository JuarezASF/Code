UnB - 2/2013 - Princípios de Visão Computacional - Professor Flávio Vidal
Aluno : Juarez Aires Sampaio Filho	11/0032829
Trabalho 2: Detecção de linhas e círculos

Para compilar o código digite:
	./build_all.sh

o zip contém a rotina principal em 'main.cpp' e uma biblioteca com funções 
auxiliares 'ImgProcess.hpp'. Para rodar as diferentes funcionalidades do 
código é preciso editá-lo para selecionar os DEFINES adequados. Listo
as funcionalidades e a configuração. Os defines estão no começo do .cpp.


*ler vídeo apartir de arquivo especificado no código:
	#define VIDEO_MODE
*ler vídeo apartir de webcam
	#define VIDEO_MODE
	#define VIDEO_FROM_WEBCAM
*ler imagens especificadas no código
	#define IMAGE_MODE
*ler imagens apartir do vídeo e contar o número de linhas e círculos 
ao pressionar da tecla 'o'
	(nada definifo, modo padrão)


 Para rodar o código: ./main

IMPORTANTE
 o arquivo de vídeo deve estar no endereço especificado no código.
 No modo atual ele funciona especificamente para a minha máquina. O endereço
 deve ser modificado para o endereço adequado no computado em que se vai
 rodar

O programa mostra a imagem de entrada em uma janela e uma imagem com círculos e retas
pintados em outra.

aperte 'esc' para encerrar a execução e 'o' para contar o número de objetos detectados
(somente modo questão 3)