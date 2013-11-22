#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum boolean{ FALSE , TRUE};//false = 0 e true =1. !lembrar de declarar como enum boolean

void *aloca(int tamanho){
	memoria_pedida ++;
	return((void *)malloc(tamanho));
	}

void libera(void *adeus){

	memoria_liberada++;
	free(adeus);
	}
	
void EndProgram(){
	printf("\t memória alocada: %d \n\t memória liberada : %d\n\n", memoria_pedida, memoria_liberada);
	}
	
Matrix *new_M(int M, int N){
	//cria mtriz Ma x Na de zeros
	Matrix *A = NULL;
	int i, j;
	
	if(N > 0 && M > 0)
		{
		A = (Matrix *)aloca(sizeof(Matrix));
		A->a = (double **)aloca(M*sizeof(double *));
		for(i = 0; i < M; i++)
			A->a[i] = (double *)aloca(N*sizeof(double));
			
		A->rows 		= M;
		A->columns 		= N;

		for(i = 0; i < A->rows; i++)
			for(j = 0; j < A->columns; j++)
					A->a[i][j] = 0;
		}
	else
		printf("new_M recebeu tamanhos não positivos!\n");
		
	return(A);
	}

Matrix *new_M_I(int size){
	/*retorna matriz Identidade de tamanho size x size*/
	Matrix *I = NULL;
	int i;

	I = new_M(size, size);
	if(I)
		{
		for(i = 0; i < I->rows; i++)
			I->a[i][i] = 1;
		}
	return(I);
	}

Matrix *new_M_from_string(int Ma, int Na, const char *elements){
	/*cria matriz apartir de string recebdi
	 *sem enter, virgulas, barra ou o diabo...somente os números
	 * linhas e colunas devem ser definidos por Ma e Na
	 * */
	Matrix *M;
	int i,j;
	FILE *fp;

	fp =fopen("temp.temp", "w");
	fprintf(fp,"%s\n", elements);
	fp =freopen("temp.temp", "r", fp);

	M = new_M(Ma, Na);
	for(i = 0; i < M->rows; i++)
		for(j = 0; j < M->columns; j++)
			fscanf(fp, "%lf", &(M->a[i][j]));

	fclose(fp);
	system("rm temp.temp");
	return(M);
	}


void kill_M(Matrix **A){
	/*apaga a matriz e o seu ponteiro
	 * */
	int i;

	if(*A)
		{
		for(i = 0; i < (*A)->rows; i++)
				libera((*A)->a[i]);

		libera((*A)->a);	
		libera(*A);
		(*A) = NULL;
		}
	else 
		printf("kill_M recebeu matriz não alocada!\n");
	}

Matrix *sum(Matrix *A,Matrix *B)
	{
	/*retorna ponteiro alocado para a matriz soma das entradas*/
	int i, j, M, N;
	Matrix *S;
		
	if(A->rows == B->rows && A->columns == B->columns && A && B)
		{
				M = A->rows;
				N = A->columns;
				S = new_M(M, N);
				for(i = 0; i < M; i++)
					{
					for(j = 0; j < N; j++)
						S->a[i][j] = A->a[i][j] + B->a[i][j]; 
					}
		}
	else
		printf("sum Matrizes não tem mesmas dimensões!\n Ou então\
		as matrizes não existem!\n");

	return(S);	
	}
	
Matrix *subtract(Matrix *A,Matrix *B)
{
	/*retorna ponteiro alocado para a matriz soma das entradas*/
	int i, j, M, N;
	Matrix *S;
		
	if(A->rows == B->rows && A->columns == B->columns)
		{
				M = A->rows;
				N = A->columns;
				S = new_M(M, N);
				for(i = 0; i < M; i++)
					{
					for(j = 0; j < N; j++)
						S->a[i][j] = A->a[i][j] - B->a[i][j]; 
					}
		}
	else
		printf("Matrizes não tem mesmas dimensões!\n");

	return(S);	
}
	
void print_M(Matrix *M){
	/*imprime com tabulação a matriz M
	 * */
	int i, j;

	printf("\n\n");
	for(i = 0; i < M->rows; i++)
		{
		for(j = 0; j < M->columns; j++)
			printf("%.3lf \t",M->a[i][j]);
		printf("\n");
		}
	printf("\n\n");
	}
	
void set_M_const(Matrix *M, double c){
	//modifica a matriz recebida para ser contante
	int i, j;
	if(M)
		{
		for(i = 0; i < M->rows; i++)
			{
			for(j = 0; j < M->columns; j++)
					M->a[i][j] = c;
			}
		}
	}

void scalar_cross_M(Matrix *M, double c){
	/*modifica a matriz recebida M por c.M*/
	int i, j;
	if(M)
		{
		for(i = 0; i < M->rows; i++)
			{
			for(j = 0; j < M->columns; j++)
					M->a[i][j] *= c;
			}
		}
	}


