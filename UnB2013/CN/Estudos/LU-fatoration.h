#ifndef LU_FATORATION_H
#define LU_FATORATION_H

#include "usual-math.h"

void get_simply_LU_fatoration(Matrix *A, Matrix **L, Matrix **U);
	/*
	 *acha a fatoração LU sem tentar permutações
	 * */


void BackSubstitution(Matrix *A, Matrix *x, Matrix *b);
	/*
	 *isola x começando de baixo para cima
	 * */

void ForwardSubstitution(Matrix *A, Matrix *x, Matrix *b);
	/*
	 *isola x começando de cima para baixo
	 * */


void simply_LU_fatoration(Matrix *A, Matrix *x, Matrix *b);
	/*Resolvemos
	 *		Ax = B
	 *
	 * fazendo A = LU
	 * 	Ax = LUx = b
	 * definimos Ux = c
	 * e portanto
	 * basta resolver
	 * 			-  Lc = b
	 * 			-  Ux = c
	 *
	 * aplica-se substituição direta no primeiro
	 * e inversa no segundo
	 * **PARA CASO ACHE 0 NA DIAGONAL PRINCIPAL**
	 * 	*/

void get_Permuted_LU_fatoration(Matrix *A, Matrix **L, Matrix **U, Matrix **P);
	/*
	 *acha a fatoração LU com permutações
	 * */


void Permuted_LU_fatoration(Matrix *A, Matrix *x, Matrix *b);
	/*Resolvemos
	 *		Ax = B
	 *
	 * fazendo PA = LU
	 * 	PAx = LUx = Pb = B
	 * definimos Ux = c
	 * e portanto
	 * basta resolver
	 * 			-  Lc = B
	 * 			-  Ux = c
	 *
	 * aplica-se substituição direta no primeiro
	 * e inversa no segundo
	 * **TENTA CORRIGIR CASO ACHE 0 NA DIAGONAL PRINCIPAL**
	 * 	*/

#include "LU-fatoration.c"
#endif
