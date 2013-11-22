#include "all.h"


double TrapezoidalRule(const char *file, int M_data)
{
	Matrix *DATA;
	int 	i, n;
	double 	h, J;

	DATA 	= get_data_from_file(file, M_data);
	
	n = M_data - 1;
	h = (DATA->a[n][0] - DATA->a[0][0])/n;

	J = 0;
	J += 0.5* DATA->a[0][1];
	J += 0.5* DATA->a[n][1];
	for(i = 1; i <= n-1; i++)
		J += DATA->a[i][1];

	J *= h;
	
	return(J);
}

double SimpsonRule(const char *file, int M_data)
{
	Matrix *DATA;
	int 	i, n;
	double 	h, J;
	
	if(M_data%2 == 1)
		{
		DATA 	= get_data_from_file(file, M_data);
		
		n = M_data - 1;
		h = (DATA->a[n][0] - DATA->a[0][0])/n;

		J = 0;
		J += DATA->a[0][1];
		J += DATA->a[n][1];
		
		for(i = 1; i <= n/2; i++)//ímpares
			J += 4*DATA->a[2*i-1][1];

		for(i = 1; i <= n/2 - 1; i++)//pares
			J += 2*DATA->a[2*i][1];

		J *= h/3;
	
		return(J);
		}
	else
		{
		printf("Simpson precisa de um número ímpar de pontos \
		para que tenhamos um número par de intervalos!\n\
		O programa será terminado!\n\n");
		exit(1);
		}
}



int main()
{
	char 	file[] = "./../data/tab1.dat"; int M_data = 17;
//	char 	file[] = "./test_trapezio.dat"; int M_data = 2;//ok
//	char 	file[] = "./test_simpson.dat"; int M_data = 3; //ok
		
	printf("A regra do Trapézio nos dá %.6lf\n",\
		TrapezoidalRule(file , M_data));

	printf("A regra de Simpson nos dá %.6lf\n",\
		SimpsonRule(file , M_data));

	
	return(0);
	
}
