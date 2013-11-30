#ifndef GRAFOARESTA_H
#define GRAFOARESTA_H

#include <list>
#include <limits>

#include "../GrafoNode/GrafoNode.h"

using namespace std;

template <class nodeType>
class GrafoAresta
{
private:
	nodeType &from, &to;
	double peso;

public:
    GrafoAresta(nodeType &from, nodeType &to,
    		double peso = numeric_limits<double>::max());

};

#endif // GRAFOARESTA_H
