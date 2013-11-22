#ifndef SIMPLY_GAUSSIAN_H
#define SIMPLY_GAUSSIAN_H

#include "matrix-class.h"

Matrix *make_augmented(Matrix *A, Matrix *b);
	/*retorna ponteiro alocado para matriz aumentada de A|b*/


void simply_Gaussian_elimination(Matrix *A, Matrix *b);
	/*
	 * eliminação gaussiana simples: sem permutação
	 * */
#include "simply-gaussian-elimination.c"
#endif
