#include <math.h>

double min_lf(double a, double b){
	return((a<b)? a : b );
}

int min_d(int a, int b){
	return((a<b)? a : b );
}

int max_d(int a, int b){
	return((a>b)? a : b);
}

double max_lf(double a, double b){
	return((a>b)? a : b);
}

double absf(double a)
//retorna módulo de número real
{
	return(max_lf(a, -1*a));
}
	
