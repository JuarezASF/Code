#include <iostream>
#include <string>
#include <vector>

#include "./GrafoNode/GrafoNode.h"
#include "./GrafoAresta/GrafoAresta.h"
#include "MathVector/MathVector.h"

using namespace std;

int main() {

	double dataV[] = {0 ,0, 0};
	MathVector<double> V(3, dataV);
	GrafoNode<MathVector<double> > P(V);

	cout << "O ponto guardado é " << P.getData() << endl;


	return 0;
}

