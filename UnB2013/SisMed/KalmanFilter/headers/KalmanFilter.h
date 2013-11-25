/*
 * auxMain.h
 *
 *  Created on: Oct 23, 2013
 *      Author: Juarez Aires Sampaio Filho
 *
 *      !desenvolvido para a disciplina Sistemas de Medição, UnB, 2º/2013
 *      professor : Carlos Llanos!
 *
 *      O código é uma tradução para C de um exemplo de implementação
 *      do filtro de kalman para matlab. Essa versão do código não pretente
 *      ser genérica, apenas um exemplo de aplicação do filtro.
 *      Para auxiliar na implementação utilizou-se apenas as bibliotecas
 *      padrão da linguagem e um conjunto de bibliotecas desenvolvidas
 *      na disciplina Cálculo Numérico.
 */

#ifndef AUXMAIN_H_
#define AUXMAIN_H_

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix-class.h"
#include "inversa.h"

double randomNormal();
/**
 * retorna número aleatório normalmente
 * distribuído. Não tenho certeza se funciona corretamente
 * tirei de um un post em um site:
 * http://stackoverflow.com/questions/2325472/
 * generate-random-numbers-following-a-normal-distribution-in-c-c*/
double getVel();
/**
 * retorna um valor de velocidade com uma parcela
 * aleatória.*/

Matrix *intKalman(double z);

void KalmanFilter_End();
//elimina as matrizes estáticas alocadas
#endif /* AUXMAIN_H_ */
