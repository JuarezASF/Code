#include "all.h"

void FirstDerivatives(const char *file, int M_data,\
									const char *save)
{
		Matrix *DATA;
		FILE 	*fp;
		int 	i,n;
		double 	DX, X0, F1, F2, T1, T2, h;
		//F1 e F2 : f a frente 
		//T1 e T2 : f atrás
		
		DATA 	= get_data_from_file(file, M_data);
		fp = fopen(save, "w");
		
		n = M_data - 1;
		h = (DATA->a[n][0] - DATA->a[0][0])/n;
		
		//derivada adiante para a fronteira esquerda
		F1 = DATA->a[1][1];
		F2 = DATA->a[2][1];
		X0 = DATA->a[0][1];
		
		DX = ((-1.5*X0) + (2.0*F1) + (-0.5*F2))/h; 
	
		fprintf(fp, "%.6f \t %.6f \n", DATA->a[0][0], DX);
		
		for(i = 1; i <= n-1; i++)
			{//derivadas centradas para o interior
			F1 = DATA->a[i+1][1];
			T1 = DATA->a[i-1][1];
			
			DX = ((0.5*F1) + (-0.5*T1))/h;
			fprintf(fp, "%.6f \t %.6f \n", DATA->a[i][0], DX);
			}

		//derivada para tras para a fronteira direitra
		T1 = DATA->a[i-1][1];
		T2 = DATA->a[i-2][1];
		X0 = DATA->a[i][1];
		
		DX = ((1.5*X0) + (-2.0*T1) + (0.5*T2))/h; 
	
		fprintf(fp, "%.6f \t %.6f \n", DATA->a[i][0], DX);
		

		kill_M(&DATA);
}
void SecindDerivatives(const char *file, int M_data,\
									const char *save)
{
		Matrix *DATA;
		FILE 	*fp;
		int 	i,n;
		double 	DDX, X0, F1, F2, F3, T1, T2, T3, h;
		//F1 e F2 : f a frente 
		//T1 e T2 : f atrás
		
		DATA 	= get_data_from_file(file, M_data);
		fp = fopen(save, "w");
		
		n = M_data - 1;
		h = (DATA->a[n][0] - DATA->a[0][0])/n;
		
		//derivada adiante para a fronteira esquerda
		F1 = DATA->a[1][1];
		F2 = DATA->a[2][1];
		F3 = DATA->a[3][1];
		X0 = DATA->a[0][1];
		
		DDX = ((2*X0) + (-5*F1) + (4*F2) + (-1*F3))/pow(h, 2); 
	
		fprintf(fp, "%.6f \t %.6f \n", DATA->a[0][0], DDX);
		
		for(i = 1; i <= n-1; i++)
			{//derivadas centradas para o interior
			F1 = DATA->a[i+1][1];
			T1 = DATA->a[i-1][1];
			X0 = DATA->a[i][1];	
					
			DDX = ((1*F1) + (-2*X0) + (1*T1))/pow(h,2);
			fprintf(fp, "%.6f \t %.6f \n", DATA->a[i][0], DDX);
			}

		//derivada para tras para a fronteira direitra
		T1 = DATA->a[i-1][1];
		T2 = DATA->a[i-2][1];
		T3 = DATA->a[i-3][1];
		X0 = DATA->a[i][1];
		
		DDX = ((2*X0) + (-5*T1) + (4*T2) + (-1*T3))/pow(h, 2);
	
		fprintf(fp, "%.6f \t %.6f \n", DATA->a[i][0], DDX);
		

		kill_M(&DATA);
}

int main()
{
	char 	file[] = "./../data/tab1.dat"; int M_data = 17;	
	
	FirstDerivatives(file, M_data, "quest3-1.dat");
	
	SecindDerivatives(file, M_data, "quest3-2.dat");
	
	
	EndProgram();
	
	return(0);
}
