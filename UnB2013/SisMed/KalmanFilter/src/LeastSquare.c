#include "../headers/LeastSquare.h"
#include <stdio.h>

Matrix *LeastSquares(Matrix *A,  Matrix *b)
{
    Matrix *x = NULL;
    Matrix *AT, *AT_A, *AT_A_inv, *AT_A_inv_AT;

	if(A && b)
		{

			AT = Transpose_M(A);

			AT_A = M_cross_N(AT, A);

			AT_A_inv = Inverse(AT_A);

			AT_A_inv_AT =M_cross_N(AT_A_inv, AT);

			x = M_cross_N(AT_A_inv_AT, b);

			kill_M(&AT);
			kill_M(&AT_A);
			kill_M(&AT_A_inv);
			kill_M(&AT_A_inv_AT);

		}
		
	else
		printf("LeastSquares recebeu matrizes não existentes!\n");
		
		
    return(x);
}
/*
int main()
{
    Matrix *A, *x, *b;
        
    A = new_M_from_string(5, 3, " 1 2 0 \
                                 3 -1 1 \
                                 -1 2 1 \
                                 1 -1 -2\
                                 2  1 -1 ");

    b = new_M_from_string(5,1,"1 0 -1 2 2");

	x = LeastSquares(A, b);

	print_M(A);
	
	print_M(b);
	
	print_M(x);

	kill_M(&A);
	kill_M(&x);
	kill_M(&b);
    EndProgram();

    return(0);
}
*/
