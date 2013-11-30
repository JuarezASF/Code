#ifndef GRAFO_H
#define GRAFO_H

#include <list>

#include "../GrafoAresta/GrafoAresta.h"
#include "../GrafoNode/GrafoNode.h"

template <typename T>
class Grafo
{
private:
	list<GrafoNode<T> > nodeList;

public:
    Grafo();
};

#endif // GRAFO_H
