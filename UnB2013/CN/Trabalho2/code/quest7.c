#include "all.h"

void SetSplitAb(Matrix *A, Matrix *b, Matrix *Y, int coluna)
/*Monta as matriz do sista para ser usado em SolveD
 * coluna controla qual coluna dos dados será lida
 * 
 * */
{
		int i;
		
		//set primeira linha de A
		A->a[0][0] = 2;
		A->a[0][1] = 1;
		//set linha 2 até n-1 de A
		for(i = 1; i < A->rows-1; i++)
			{
			A->a[i][i-1]	= 1;
			A->a[i][i]		= 4;
			A->a[i][i+1]	= 1;
			}
		//set ultima linha de A
		A->a[i][i-1]	= 1;
		A->a[i][i]		= 2;


		//set primeira linha de b
		b->a[0][0] = 3*Y->a[1][coluna] -3*Y->a[0][coluna] ;		
		//set linha 2 até n-1 de b
		for(i = 1; i < b->rows-1; i++)
			b->a[i][0] = 3*Y->a[i+1][coluna] -3*Y->a[i-1][coluna];
		//set ultima linha de b
		b->a[i][0] = 3*Y->a[i][coluna] -3*Y->a[i-1][coluna];

}

Matrix *SolveD(Matrix *DATA,int coluna)
/*deve receber:
 * - matriz com os dados (pares ou trincas)
 * - número da coluna que será resolvida
 * */
{
	Matrix *A, *x, *b;
	Matrix *A_inv;
	int M_data = DATA->rows;

	A = new_M(M_data, M_data);
	b = new_M(M_data, 1);

	SetSplitAb(A, b, DATA, coluna);
	
	//RESOLVE DIRETAMENTE POR INVERSÃO
	A_inv = Inverse(A);
	x = M_cross_N(A_inv, b);
	kill_M(&A_inv);

	//RESOLVE INDIRETAMENTE POR JACOBI
/*	x = new_M(M_data, 1);
	JacobiMethod(A, x, b);
*/	
	//RESOLVE INDIRETAMENTE POR GAUSS-SEIDEL
/*	x = new_M(M_data, 1);
	GaussSeidel(A, x, b);
*/		

//****PARA OS TESTES REALIZADOS TODOS OS MÉTODOS RETORNARAM
//****MESMO RESULTADO!

	kill_M(&A);
	kill_M(&b);
	
	return(x);
}

Matrix *SolveCoeff(Matrix *D, Matrix *y, int coluna)
/* Dados os coeficientes D_i's:
 * -calcula os coeficientes a_i, b_i, c_i, d_i
 * *CONVENÇÃO
 * X[i][j]:
 * -i marca o intervalo para o qual vale os coeficientes
 * -j marca o coeficiente
 * adotamos:
 *  j   coeficiete 
 *  0   a_i
 *  1	b_i
 *  2	c_i
 *  3	d_i
 * 
 * segundo a forma:
 * Y_i(s) = a_i s^3 + b_i s^2  c_i s + d
 * i.e: o primeiro coeficiente é o de maior potencia!
 * */
{
	Matrix *X;
	
	X = new_M(D->rows - 1, 4);
	int i;
	
	for (i=0; i < X->rows; i++)
		{
		X->a[i][0] = 2*(y->a[i][coluna] - y->a[i+1][coluna])\
									+ (D->a[i][0] + \
											D->a[i+1][0]);
		X->a[i][1] = -3*(y->a[i][coluna] - y->a[i+1][coluna]) - \
									(2*D->a[i][0] + \
											D->a[i+1][0]);
		X->a[i][2] = D->a[i][0];
		X->a[i][3] = y->a[i][coluna] ;
		}
	return(X);
}

void PrintSplit(Matrix *DATA, Matrix *coeff0, Matrix *coeff1,\
									const char *file)
{
	FILE *fp;
	int i;
	double s, ds, x, y;
	
	fp = fopen(file, "w");
	
	ds = pow(10, -2);
	
	for (i=0; i < DATA->rows - 1; i++)
		{
		for (s = 0; s <= 1; s+= ds)
			{
			//dentro desse intervalo a função é cúbica
			/*vale lembrar a convenção
			 *  *  j   coeficiete 
				*  0    a_i
				*  1	b_i
				*  2	c_i
				*  3	d_i
			   */
			x = coeff0->a[i][0]*pow(s, 3) + \
				coeff0->a[i][1]*pow(s, 2) + \
				coeff0->a[i][2]*pow(s, 1) + \
				coeff0->a[i][3];
				
			y = coeff1->a[i][0]*pow(s, 3) + \
				coeff1->a[i][1]*pow(s, 2) + \
				coeff1->a[i][2]*pow(s, 1) + \
				coeff1->a[i][3];			
				
			fprintf(fp, "%.6lf \t %.6lf \n", x,y);
			}
		}
		
	fclose(fp);
}

void SplitCalculate2D(const char *file, int M_data, \
									const char *split_save)
/* recebe :
 * -nome de um arquivo com os dados 
 * -número de dados a serem lidos
 * -nome de um arquivo aonde sairá os dados do split
 * 
 * *Faz isso em 2D, i.e.:
 * 					OS DADOS DEVEM TER DUAS COLUNAS
 * o que o código lerá são as duas primeiras colunas
 * do arquivo. O resto será desconsiderado
 * */
{
	Matrix *D0, *D1, *DATA, *coeff0, *coeff1;
	
	DATA 	= get_data_from_file(file, M_data);
	
	D0 = SolveD(DATA, 0);
		
	coeff0 = SolveCoeff(D0, DATA, 0);
	
	D1 = SolveD(DATA, 1);
		
	coeff1 = SolveCoeff(D1, DATA, 1);
	
	PrintSplit(DATA, coeff0, coeff1, split_save);
	
	print_M(coeff0);

	print_M(D1);	
	print_M(coeff1);	
	
	kill_M(&D0);
	kill_M(&coeff0);
	kill_M(&D1);
	kill_M(&coeff1);
	kill_M(&DATA);
}

int main()
{
	char 	file[] = "./../data/tab1.dat";
	char 	split[] = "./quest7-split.dat";
	
	int M_data = 17;
			
	SplitCalculate2D(file, M_data, split);
	EndProgram();
	
	return(0);
}
