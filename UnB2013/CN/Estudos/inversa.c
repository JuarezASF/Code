#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix-class.h"
#include "LU-fatoration.h"
#include "usual-math.h"
Matrix *mount_A_from_coluns(Matrix **c, int columns){
	Matrix *A;
	int i, j;

	A = new_M(c[0]->rows, columns);

	for(i = 0; i < A->rows; i++)
		for(j = 0; j < A->columns; j++)
			A->a[i][j] = c[j]->a[i][0];
			
	return(A);
	}

Matrix *Inverse(Matrix *A){
	
	Matrix **e, **x, *L, *U, *P, *I, *c, *B;
	int i, j;
	
	I = NULL;
	
	get_Permuted_LU_fatoration(A, &L, &U, &P);
	if(check_diagonal(U))
		{
			e = (Matrix **)aloca(A->columns*sizeof(Matrix *));
			x = (Matrix **)aloca(A->columns*sizeof(Matrix *));
		
			for(i = 0; i < A->columns; i++)
				{
				e[i] = new_M(A->rows, 1);
				x[i] = new_M(A->rows, 1);
				}
			
			for(i = 0; i < A->columns; i++)
				{
				set_M_const(e[i], 0);
				e[i]->a[i][0] = 1;
				}
				
				
			for(j = 0; j < A->columns; j++)
				{
				B = M_cross_N(P, e[j]);
				c = new_M(x[j]->rows, x[j]->columns);
				ForwardSubstitution(L, c, B);   
				BackSubstitution(U, x[j], c);
				kill_M(&c);
				kill_M(&B);
				}
			I = mount_A_from_coluns(x, A->columns);
		
			for(i = 0; i < A->columns; i++)
				{
				kill_M(&e[i]); 
				kill_M(&x[i]); 
				}
			libera(e);
			libera(x);	
		}
		else
			printf("Inverse não foi capaz de achar fatoração PLU de A!\n");
	
		if (L)		kill_M(&L);
		if (U)		kill_M(&U);
		if (P)      kill_M(&P);	
		
	
	return(I);
	}
