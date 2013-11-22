//Precisa de uma rotina para inverter matrizes


void get_Jacobi_method_matrixs	(
Matrix *A, Matrix *u, Matrix *b, Matrix **T, Matrix **c
								)
//calcula as matrizes necessárias para o algoritmo de
//Jacobi
{
	Matrix *L, *D, *U, *D_inv, *aux;	
	int 	i,j;
	
	L = new_M(A->rows, A->columns);
	
	D = new_M(A->rows, A->columns);
	
	U = new_M(A->rows, A->columns);
	 	
	for (i = 1 ; i < A->rows; i++)
		for (j = 0 ; j < i; j++)
			L->a[i][j] = A->a[i][j];
	
	for (i = 0 ; i < A->rows; i++)
			D->a[i][i] = A->a[i][i];
	
	for (i = 0 ; i < A->rows - 1; i++)
		for (j = i+1 ; j < A->columns; j++)
			U->a[i][j] = A->a[i][j];
	
	
	D_inv = Inverse(D);
	
	aux = sum(L,U);
	*T = M_cross_N(D_inv, aux);
	scalar_cross_M(*T, -1);
	kill_M(&aux);
	//T = -D^{-1}(L + U)
	
	*c = M_cross_N(D_inv, b);
	//c = D^{-1}b
	
	
	kill_M(&L);
	kill_M(&D);
	kill_M(&U);		
	kill_M(&D_inv);

}

int check_dominant_diagonal(Matrix *A)
//retorna 1 caso a matriz seja estritamente 
//diagonalmente dominante
{
int i,j;
double a_ii;//elemento da diagonal;
double diagonal_soma;

	for (i = 0 ; i < A->rows; i++)
		{
		a_ii = A->a[i][i];
		a_ii = absf(a_ii);
		diagonal_soma = 0;
		for (j = 0 ; j < A->columns; j++)
			{
			if( i != j)
				diagonal_soma += absf(A->a[i][j]);
			}
		if(diagonal_soma >= a_ii)
			return(0);
		}
		
	return(1);
} 

void JacobiMethod(Matrix *A, Matrix *u, Matrix *b)
/*recebe:
 * matrizes Au = b
 * todas devem ter sido definidas
 * inclusive u! que pode ser inicializada em 0
 * modifica u colocando aí a solução do sistema se possível
 * o código checa se a matriz é diagonalmente dominante ou não
 * se não for prossegue do mesmo modo mas não há garantia
 * teórica de que o algoritmo vá convergir!
 * 
 * o algoritmo é baseado no método iterativo descrito em:
 * Numerical Analysis Lecture Notes - Peter J. Oliver
 * Capítulo 7 pgs : 120 -122
 * 
 * Usa-se a fatoração A = L + D + U parar criar o processo iterativo:
 * 
 * u^{n+1} = Tu^{n} + c
 *  
 * com:
 * T = -D^{-1}(L + U)
 * c = D^{-1}b
 * 
 * 
 * 
 * desenvolvido por :
 * 					Juarez Aires Sampaio Filho
 * motivação:
 * 			curso de cálculo numérico - UnB-1º/2013
 * professor: 
 * 			Yuri Dumaresq Sobral
*/

{
	if(!A || !u || !b)
		{
		printf("JacobiMethod recebeu matrizes não existentes!\n");	
		printf("A rotina será terminada!\n");
		exit(0);
		}
		
	if((A->columns != A->rows) || (A->rows != u -> rows) || 
		(A->rows != b->rows) || (A->columns*A->rows == 0))
	{
		printf("JacobiMethod recebeu matrizes em forma não padrão!\n");	
		printf("A rotina será terminada!\n");
		exit(0);
	}
	
	Matrix  *T, *c;
		//>>matrizes do algoritmo
	Matrix *aux;
		//>>matriz para auxiliar
	int n, N_MAX;
	//n controla o número de interações e N_MAX o máximo permitido para n


	get_Jacobi_method_matrixs(A, u, b, &T, &c);
	//calcula: T = -D^{-1}(L + U) e c = D^{-1}b
	
	if(!check_dominant_diagonal(A))
		printf(" A matriz A recebida não é diagonalmente \
		 estritamente dominante! O algoritmo pode não convergir!\n");
		
	N_MAX = 1000;
	for( n = 0; n < N_MAX; n++)
		{
			aux = M_cross_N(T, u);
			kill_M(&u);
			u 	= sum(aux, c);
			kill_M(&aux);
		}
		
	kill_M(&T);				
	kill_M(&c);				
}
