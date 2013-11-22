#include "all.h"

int main()
{
	
	Matrix  **A, **B;
	Matrix *X1, *X2, *X3, *X5, *X10;
	char 	file[] = "./../data/tab1.dat";
	A = (Matrix **)aloca(3 * sizeof(Matrix *));
	B = (Matrix **)aloca(2 * sizeof(Matrix *));
	
	X1  = PolynomialFitting(file, 17, 1);
	X2  = PolynomialFitting(file, 17, 2);
	X3  = PolynomialFitting(file, 17, 3);
	X5  = PolynomialFitting(file, 17, 5);
	X10 = PolynomialFitting(file, 17, 10);
	
	//exemplo pg 230 : resultado ok!
	A[0] = X1;
	A[1] = X2;
	A[2] = X3;
	B[0] = X5;
	B[1] = X10;	
	
	MakeGnuplotMultPlotScript("plot1-a.GNU", \
	"./../data/tab1.dat", A, 3, "./../LaTeX/graph/quest1-a");
	
	MakeGnuplotMultPlotScript("plot1-b.GNU", \
	"./../data/tab1.dat", B, 2, "./../LaTeX/graph/quest1-b");
	
		printf("O erro da aproximação com n = 1 é : %.6lf\n",\
						FindFittingError(X1, file, 17));
		printf("O erro da aproximação com n = 2 é : %.6lf\n",\
						FindFittingError(X2, file, 17));
						
		printf("O erro da aproximação com n = 3 é : %.6lf\n",\
						FindFittingError(X3, file, 17));
						
		printf("O erro da aproximação com n = 5 é : %.6lf\n",\
						FindFittingError(X5, file, 17));
						
		printf("O erro da aproximação com n = 10 é : %.6lf\n",\
						FindFittingError(X10, file, 17));
	
	print_coeff_table(X1, "tab-quest1-X1.tab");
	print_coeff_table(X2, "tab-quest1-X2.tab");
	print_coeff_table(X3, "tab-quest1-X3.tab");
	print_coeff_table(X5, "tab-quest1-X5.tab");
	print_coeff_table(X10, "tab-quest1-X10.tab");
		
	kill_M(&X1);
	kill_M(&X2);
	kill_M(&X3);
	kill_M(&X5);		
	kill_M(&X10);
	libera(A);
	libera(B);
	
	EndProgram();
	
	
	
return(0);
}
