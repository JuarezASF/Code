#include "all.h"

int main()
{
	
	Matrix *X;
	Matrix  **A;
//	char 	file[] = "./../data/data_test.dat";
	char 	file[] = "./../data/tab1.dat";
	A  		= (Matrix **)aloca(1 * sizeof(Matrix *));
	X   	= PolynomialFitting(file, 17, 16);
	
	A[0] 	= X;

	MakeGnuplotMultPlotScript("plot2.GNU", \
	file, A, 1, "./../LaTeX/graph/quest2");
	
	printf("O erro da aproximação com n = 16 é : %.6lf\n",\
						FindFittingError(X, file, 17));

	print_coeff_table(X, "tab-quest2-X16.tab");
	
	kill_M(&X);

	libera(A);
	
	EndProgram();
	
return(0);
}
