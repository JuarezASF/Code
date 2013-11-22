#!/bin/sh
		echo "Compilando  *.cpp"
	    g++ -ggdb *.cpp `pkg-config --cflags opencv` -o ../bin/Projeto3 $i `pkg-config --libs opencv`;
	    echo "se tudo deu certo o executável está em ../bin/"
	    ../bin/Projeto3
