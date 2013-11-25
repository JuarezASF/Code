#ifndef DETERMINANTE_H 
#define DETERMINANTE_H

#include <math.h>

#include "matrix-class.h"
#include "inversa.h"
#include "LU-fatoration.h"

int N_non_zeros(Matrix *A);

double determinante(Matrix *A);

#endif
