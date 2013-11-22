#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H

class Matrix
    {


    public:

        double **a;
        int rows;
        int columns;

    private:

        void Init_Matrix(int M, int N);

    public:
        Matrix(int M, int N);
        //matriz MlinhasxNcolunas de zeros

        Matrix();
        //matriz 0x0

        Matrix(int size);
        //matriz identidade sizexsize

        Matrix(int M, int N, const char *elements);
        //matriz MxN com elementos do string

        ~Matrix();

        Matrix& operator= (const Matrix &mSource);

        friend Matrix operator+(Matrix &A, Matrix &B);

        friend Matrix operator-(Matrix &A, Matrix &B);

        friend Matrix operator*(double c, Matrix &A);

    };//end class

#include "matrix-class.cpp"
#endif
