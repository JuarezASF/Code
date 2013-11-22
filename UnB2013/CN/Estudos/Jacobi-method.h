#ifndef JACOBI_METHOD_H 
#define JACOBI_METHOD_H

void JacobiMethod(Matrix *A, Matrix *u, Matrix *b);
/*recebe:
 * matrizes Au = b
 * todas devem ter sido definidas
 * inclusive u! que pode ser inicializada em 0
 * modifica u colocando aí a solução do sistema se possível
 * o código checa se a matriz é diagonalmente dominante ou não
 * se não for prossegue do mesmo modo mas não há garantia
 * teórica de que o algoritmo vá convergir!
 * 
 * o algoritmo é baseado no método iterativo descrito em:
 * Numerical Analysis Lecture Notes - Peter J. Oliver
 * Capítulo 7 pgs : 120 -122
 * 
 * Usa-se a fatoração A = L + D + U parar criar o processo iterativo:
 * 
 * u^{n+1} = Tu^{n} + c
 *  
 * com:
 * T = -D^{-1}(L + U)
 * c = D^{-1}b
*/
#include "Jacobi-method.c" 

#endif //JACOBI_METHOD_H
