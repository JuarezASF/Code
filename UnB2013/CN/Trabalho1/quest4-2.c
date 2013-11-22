#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float mod(float x){
	return((x > 0)? x : -1.0*x);}

int find_frequencia(FILE *fp, int alvo){

	int counter = 0;
	int aux;
	float lambda;
	char c;
	while((c = fgetc(fp)) != EOF){
		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%f %d", &lambda, &aux);
		if(aux == alvo) counter ++;
		}
		return(counter);
	}
	

int main(int argc, char* argv[]){
	FILE *fp, *f_out;
	int f_5, f_2;
	int i, f_i;
	fp = fopen("./data/4-1.dat", "r");
	f_5 = find_frequencia(fp, 5);
	fclose(fp);
	
	fp = fopen("./data/4-1.dat", "r");
	f_2 = find_frequencia(fp, 2);
	fclose(fp);

	printf("f_5 = %d \t f_2 = %d\n", f_5, f_2);

	//extra

	f_out = fopen("./data/4-2.dat", "w");
	for(i = 1; i <=100; i++)
		{
		fp = fopen("./data/4-1.dat", "r");
		f_i = find_frequencia(fp, i);
		fclose(fp);
		fprintf(f_out, "%d \t %d \n", i, f_i);
		}
		
		fclose(f_out);
	return(0);

	}
