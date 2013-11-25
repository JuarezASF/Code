#include <iostream>
#include <fstream>
#include <cmath>
#include <limits>

using namespace std;

  fstream myfile;

void getDataQuest7(double *P, int N){
  	int i;


  	for(i = 0; i < N; i++)
  		{
  			myfile >> P[i];
  		}
  }

void change(double *A, double *B)
	{
	double aux = *B;
	*B = *A;
	*A = aux;
	}

void organize(double *P, int N)
	{

		for(int i = 0; i < N; i++){
			for(int j = 0; j < i; j++){
				if(P[i] < P[j])
					change(&P[i], &P[j]);
			}
		}
	}

double **getGroups(double *P, int N, int nPerGroup){
	int nGroups = (int)((double)(N/nPerGroup) + 0.5);
	//arredonda para cima a divisão inteira
	double **groups;
	groups = new double*[nGroups];

	for(int i = 0; i < nGroups; i++)
		groups[i] = new double [nPerGroup];

	int n = 0;

	for(int i =0; i < nGroups; i++)
		{
		for(int j = 0; j < nPerGroup; j++)
			{
			if(n < N)
				groups[i][j] = P[n];
			else//estouramos P
				groups[i][j] = 0;
			n++;
			}
		}
	return groups;
}


void getP(double P[4]){
	int i;

	for(i = 0; i < 4; i++)
		{
			double aux;
			myfile >> aux;//descarta a primeira coluna
			myfile >> P[i];
		}
}


void getPC(double P[2][4]){
	int i;

	for(i = 0; i < 4; i++)
		{
			myfile >> P[0][i];
			myfile >> P[1][i];
		}
}

void print(double P[4]){
	int i;


	for(i = 0; i < 4; i++)
			cout << P[i] <<endl;

}

void print(double P[2][4]){
	int i;


	for(i = 0; i < 4; i++)
			cout << P[0][i] << "\t" << P[1][i] << endl;

	cout << "\n\n";

}


void print(double *P, int N){
	int i;


	for(i = 0; i < N; i++)
			cout << P[i]  << endl;

	cout << "\n\n";

}

void print(int *P, int N){
	int i;
	for(i = 0; i < N; i++)
			cout << P[i]  << endl;

	cout << "\n\n";

}

double media(double P[4]){
	double med = 0;

	for(int i = 0; i < 4; i++)
		med += P[i];

	med /= 4;

	return med;
}




double media(double *P, int N){
	double med = 0;

	for(int i = 0; i < N; i++)
		med += P[i];

	med /= N;

	return med;
}

double standardDeviation(double *P, int N){
	double med = media(P, N);
	double sD = 0;

	for(int i = 0; i < N; i++)
		sD += pow(P[i] - med, 2)/(N-1);

	sD = sqrt(sD);
	return sD;
}

double s2t(double P[4]){

	double med = media(P);
	double s2t = 0;

	for(int i = 0; i < 4; i++)
		s2t += pow(P[i] - med, 2);

	s2t /= 4*3;

	return s2t;
}

void quest1(double P[4], int n){

	double med = media(P);
	double s = s2t(P);

	cout << "Os dados do ponto "<< n << " são : \n";
	cout <<"media = " << med << endl;
	cout << "s2t = " << s << endl;
	cout << "\n\n\n";


}

double calculateM(double data[2][4]){
	double m;
	double sumQi, sumQo, sumQi2, sumQo2, sumQiQo;
	int N = 4;

	sumQi = sumQo = sumQi2 = sumQo2 = sumQiQo = 0;

	for(int i = 0; i < N; i++)
	{
		sumQi += data[0][i];
		sumQi2 += pow(data[0][i], 2);
		sumQo += data[1][i];
		sumQo2 += pow(data[1][i], 2);
		sumQiQo += data[1][i]*data[0][i];
	}


	m = (N*sumQiQo - sumQi*sumQo)/(N*sumQi2 - pow(sumQi, 2));
	return m;
}

double calculateB(double data[2][4]){
	double b;
	double sumQi, sumQo, sumQi2, sumQo2, sumQiQo;
	int N = 4;

	sumQi = sumQo = sumQi2 = sumQo2 = sumQiQo = 0;

	for(int i = 0; i < N; i++)
	{
		sumQi += data[0][i];
		sumQi2 += pow(data[0][i], 2);
		sumQo += data[1][i];
		sumQo2 += pow(data[1][i], 2);
		sumQiQo += data[1][i]*data[0][i];
	}


	b = (sumQo*sumQi2 - sumQiQo*sumQi)/(N*sumQi2 - pow(sumQi, 2));
	return b;
}

