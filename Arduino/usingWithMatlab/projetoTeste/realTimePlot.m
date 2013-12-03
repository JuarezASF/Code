
%segundo esse tutorial http://www.xploreautomation.com/arduinomatlab-real-time-plot/
%abra o arduino com A = arduino('portaUSB_Correta')

t=0;
x=0;
interv=1000; % número de leituras a serem feitas
passo=1; %intervalo de tempo enetre uma leitura e outra

while(t<interv)
	b=A.analogRead(0);
	x=[x,b];
	plot(x);
	axis([0,interv,0,1023]) %eixo_x [0-interv] eixo_y [0,1023]
	grid %habilita a malha
	t=t+passo; %aggiornamento della variabile t
	drawnow
end %fim do while
