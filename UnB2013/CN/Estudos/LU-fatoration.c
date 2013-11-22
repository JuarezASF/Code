

void get_simply_LU_fatoration(Matrix *A, Matrix **L, Matrix **U){
	/*
	 *acha a fatoração LU sem tentar permutações
	 * */
	int i, j;
	double l;

	*U = copy_M(A);

	*L = new_M((*U)->rows, (*U)->columns);
		//L matriz triangular inferior especial
	for(i = 0; i < (*L)->rows; i++)
		(*L)->a[i][i] = 1;//diagonal 1
	for(i = 0; i < (*L)->rows; i++)
		for(j = i + 1; j < (*L)->columns; j++)
			(*L)->a[i][j] =0;//superior 0


		
	for(j = 0; j < (*U)->columns; j++)
		{
		if((*U)->a[j][j] == 0)
			printf("A matriz não é regular!\n");
		else
			{
			for(i = j+1; i < (*U)->rows; i++)
				{
				l = -1.0*(*U)->a[i][j]/(*U)->a[j][j];
				add_line((*U), j, l, i);
				(*L)->a[i][j] = -1.0 * l;
				}//end for
			}//end else
		}//end for
	}

void BackSubstitution(Matrix *A, Matrix *x, Matrix *b){
	/*
	 *isola x começando de baixo para cima
	 * */
	int i, j;
    Matrix *b_aux;

    b_aux = copy_M(b);
	for(i = A->rows - 1; i>=0; i--)
		{
		for(j = i + 1; j < A->columns; j++)
            b_aux->a[i][0] -= A->a[i][j]*x->a[j][0];
        x->a[i][0] = b_aux->a[i][0]/A->a[i][i];
		}

    kill_M(&b_aux);
    }

void ForwardSubstitution(Matrix *A, Matrix *x, Matrix *b){
	/*
	 *isola x começando de cima para baixo
	 * */
	int i, j;
    Matrix *b_aux;

    if(A && x && b)
        {
        b_aux = copy_M(b);

        for(i = 0; i < A->rows ; i++)
            {
            for(j = i - 1; j >= 0; j--)
                b_aux->a[i][0] -= A->a[i][j]*x->a[j][0];
            x->a[i][0] = b_aux->a[i][0]/A->a[i][i];
            }

        kill_M(&b_aux);
        }
     else
        printf("ForwardSubstitution recebeu algo que n existe!\n");
	}




void simply_LU_fatoration(Matrix *A, Matrix *x, Matrix *b){
	/*Resolvemos
	 *		Ax = B
	 *
	 * fazendo A = LU
	 * 	Ax = LUx = b
	 * definimos Ux = c
	 * e portanto
	 * basta resolver
	 * 			-  Lc = b
	 * 			-  Ux = c
	 *
	 * aplica-se substituição direta no primeiro
	 * e inversa no segundo
	 * **PARA CASO ACHE 0 NA DIAGONAL PRINCIPAL**
	 * 	*/
	Matrix *L, *U, *c;
	

	if(A && x && b)
	{
	if(A->columns != A->rows)
		{
		printf("solve_by_LU_fatoration recebeu A não quadrado!\n");
		}
	else
		{
		get_simply_LU_fatoration(A, &L, &U);
		c = new_M(x->rows, x->columns);
		if(check_diagonal(U))
			{
			printf("A matriz A é:\n");
			print_M(A);
			printf("A matriz b é:\n");
			print_M(b);
			printf("A fatoração L é:\n");
			print_M(L);
			printf("A fatoração U é:\n");
			print_M(U);
			
			ForwardSubstitution(L, c, b);
            BackSubstitution(U, x, c);
			printf("A solução x é:\n");
			print_M(x);
			}//end if check
		else
			{
			printf("Falha na fatoração LU! U apresenta 0's na diagonal!\n");
			}
		kill_M(&L);
		kill_M(&U);
		kill_M(&c);
		}//end else A quadrado

	}//end if existe
	else
		printf("solve_by_LU_fatoration recebeu alguma matriz que n existe!\n");

	}

void get_Permuted_LU_fatoration(Matrix *A, Matrix **L, Matrix **U, Matrix **P){
	/*
	 *acha a fatoração LU com permutações
	 * */
	int i, j;
	double l;

	*U = copy_M(A);
	*L = new_M_I(A->rows);
	*P = new_M_I(A->rows);
		
	for(j = 0; j < (*U)->columns; j++)
		{
		if((*U)->a[j][j] == 0)
			{
			// temos problema na diagonal!
			for(i = j+1; i < A->rows; i++)
				if((*U)->a[i][j] != 0)
					{
					change_lines((*U), i, j);
					change_lines((*P), i, j);
					change_lines_special((*L), i, j);
					break;
					}
			}//end if primeiro teste
		if((*U)->a[j][j] != 0)
			{
			for(i = j+1; i < (*U)->rows; i++)
				{
				l = -1.0*(*U)->a[i][j]/(*U)->a[j][j];
				add_line((*U), j, l, i);
				(*L)->a[i][j] = -1.0 * l;
				}//end for
			}//end if segundo teste
		else
			{
			printf("A matriz não pode ser transformada em PA = LU!\n");
			break;
			}//end else segundo teste
		}//end for
	}


void Permuted_LU_fatoration(Matrix *A, Matrix *x, Matrix *b){
	/*Resolvemos
	 *		Ax = B
	 *
	 * fazendo PA = LU
	 * 	PAx = LUx = Pb = B
	 * definimos Ux = c
	 * e portanto
	 * basta resolver
	 * 			-  Lc = B
	 * 			-  Ux = c
	 *
	 * aplica-se substituição direta no primeiro
	 * e inversa no segundo
	 * **TENTA CORRIGIR CASO ACHE 0 NA DIAGONAL PRINCIPAL**
	 * 	*/
	Matrix *L, *U,*P, *B, *c;
		//L:matriz trang inferior especial
		//U:matriz triang superior com diagonal não nula
		//P:matriz das permutações
		//B: permutação aplicada em b
		//c: para o sistema auxlia Lc = B
		

	if(A && x && b)
	{
	if(A->columns != A->rows)
		{
		printf("solve_by_LU_fatoration recebeu A não quadrado!\n");
		}
	else
		{
		get_Permuted_LU_fatoration(A, &L, &U, &P);
        B = M_cross_N(P, b);
		c = new_M(x->rows, x->columns);
		if(check_diagonal(U))
			{
			printf("A matriz A é:\n");
			print_M(A);
			printf("A matriz b é:\n");
			print_M(b);
            printf("A matriz P é:\n");
            print_M(P);
            printf("A matriz B é:\n");
            print_M(B);
            printf("A fatoração L é:\n");
			print_M(L);
			printf("A fatoração U é:\n");
			print_M(U);
			
            ForwardSubstitution(L, c, B);
            printf(" c é:\n");
            print_M(c);
            BackSubstitution(U, x, c);
			printf("A solução x é:\n");
			print_M(x);
			}//end if check
		else
			{
			printf("Falha na fatoração LU! U apresenta 0's na diagonal!\n");
			}
		kill_M(&L);
		kill_M(&U);
		kill_M(&c);
        kill_M(&P);
        kill_M(&B);
		}//end else A quadrado

	}//end if existe
	else
		printf("solve_by_LU_fatoration recebeu alguma matriz que n existe!\n");

	}


