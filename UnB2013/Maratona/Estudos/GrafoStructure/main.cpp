#include <iostream>
#include <string>
#include <vector>

#include "Grafo/Grafo.h"
#include "./GrafoNode/GrafoNode.h"
#include "./GrafoAresta/GrafoAresta.h"
#include "MathVector/MathVector.h"

using namespace std;

typedef MathVector<double> dVector;

int main() {

	Grafo<double> myGrafo;

	double target = 2;
	myGrafo.nodeAdd(target);

	double toFind;

	while(toFind != -1)
	{
	cout << "entre com um número a procurar no grafo \n";
	cin >> toFind;
 		if(myGrafo.exist(toFind))
			cout << "valor inserido achado" << endl;
		else
			cout << "valor inserido não achado" << endl;
	}
	return 0;
}

