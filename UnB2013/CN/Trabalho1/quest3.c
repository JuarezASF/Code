#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(int argc, char* argv[]){

	int n;
	float lambda, x;
	FILE *fp;

	fp = fopen("./data/3-1.dat", "w+");

	for(lambda = 3; lambda <= 4;  lambda += 0.001)
		{
		x = 0.5;
		for(n = 0; n < 100; n++)	
			x = lambda*x*(1 - x);
		for(n = 0; n < 50; n++)
			{
			x = lambda*x*(1 - x);
			fprintf(fp, "%.5f \t %.6f\n", lambda, x);
			}
		}

		fclose(fp);

	fp = fopen("./data/3-2.dat", "w+");

	for(lambda = 0; lambda <= 4;  lambda += 0.001)
		{
		x = 0.5;//chute inicial
		for(n = 0; n < 100; n++)//iterações descartadas	
			x = lambda*x*(1 - x);
		for(n = 0; n < 50; n++)//iterações impressas
			{
			x = lambda*x*(1 - x);
			fprintf(fp, "%.5f \t %.8f\n", lambda, x);
			}
		}

		fclose(fp);
			
return(0);
	}
