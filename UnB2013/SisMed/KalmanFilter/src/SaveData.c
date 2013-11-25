/*
 * SaveData.c
 *
 *  Created on: 24/10/2013
 *      Author: juarez
 */

#include "../headers/SaveData.h"
#include "../headers/UserInterface.h"

void MatrixPrint2File(Matrix *A, const char *filename){

	if(A != NULL){

		FILE *fp = fopen(filename, "w+");
		int i, j;

		for(i = 0; i < A->rows; i++)
			{
			for(j = 0; j < A->columns - 1; j++)
				fprintf(fp, "%.6lf\t", A->a[i][j]);
			fprintf(fp, "%.6lf\n", A->a[i][j]);
			}
	}

	else
		reportBad("MatrixPrint2File recebeu matriz que não existe!\n\n");
}