Matrix *M_cross_N(Matrix *M, Matrix *N){
	/*retorna ponteiro alocad para o produto matricial*/
	int i, j, k, n;
	Matrix *P;
	
	if(M && N)
		{
		if(M->columns == N->rows)
			{
			n = M->columns; // = N->rows
			P = new_M(M->rows, N->columns);
			for(i = 0; i < P->rows; i++)
				{
				for(j = 0; j < P->columns; j++)
						{
						P->a[i][j] = 0;
						for(k = 0; k < n; k++)
								P->a[i][j] += M->a[i][k] * N->a[k][j];
						}//end for colunas
				}//end for linhas
			}//end if igualdade
		
		else
			printf("Tentou-se multiplicar matrizes n compatíveis!\n");
		}//end if existe
	else
		printf("Um dos argumentos de M_cross_N não existe!\n");
	return(P);
	}
void A_equals_M_times_N(Matrix *A, Matrix *M, Matrix *N){
	/*coloca MN em A já alocados todos*/
	int i, j, k, n;
	
	if(M && N && A)
		{
		if(M->columns == N->rows && A->rows == M->rows && A->columns == N->columns )
			{
			n = M->columns; // = N->rows
			for(i = 0; i < A->rows; i++)
				{
				for(j = 0; j < A->columns; j++)
						{
						A->a[i][j] = 0;
						for(k = 0; k < n; k++)
								A->a[i][j] += M->a[i][k] * N->a[k][j];
						}//end for colunas
				}//end for linhas
			}//end if igualdade
		
		else
			printf("Tentou-se multiplicar matrizes n compatíveis em A_equals_MN!\n");
		}//end if existe
	else
		printf("Um dos argumentos de A_equals_M_cross_N não existe!\n");
	}
	
Matrix *Transpose_M(Matrix *M){
	/*retorna ponteiro alocado para matriz transporta da recebida*/
	int i, j;
	Matrix *M_t;
	
	M_t = NULL;
	
	if(M)
		{
		M_t = new_M(M->columns, M->rows);
			for(i = 0; i < M_t->rows; i++)
				{
				for(j = 0; j < M_t->columns; j++)
						{
								M_t->a[i][j] += M->a[j][i];
						}//end for colunas
				}//end for linhas
		}//end if existe

	else
		printf("Transpose_M recebeu matriz não existente!\n");

	return(M_t);
	}
	
Matrix *copy_M(Matrix *A){
	/*
	 * retorna ponteiro para matriz alocada igual a recebida
	 * */
	Matrix *S;
	int i, j;

	if(A)
		{
		S = new_M(A->rows, A->columns);
		for(i = 0; i < S->rows; i++)
			for(j = 0; j < S->columns; j++)
				S->a[i][j] = A->a[i][j]; 
		}
	else
		printf("copy_M recebeu uma matriz que não existe!\n");

	return(S);
	}
	

int check_sqare(Matrix *A){
	/*
	 *RETORNA 1 CASO MATRIZ QUADRADA
	 * */
	return((A->rows == A->columns)? 1:0);
	}

int check_diagonal(Matrix *A){
	/*
	 *RETORNA 1 CASO A DIAGONAL SEJA NÃO NULA
	 * */
	int flag = 1; //supomos que esta certo
	int i;

	if(!check_sqare(A))
		{
		printf("check_diagonal recebeu matriz não quadrada!\n");
		return(0);
		}
	else
		{
		for(i = 0; i < A->rows; i++)
				if(A->a[i][i] == 0)
					flag = 0;
		}
	return(flag);
	}
	
void add_line(Matrix *A, int row_from, double c, int row_to){
	//add linha row_from*c a linha row_to
	//tomar cuidado com numeração das linhas e colunas
	//o primeiro elemento é a(0,0)
	int j;

	for(j = 0; j < A->columns; j++)
		A->a[row_to][j] += c*A->a[row_from][j];

	}

void change_lines(Matrix *A, int row_k, int row_l){
	//troca as linhas row_k por row_l
	int j;
	double aux;

	for(j = 0; j < A->columns; j++)
		{
		aux = A->a[row_k][j];
		A->a[row_k][j] = A->a[row_l][j];
		A->a[row_l][j] = aux;
		}
	}

void change_lines_special(Matrix *A, int row_k, int row_l){
	/*troca os elementos das linhas row_k por row_l que estão
	abaixo da diagonal principal
	* para ser usado na fatoração LU com permutação*/
	int j;
	double aux;

	for(j = 0; j < min_d(row_k, row_l); j++)
		{
		aux = A->a[row_k][j];
		A->a[row_k][j] = A->a[row_l][j];
		A->a[row_l][j] = aux;
		}
	}
