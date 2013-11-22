#ifndef ALGEBRIC_SYSTEM_H 
#define ALGEBRIC_SYSTEM_H
typedef struct VectorValuedFunction
{    
    double (*f1)(double , double);
    double (*f2)(double , double);

}VectorValuedFunction;

Matrix *evaluate(VectorValuedFunction *F, Matrix *u);
//retorna matrix alocada para F(U)

double ddx(double (*f)(double , double ), double x, double y);

double ddy(double (*f)(double , double ), double x, double y);

void VectorValuetedNewton(VectorValuedFunction *F, Matrix *u);
//deve receber o sistema R^2 -> R^2
//e o chute inicial em u
//Implementa o método de Newton versão vetorial
//Limitação para matrizes 2x2: ainda deve ser generalizado
//Algoritmo descrito em:
//                  Numeral Analysis Lecture Notes 
//                  Peter J. Oliver
//                  capítulo 9: 
//                  Numerical Solution of Algebric Systems
//                  pgs:145 - 147
//
//
//O processo iterativo utilizado é;
//   u^{(k+1)} = u^{(k)} - f'(u^{(k))^{-1}. f(u^{(k)}
//  * aqui tudo é vetorial
//  *f é uma função R^n -> R^n
//  *u é um vetor no R^n
//
//  o chato aqui é ficar avaliando essas funções vetorias e
//  invertendo. achar a derivada tbm é chato
//  achamos a derivada através de diferença finitas de
//  segunda ordem para a primeira derivada parcial em x e em
//  y
//
//  *Os testes com os exemplos do livro funcionaram, apesar
//  de não convergirem da mesma forma. O teste da pag.
//  149(de dois braços robóticos) convergiram para outra
//  solução mas igualmente correte. Os testes com o cálculos
//  das raízes cúbicas da unidade (pg 148) só convergiram
//  para a raíz real.
//
//  *Notou-se um bug no teste do braço robótico ao tentar
//  dar chute inicial com primeira entradad 0. Será que é
//  problema no algoritmo ou na função que cria as matrizes?
//  verificar!
//
//  A FAZER: ACRESCENTAR TESTES PARA VERIFICAR SE A ENTRADA
//  É VALIDA OU NAO!


#include "AlgebricSystem.c" 

#endif
