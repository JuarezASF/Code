#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "listas.h"

int main(int argc, char* argv[]){

	float *lambda;
	float *x;
	int i;
	int n;
	FILE *fp;

	n=50;
	lambda = (float *)malloc(n*sizeof(float));
	x = (float *)malloc(n*sizeof(float));
	
	fp = fopen("./data/2-1.dat", "w+");
	

	for(i = 0 ;i < n; i++){
		lambda[i] = -5.0 + 10.0*((float)i/n);
		x[i] = 1.0 - 1.0/lambda[i];
		}
		
	for( i = 0 ;i < n; i++){
		fprintf(fp, "%.5f \t %.5f \n", lambda[i], x[i]); 
		}

	fclose(fp);
	free(x);
	free(lambda);


	float *x_n, x_0;
	int m;
	char file[50];
	n = 6;
	char *oldLocale = setlocale(LC_NUMERIC, NULL);
	
	lambda = (float *)malloc(n*sizeof(float));
	x_n = (float *)malloc(n*sizeof(float));	

	lambda[0] = -4.0 ;
	lambda[1] = -1.2;
	lambda[2] = -0.4;
	lambda[3] = 0.4;
	lambda[4] = 1.2;
	lambda[5] = 5;

	for(x_0 = -3.0; x_0 <=3.0; x_0 += 0.5) 
		{
		setlocale(LC_NUMERIC, "");
		sprintf(file, "./data/2-2-x0=(%'.1f).dat", x_0);//cada x0 possui um arquivo
		setlocale(LC_NUMERIC, oldLocale);
		fp = fopen(file, "w+");
		for(i = 0; i < n ; i++) x_n[i] = x_0;//cada iteração começa com x_0

		fprintf(fp, "0\t");//escrevendo primeira linha
		for(i = 0; i < n ; i++) fprintf(fp, "%.3f \t", x_n[i]);
		fprintf(fp, "\n");
		
		for(m = 0; m < 20; m++)//m controla o número da iteração
			{
			fprintf(fp, "%d\t", m);
			for(i = 0; i < n ; i++)//n associado ao lambda em questão
				{
				x_n[i] = -1.0*lambda[i]*x_n[i]*x_n[i] + lambda[i]*x_n[i];
				fprintf(fp, "%.3f \t", x_n[i]);
				}
			fprintf(fp, "\n");
			}
		fclose(fp);
		}


	return(0);
	}
