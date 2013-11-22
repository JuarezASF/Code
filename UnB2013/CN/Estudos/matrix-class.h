#ifndef MATRIX_CLASS_H 
#define MATRIX_CLASS_H 

#include "usual-math.h"

int memoria_pedida   = 0;
int memoria_liberada = 0;

void *aloca(int tamanho);

void libera(void *adeus);

void EndProgram();

typedef struct Matrix{
	double **a;
	int rows;
	int columns;
	}Matrix;

Matrix *new_M(int M, int N);
	//cria mtriz Ma x Na de zeros


Matrix *new_M_I(int size);
	/*retorna matriz Identidade de tamanho size x size*/


Matrix *new_M_from_string(int Ma, int Na, const char *elements);
	/*cria matriz apartir de string recebdi
	 *sem enter, virgulas, barra ou o diabo...somente os números
	 * linhas e colunas devem ser definidos por Ma e Na
	 * */

void kill_M(Matrix **A);
	/*apaga a matriz e o seu ponteiro
	 * */

Matrix *sum(Matrix *A,Matrix *B);
	/*retorna ponteiro alocado para a matriz soma das entradas*/

Matrix *subtract(Matrix *A,Matrix *B);
	/*retorna ponteiro alocado para A - B*/
	
void print_M(Matrix *M);
	/*imprime com tabulação a matriz M
	 * */

void set_M_const(Matrix *M, double c);
	//modifica a matriz recebida para ser contante

void scalar_cross_M(Matrix *M, double c);
	/*modifica a matriz recebida M por c.M*/
	
	
Matrix *M_cross_N(Matrix *M, Matrix *N);
	/*retorna ponteiro alocad para o produto matricial*/

void A_equals_M_times_N(Matrix *A, Matrix *M, Matrix *N);
	/*coloca MN em A já alocados todos*/
	
Matrix *Transpose_M(Matrix *M);
	/*retorna ponteiro alocado para matriz transporta da recebida*/
	
Matrix *copy_M(Matrix *A);
	/*
	 * retorna ponteiro para matriz alocada igual a recebida
	 * */

int check_sqare(Matrix *A);
	/*
	 *RETORNA 1 CASO MATRIZ QUADRADA
	 * */

int check_diagonal(Matrix *A);
	/*
	 *RETORNA 1 CASO A DIAGONAL SEJA NÃO NULA
	 * */

	
void add_line(Matrix *A, int row_from, double c, int row_to);
	//add linha row_from*c a linha row_to
	//tomar cuidado com numeração das linhas e colunas
	//o primeiro elemento é a(0,0)

void change_lines(Matrix *A, int row_k, int row_l);
	//troca as linhas row_k por row_l


void change_lines_special(Matrix *A, int row_k, int row_l);
	/*troca os elementos das linhas row_k por row_l que estão
	abaixo da diagonal principal
	* para ser usado na fatoração LU com permutação*/

#include "matrix-class.c" 

#endif //MATRIX-CLASS_H
