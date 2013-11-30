#include <iostream>

#include "GrafoNode/GrafoNode.h"

using namespace std;

int main()
{
	GrafoNode<double> P(12);

    cout << "O dado em P é " << P.getData()<< endl;
    return 0;
}