double calculateS_q_o(double data[2][4]){
	double S_q_o = 0;
	int N = 4;

	double m = calculateM(data);
	double b = calculateB(data);
	for(int i = 0; i < N; i++)
	{
		S_q_o += pow(m*data[0][i] + b - data[1][i], 2);
	}

	S_q_o /= N;

	S_q_o = sqrt(S_q_o);

	return S_q_o;
}

double calculateS_q_i(double data[2][4]){
	double S_q_o = calculateS_q_o(data);
	double m = calculateM(data);

	double S_q_i = sqrt(S_q_o/m);

	return S_q_i;
}


double calculateS_m(double data[2][4]){
	double S_m = 0;
	int N = 4;

	double S_q_o = calculateS_q_o(data);
	double sumQi, sumQo, sumQi2, sumQo2, sumQiQo;

	sumQi = sumQo = sumQi2 = sumQo2 = sumQiQo = 0;

	for(int i = 0; i < N; i++)
	{
		sumQi += data[0][i];
		sumQi2 += pow(data[0][i], 2);
		sumQo += data[1][i];
		sumQo2 += pow(data[1][i], 2);
		sumQiQo += data[1][i]*data[0][i];
	}


	S_m = N*pow(S_q_o, 2)/(N*sumQi2 - pow(sumQi, 2));

	S_m = sqrt(S_m);
	return S_m;
}

double calculateS_b(double data[2][4]){
	double S_b = 0;
	int N = 4;

	double S_q_o = calculateS_q_o(data);
	double sumQi, sumQo, sumQi2, sumQo2, sumQiQo;

	sumQi = sumQo = sumQi2 = sumQo2 = sumQiQo = 0;

	for(int i = 0; i < N; i++)
	{
		sumQi += data[0][i];
		sumQi2 += pow(data[0][i], 2);
		sumQo += data[1][i];
		sumQo2 += pow(data[1][i], 2);
		sumQiQo += data[1][i]*data[0][i];
	}


	S_b = (pow(S_q_o, 2)*sumQi2)/(N*sumQi2 - pow(sumQi, 2));

	S_b = sqrt(S_b);
	return S_b;
}


double **normalize(double **interval_src, double *data,  int nGroups, int nData)
{
	double mu = media(data, nData);
	double sD = standardDeviation(data, nData);

	double** interval = new double*[nGroups];
	for(int i = 0; i < nGroups; i++)
		interval[i] = new double[2];

	double begin, end;


	for(int i = 0; i < nGroups; i++)
	{
		begin = (interval_src[i][0] - mu)/sD;
		end = (interval_src[i][1] - mu)/sD;
		interval[i][0] = begin;
		interval[i][1] = end;
	}

	return interval;
}

void printInterval(double **interval, int n){
	for(int i = 0; i < n; i++)
		{
		cout << "from "<< interval[i][0] << " to " << interval[i][1] <<endl;
		}
}

double phi(double x)
{
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return 0.5*(1.0 + sign*y);
}

double *probabilityCalculate(double ** interval, int nGroups)
	{
	double *prob;
	prob = new double[nGroups];

		double p = phi(interval[0][1]);
		prob[0] = p;

		for(int i = 1;i < nGroups - 1; i++)
		{
			p = phi(interval[i][1]) - phi(interval[i][0]);
			prob[i] = p;
		}

		 p = 1.0 - phi(interval[nGroups - 1][0]);
		prob[nGroups - 1] = p;

	return prob;
	}

double *calculateNe(double *prob, int nData, int nGroups){
	double *Ne = new double[nData];

	for(int i = 0; i < nGroups; i++)
		Ne[i] = nData * prob[i];
	return Ne;
}

double chi2(double *Ne, int* no, int nGroups){
	double chi = 0;

	for(int i = 0; i < nGroups; i++)
			chi += (pow(no[i] - Ne[i], 2))/Ne[i];

	return chi;
}

int* countNo(double **interval, double *data, int nData, int nGroups){

	int* No = new int[nGroups];
	for(int i = 0; i < nGroups; i++)
			No[i] = 0;

	for(int i = 0; i < nData; i++)
		{
		for(int n = 0; n < nGroups; n++)
			if(data[i] > interval[n][0] && data[i] <= interval[n][1])
				No[n]++;
		}

	return No;
}

