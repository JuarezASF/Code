#ifndef GAUSS_SEIDEL_METHOD_H 
#define GAUSS_SEIDEL_METHOD_H

void GaussSeidel(Matrix *A, Matrix *u, Matrix *b);
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
 * Capítulo 7 pgs : 123 -126
 * 
 * Usa-se a fatoração A = L + D + U parar criar o processo iterativo:
 * 
 * u^{n+1} = Tu^{n} + c
 *  
 * com:
 * T = -(L + D)^{-1}.U
 * c = (L + D)^{-1}.b
 * 
 * 
 * 
 * desenvolvido por :
 * 					Juarez Aires Sampaio Filho
 * motivação:
 * 			curso de cálculo numérico - UnB-1º/2013
 * professor: 
 * 			Yuri Dumaresq Sobral
*/
#include "Gauss-Seidel-method.c" 

#endif //JACOBI_METHOD_H
