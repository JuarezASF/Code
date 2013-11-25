#! /bin/bash

 echo "Compilando  *.cpp"
    g++ -ggdb ./src/*.cpp `pkg-config --cflags opencv` -o ./bin/ProjetoFinal $i `pkg-config --libs opencv` -I ./include/;
 echo "se tudo deu certo, o executável está em ./bin/"