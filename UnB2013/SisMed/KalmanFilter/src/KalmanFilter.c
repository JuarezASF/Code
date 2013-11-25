/*
 * auxMain.c
 *
 *  Created on: Oct 23, 2013
 *      Author: juarez
 */
#include "../headers/KalmanFilter.h"

static Matrix  *X,*P,*A,*H,*Q, *R, *Z;

double randomNormal() {
    double u = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double v = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double r = u * u + v * v;
    if (r == 0 || r > 1) return randomNormal();
    double c = sqrt(-2 * log(r) / r);
    return u * c;
}

double getVel(){

	  static double Posp = 0;
	  static double Velp = 80;
	  static  double dt = 0.1;
	  double v, z;

	  v  = 0 +  10*randomNormal();

	  Posp = Posp + Velp*dt;     // true position
	  Velp = 80 + v;             // true speed

	  z = Velp;

	  return z;
}

Matrix *setPp(Matrix *A, Matrix *P, Matrix *Q){
	Matrix *At = Transpose_M(A);
	Matrix *PAt = MatrixProduct(P, At);
	Matrix *APAt = MatrixProduct(A, PAt);
	Matrix *Pp = sum(APAt, Q);

	kill_M(&At);
	kill_M(&PAt);
	kill_M(&APAt);

	return Pp;
}

Matrix *setK(Matrix *H, Matrix *Pp, Matrix *R){
	Matrix *Ht = Transpose_M(H);
	Matrix *PpHt = MatrixProduct(Pp, Ht);

	Matrix *HPpHt = MatrixProduct(H, PpHt);
	Matrix *HPpH_sum_R = sum(HPpHt, R);
	Matrix *inv_HPpH_sum_R = Inverse(HPpH_sum_R);

	Matrix *K = MatrixProduct(PpHt, inv_HPpH_sum_R);

	kill_M(&Ht);
	kill_M(&PpHt);

	kill_M(&HPpHt);
	kill_M(&HPpH_sum_R);
	kill_M(&inv_HPpH_sum_R);

	return K;
}

Matrix *setNewX(Matrix *H, Matrix *xp, Matrix *Z, Matrix *K){
	Matrix *Hxp = MatrixProduct(H, xp);
	Matrix *Z_minus_Hxp = MatrixMinus(Z, Hxp);
	Matrix *K_Z_minus_Hxp = MatrixProduct(K, Z_minus_Hxp);
	Matrix *X = MatrixPlus(xp, K_Z_minus_Hxp);

	kill_M(&Hxp);
	kill_M(&Z_minus_Hxp);
	kill_M(&K_Z_minus_Hxp);

	return X;

}

Matrix *setNewP(Matrix *H, Matrix *Pp, Matrix *K){
	Matrix *HPp = MatrixProduct(H, Pp);
	Matrix *KHPp = MatrixProduct(K, HPp);
	Matrix *newP = MatrixMinus(Pp, KHPp);

	kill_M(&HPp);
	kill_M(&KHPp);

	return newP;
}

Matrix *intKalman(double z){

	static double dt;
	static int firstRun = 0;

	if(firstRun == 0)
	{
		dt = 0.1;

		double dataA[2][2] = {	{1, dt},
								{0, 1}};
		A = Matrix_from_array(2, 2, &dataA[0][0]);

		double dataH[1][2] = {{0, 1}};
		H = Matrix_from_array(1, 2, &dataH[0][0]);

		double dataQ[2][2] = {	{1, 0},
								{0, 3}};
		Q = Matrix_from_array(2, 2, &dataQ[0][0]);

		double dataR[1][1] = {{10}};
		R = Matrix_from_array(1,1, &dataR[0][0]);

		double dataX[2][1] = {{0}, {20}};
		X = Matrix_from_array(2, 1, &dataX[0][0]);

		P = Matrix_eye(2);
		timesScalar(P, 5);

		firstRun = 1;
	}

	double dataZ[1][1] = {{z}};
	Z = Matrix_from_array(1,1,&dataZ[0][0]);

	//xp = A*x
	Matrix *xp = MatrixProduct(A, X);

	//Pp = A*P*A' + Q
	Matrix *Pp = setPp(A, P, Q);

	//K = Pp*H'*inv(H*Pp*H' + R)
	Matrix *K = setK(H, Pp, R);

	//x = xp + K*(z - H*xp)
	Matrix *newX = setNewX(H, xp, Z, K);

	//P = Pp - K*H*Pp

	Matrix *newP = setNewP(H, Pp, K);

	MatrixCopyTo(newX, &X);
	MatrixCopyTo(newP, &P);

	Matrix *output = NULL;

	MatrixCopyTo(X, &output);

	kill_M(&Z);
	kill_M(&xp);
	kill_M(&Pp);
	kill_M(&K);
	kill_M(&newX);
	kill_M(&newP);


	return output;

}

void KalmanFilter_End(){
	kill_M(&A);
	kill_M(&H);
	kill_M(&P);
	kill_M(&Q);
	kill_M(&R);
	kill_M(&X);
}


