#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "all.h"



int main(){
	
	
	Matrix *A, *b, *x, *E;
	Matrix *S, *L, *U, *I;
	
	A = new_M_from_string(2,2, "1 1 2 3");
	printf("detA = %.3lf \n", determinante(A));
	kill_M(&A);

	
    EndProgram();
	return(0);
	
	}
