

void get_GaussSeidel_method_matrixs	(
Matrix *A, Matrix *u, Matrix *b, Matrix **T, Matrix **c
								)
//calcula as matrizes necessárias para o algoritmo de
//Jacobi
{
	Matrix *L, *D, *U, *L_plus_D_inv, *aux;	
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
	
	
	aux = sum(L, D);
	L_plus_D_inv = Inverse(aux);
	kill_M(&aux);
	
	*T = M_cross_N(L_plus_D_inv, U);
	scalar_cross_M(*T, -1);
	//T = -(L + D)^{-1}.U
	
	*c = M_cross_N(L_plus_D_inv, b);
	//c = D^{-1}b
	
	
	kill_M(&L);
	kill_M(&D);
	kill_M(&U);		
	kill_M(&L_plus_D_inv);

}


void GaussSeidel(Matrix *A, Matrix *u, Matrix *b)
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
 * Capítulo 7 pgs : 123 -126
 * 
 * Usa-se a fatoração A = L + D + U parar criar o processo iterativo:
 * 
 * u^{n+1} = Tu^{n} + c
 *  
 * com:
 * T = -(L + D)^{-1}.U
 * c = (L + D)^{-1}.b
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
		printf("GaussSeidel recebeu matrizes não existentes!\n");	
		printf("A rotina será terminada!\n");
		exit(0);
		}
		
	if((A->columns != A->rows) || (A->rows != u -> rows) || 
		(A->rows != b->rows) || (A->columns*A->rows == 0))
	{
		printf("GaussSeidel recebeu matrizes em forma não padrão!\n");	
		printf("A rotina será terminada!\n");
		exit(0);
	}
	
	Matrix  *T, *c;
		//>>matrizes do algoritmo
	Matrix *aux;
		//>>matriz para auxiliar
	int n, N_MAX;
	//n controla o número de interações e N_MAX o máximo permitido para n


	get_GaussSeidel_method_matrixs(A, u, b, &T, &c);
	//calcula: T = -(L + D)^{-1}.U e c = (L + D)^{-1}.b
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
/*
int main()
{
	
	Matrix *A, *u, *b;
	Matrix	*X;

	//A = new_M_from_string(5,5, "4 1 0 1 0 \
								1 4 1 0 1 \
								0 1 4 1 0 \
								1 0 1 4 1 \
								0 1 0 1 4");
	
	//b = new_M_from_string(5, 1, "1 2 -1 2 1");
	
	//u = new_M(5, 1);

	A = new_M_from_string(3,3, "3 1 -1 1 -4 2 -2 -1 5");
	
	b = new_M_from_string(3, 1, "3 -1 2");
	
	u = new_M(3, 1);
		
	
	GaussSeidel(A, u, b);
	
	print_M(u);
	
	kill_M(&A);
	kill_M(&u);
	kill_M(&b);

	EndProgram();
	
	return(0);
	
}
*/
