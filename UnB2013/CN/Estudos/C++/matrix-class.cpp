void print_M(Matrix *M)
    {
    /*imprime com tabulação a matriz M
     * */
    int i, j;

    printf("\n\n");
    for(i = 0; i < M->rows; i++)
        {
        for(j = 0; j < M->columns; j++)
            printf("%.2lf \t",M->a[i][j]);
        printf("\n");
        }
    printf("\n\n");
    }

void Matrix::Init_Matrix(int M, int N)
    {
    int i, j;

    rows   		= M;
    columns 	= N;

    if(M && N)
        {
        a = new (double * [M]);
        for(i = 0; i < M; i++)
            a[i] = new double[N];

        for(i = 0; i < rows; i++)
            for(j = 0; j < columns; j++)
                a[i][j] = 0;
         }
    else
           a = NULL;

    }

Matrix::Matrix(int M, int N)
    {
    //cria mtriz Ma x Na de zeros
    Init_Matrix(M, N);
    }

Matrix::Matrix(int size)
    {
    /*retorna matriz Identidade de tamanho size x size*/
    int i;

    Init_Matrix(size, size);

    for(i = 0; i < rows; i++)
        a[i][i] = 1;
    }

Matrix::Matrix(int M, int N, const char *elements)
    {
    /*cria matriz apartir de string recebdi
     *sem enter, virgulas, barra ou o diabo...somente os números
     * linhas e colunas devem ser definidos por Ma e Na
     * */
    int i,j;
    FILE *fp;

    fp =fopen("temp.temp", "w");
    fprintf(fp,"%s\n", elements);
    fp =freopen("temp.temp", "r", fp);

    Init_Matrix(M, N);
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            fscanf(fp, "%lf", &(a[i][j]));

    fclose(fp);
    system("rm temp.temp");
    }

Matrix::~Matrix()
    {
    int i;
    if(a)
        {
        for(i = 0; i < rows; i++)
            delete[] a[i];
        delete[] a;
        }
    }

Matrix::Matrix()
    {
    Init_Matrix(0,0);
    }

 Matrix operator+(Matrix &A, Matrix &B)
    {
     int i, j, M, N;
     Matrix S;

     if(A.rows == B.rows && A.columns == B.columns)
         {
                 M = A.rows;
                 N = A.columns;
                 S = Matrix(M, N);
                 for(i = 0; i < S.rows; i++)
                     for(j = 0; j < S.columns; j++)
                         S.a[i][j] = A.a[i][j] + B.a[i][j];

         }
     else
         printf("Matrizes não tem mesmas dimensões!\n");

     return(S);

    }
 Matrix operator-(Matrix &A, Matrix &B)
    {
     int i, j, M, N;
     Matrix S;

     if(A.rows == B.rows && A.columns == B.columns)
         {
                 M = A.rows;
                 N = A.columns;
                 S = Matrix(M, N);
                 for(i = 0; i < S.rows; i++)
                     for(j = 0; j < S.columns; j++)
                         S.a[i][j] = A.a[i][j] - B.a[i][j];

         }
     else
         printf("Matrizes não tem mesmas dimensões!\n");

     return(S);

    }
 Matrix operator*(double c, Matrix &A)
    {
     int i, j, M, N;
     Matrix S;


      S = Matrix(A.rows, A.columns);
      for(i = 0; i < S.rows; i++)
        for(j = 0; j < S.columns; j++)
            S.a[i][j] = A.a[i][j] * c;

     return(S);

    }

 Matrix& Matrix::operator= (const Matrix &mSource)
 {
     // check for self-assignment by comparing the address of the
     // implicit object and the parameter
     if (this == &mSource)
         return *this;

     int i, j;
     Init_Matrix(mSource.rows, mSource.columns);
     for(i = 0; i < rows; i++)
            for(j = 0; j < columns; j++)
                a[i][j] = mSource.a[i][j];

     // return the existing object
     return *this;
 }
