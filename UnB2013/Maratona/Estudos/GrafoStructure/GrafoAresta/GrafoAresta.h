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
    GrafoAresta(nodeType &newFrom, nodeType &newTo,
    		double newPeso = numeric_limits<double>::max()) :
	from(newFrom), to(newTo), peso(newPeso){}

};

#endif // GRAFOARESTA_H
