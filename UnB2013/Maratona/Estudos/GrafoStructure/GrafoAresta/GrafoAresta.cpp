#include "GrafoAresta.h"

template <class nodeType>
GrafoAresta<nodeType>::GrafoAresta(nodeType &from, nodeType &to,
		double peso)
		: from(from), to(to), peso(peso){}
