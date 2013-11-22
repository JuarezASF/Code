#include "matrix-class.h"

Matrix *make_augmented(Matrix *A, Matrix *b){
	/*retorna ponteiro alocado para matriz aumentada de A|b*/
	Matrix *M;
	int i, j;

	if((A->rows == A->columns) && A->rows == b->rows)
		{
		M = new_M(A->rows, A->columns + 1);
		
		for(i = 0; i < M->rows; i++)
			{
			for(j = 0; j < M->columns - 1; j++)
				M->a[i][j] = A->a[i][j];
			M->a[i][j] = b->a[i][0];
			}
		}
	return(M);
	}

void simply_Gaussian_elimination(Matrix *A, Matrix *b){
	/*
	 * eliminação gaussiana simples: sem permutação
	 * */
	float l;
	int i, j;
	Matrix *A_a;//A aumentada

	A_a = make_augmented(A, b);
	
		for(j = 0; j < A_a->columns - 1; j++)
		{
		if(A_a->a[j][j] == 0)
			printf("A matriz não é regular!\n");
		else
			{
			for(i = j+1; i < A_a->rows; i++)
				{
				l = -1.0*A_a->a[i][j]/A_a->a[j][j];
				add_line(A_a, j, l, i);	
				}//end for
			}//end else
		}//end for



	for(i = 0; i < A_a->rows; i++)//make A and b from A_a
		{
		for(j = 0; j < A_a->columns - 1; j++)
			A->a[i][j] = A_a->a[i][j];
		b->a[i][0] = A_a->a[i][j];
		}
	print_M(A_a);
	kill_M(&A_a);
	}//end routine


