#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./../headers/all.h"
#include "./../headers/KalmanFilter.h"
int main(){
	
	double dt = 0.1;
	double *time;
	double t_start, t_end;
	int time_steps, Nsamples;
	Matrix *xSaved, *zSaved;
	double z;

	t_start = 0;
	t_end = 10;
	time_steps =(int)((double)(t_end - t_start)/dt + 0.5);
	//arredonda para cima o resultado da divisão

	time = (double *)aloca(time_steps*sizeof(double));

	int i;
	for(i = 0; i < time_steps; i++){
		time[i] = i*dt;
	}

	Nsamples = time_steps;
	
	xSaved = new_M(Nsamples, 3);
	zSaved = new_M(Nsamples, 2);


	for(i = 0; i < Nsamples; i++)
	{
		z = getVel();
		Matrix *X = NULL;
		X = intKalman(z);
		xSaved->a[i][0] = time[i];
		xSaved->a[i][1] = X->a[0][0];
		xSaved->a[i][2] = X->a[1][0];

		zSaved->a[i][0] = time[i];
		zSaved->a[i][1] = z;
		kill_M(&X);
	}

	const char fileX[] = "../data/X.dat";
	const char fileZ[] = "../data/Z.dat";

	MatrixPrint2File(xSaved, fileX);
	MatrixPrint2File(zSaved, fileZ);

	kill_M(&xSaved);
	kill_M(&zSaved);
	libera(time);
	KalmanFilter_End();
	EndProgram();

	reportGood("O programa chegou ao fim!");


	return(0);
	
	}