int main () {

  double P1[4];
  double P2[4];
  double P3[4];
  double P4[4];
  double PC[2][4]; 
  // dados calibração na forma (T, V(T))

//-----------------------INICIALIZA
  myfile.open ("./../data/ponto1.dat");
  getP(P1);
  myfile.close();
  

myfile.open ("./../data/ponto2.dat");
  getP(P2);
  myfile.close();


myfile.open ("./../data/ponto3.dat");
  getP(P3);
  myfile.close();


  myfile.open ("./../data/ponto4.dat");
  getP(P4);
  myfile.close();

  myfile.open ("./../data/calibration.dat");
  getPC(PC);
  myfile.close();

//-----------------------QUESTÃO 1
  cout << "Questão 1: " << endl;

  quest1(P1, 1);
  quest1(P2, 2);
  quest1(P3, 3);
  quest1(P4, 4);

  //-------------------------Questão 3
  //calcular : S_{m}, S_{c}, S_{q_o}
 
  cout << "Os dados tomados são" <<endl;
  print(PC);

  cout << "m = " << calculateM(PC) <<endl;
  cout << "b = " << calculateB(PC) <<endl;
  cout << "S_q_o = " << calculateS_q_o(PC) <<endl;
  cout << "S_q_i = " << calculateS_q_i(PC) <<endl;
  cout << "S_m = " << calculateS_m(PC) <<endl;
  cout << "S_b = " << calculateS_b(PC) <<endl ;

  //-------------------------Questão 4
  //comparar os resultados de 1 e 3

	double s1 = sqrt(s2t(P1));
	double s2 = sqrt(s2t(P2));
	double s3 = sqrt(s2t(P3));
	double s4 = sqrt(s2t(P4));

	cout << "a soma das incertezas é " << s1+s2+s3+s4 << endl;
	cout << "S_t1 = " << s1 <<endl;
	cout << "S_t2 = " << s2 <<endl;
	cout << "S_t3 = " << s3 <<endl;
	cout << "S_t4 = " << s4 <<endl;

  //-------------------------Questão 7
	  //Chi-quadrado teste
	myfile.open ("./../data/data-quest7.dat");
	  	 double *data;
	  	data = new double[30];
		getDataQuest7(data, 30);
		myfile.close();
		cout << "\n\n aqui estão os dados lidos \n";
		print(data, 30);

		cout << "\n\n aqui estão os dados organizados \n";
		organize(data, 30);
		print(data, 30);


		double media7 = media(data, 30);
		cout << "A média é " << media7 << endl;
		double sD7 = standardDeviation(data, 30);
		cout << "O desvio padrão é " << sD7 << endl;

		double **interval = new double*[4];
		for(int i = 0; i < 4; i++)
			interval[i] = new double[2];

		interval[0][0]=std::numeric_limits<double>::min();;
		interval[0][1]=9.2;

		interval[1][0]=9.2;
		interval[1][1]=9.9;

		interval[2][0]=9.9;
		interval[2][1]=10.1;

		interval[3][0]=10.1;
		interval[3][1]=std::numeric_limits<double>::max();


		cout << "A seguir apresentamos os intervalos intervalos "<< endl;
		printInterval(interval, 4);

		double **normalInterval = normalize(interval, data, 4, 30);

		cout << "A seguir apresentamos os intervalos intervalos normalizados "<< endl;
		printInterval(normalInterval, 4);

		int *No = countNo(interval, data, 30, 4);

		cout << "A seguir apresentamos o número de dados por intervalo "<< endl;
		print(No, 4);


		double *prob = probabilityCalculate(normalInterval, 4);
		cout << "aqui está a probabilidade de cada grupo" << endl;
		print(prob, 4);


		double *Ne = calculateNe(prob, 30, 4);
		cout << "aqui está o número de ventos Ne em cada intervalo em uma gaussina perfeita" << endl;
		print(Ne, 4);

		double chi = chi2(Ne, No, 4);
		cout << "O valor para chi^2 é " <<chi<<  endl;

 cout << "\n\n UnB - Sis Med - 2º/2013 ---------Professor Carlos Llanos" << endl;
 cout << "Juarez Aires Sampaio Filho--------11/0032829" << endl;
  return 0;
}
