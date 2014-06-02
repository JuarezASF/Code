#include<math.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
	float x0, y0, l;
	printf("entre com (X0,Y0))\n");
		scanf("%f %f", &x0, &y0);
	
	printf("entre com L\n");
		scanf("%f", &l);
	
	float pontoX, pontoY;
	printf("Quina superior esquerda\n");
		pontoX = x0 - l*sqrt(3)/2;
		pontoY = y0 + l/2;
		printf("\t (%f,%f)\n", pontoX, pontoY);

	printf("Quina superior\n");
		pontoX = x0;
		pontoY = y0 + l;
		printf("\t (%f,%f)\n", pontoX, pontoY);
	
	printf("Quina superior direita\n");
		pontoX = x0 + l*sqrt(3)/2;
		pontoY = y0 + l/2;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		
	printf("Quina inferior direita\n");
		pontoX = x0 + l*sqrt(3)/2;
		pontoY = y0 - l/2;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		
	printf("Quina inferior\n");
		pontoX = x0;
		pontoY = y0 - l;
		printf("\t (%f,%f)\n", pontoX, pontoY);

	printf("Quina inferior esquerda\n");
		pontoX = x0 - l*sqrt(3)/2;
		pontoY = y0 - l/2;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		
		
	printf("Floco superior esquerda\n");
		pontoX = x0 - l*sqrt(3);
		pontoY = y0 + l;
		printf("\t (%f,%f)\n", pontoX, pontoY);

	printf("floco superior\n");
		pontoX = x0;
		pontoY = y0 + 2*l;
		printf("\t (%f,%f)\n", pontoX, pontoY);
	
	printf("floco superior direita\n");
		pontoX = x0 + l*sqrt(3);
		pontoY = y0 + l;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		
	printf("floco inferior direita\n");
		pontoX = x0 + l*sqrt(3);
		pontoY = y0 - l;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		
	printf("floco inferior\n");
		pontoX = x0;
		pontoY = y0 - 2*l;
		printf("\t (%f,%f)\n", pontoX, pontoY);

	printf("floco inferior esquerda\n");
		pontoX = x0 - l*sqrt(3);
		pontoY = y0 - l;
		printf("\t (%f,%f)\n", pontoX, pontoY);
		}