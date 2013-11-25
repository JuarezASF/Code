#ifndef INVERSA_H
#define INVERSA_H

#include <stdio.h>
#include <stdlib.h>

#include "matrix-class.h"
#include "LU-fatoration.h"


Matrix *mount_A_from_coluns(Matrix **c, int columns);
Matrix *Inverse(Matrix *A);


#endif
