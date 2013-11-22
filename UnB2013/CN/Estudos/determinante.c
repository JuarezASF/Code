#include "matrix-class.h"
#include "LU-fatoration.h"

int N_non_zeros(Matrix *A){
	int i, j;
	int counter = 0;
	
	for(i = 0; i < A->rows; i++)
		for(j = 0; j < A->columns; j++)
			if(A->a[i][j] != 0) counter++;
			
	return(counter);
	}

double determinante(Matrix *A){
	
		Matrix  *L, *U, *P, *I, *s;
		double  detA = 1;
		int 	i;
		
		I = new_M_I(A->rows);
		get_Permuted_LU_fatoration(A, &L, &U, &P);
		s = subtract(I, P);
		for(i = 0; i < A->rows; i++)
			detA *= U->a[i][i];
		detA *= pow(-1, max_d((N_non_zeros(s)/2 - 1), 0));
		
		kill_M(&I);
		kill_M(&P);
		kill_M(&U);
		kill_M(&L);
		kill_M(&s);
		
		return(detA);
	}
