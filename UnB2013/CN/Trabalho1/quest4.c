#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

float mod(float x){
	return((x > 0)? x : -1.0*x);
	}

int main(int argc, char* argv[]){

	int n, freq;
	float lambda, x, x_f;
	FILE *fp;

	fp = fopen("./data/4-1.dat", "w+");

	for(lambda = 0; lambda <= 4;  lambda += 0.01)
		{
		x = 0.5;
		for(n = 0; n < 300; n++)//descartados	
				x = lambda*x*(1 - x);
		x_f = x;
		freq = 0;
		for(n = 0; n < 800; n++)//procurando valor repetido
			{
			x = lambda*x*(1 - x);
			freq++;
			if(mod(x_f - x) < 0.01) break;
			}
		fprintf(fp, "%.3f \t %d\n", lambda, freq);
		}

		fclose(fp);

}
