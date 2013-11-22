#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix-class.hpp"

int main(){

    Matrix A(2, 2, "1 1 1 1");
    Matrix B(2,2, "2 2 2 2");
    Matrix S;

    S = A + B;

    print_M(&S);

    return(0);
}
