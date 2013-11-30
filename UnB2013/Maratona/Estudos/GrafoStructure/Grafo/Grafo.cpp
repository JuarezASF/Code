#include <list>
#include <algorithm>

#include "Exceptions/NodeAlreadyExistsException.h"
#include "../GrafoNode/GrafoNode.h"

template <typename T>
void Grafo<T>::nodeAdd(T newNode)
	{
		if(exist(newNode))
			throw NodeAlreadyExistsException();
		else

			(this->nodeList).push_back(newNode);
	}

template <typename T>
bool Grafo<T>::exist(T target){
	GrafoNode<T> stN_target(target);
	return exist(stN_target);
}

template <typename T>
bool Grafo<T>::exist(st_Node target)
{
	if(this->nodeList.empty())
		return false;

	/*
	typename list<GrafoNode<T> >::iterator current;

	current = this->nodeList.begin();
	while(current != this->nodeList.end())
	{
		(*current).getData() == target.getData();
			return true;
	current ++;
	}
	*/
	listNodes *nodes = &(this->nodeList);
	typename list<GrafoNode<T> >::iterator itr;
	itr = find<
			typename list<GrafoNode<T> >::iterator,
			GrafoNode<T>
			>(nodes->begin(), nodes->end(), target);

	if(itr == nodes->end())
		return false;
	else
		return true;
	return false;
}


/* TO BO DONE
Grafo();

template <typename T>
bool Grafo<T>::exist(T &from, T &to);

template <typename T>
bool Grafo<T>::exist(st_Aresta &target);


void removeNode(T &target);
void join(T &A, T &B, double peso, bool oriented = false);
void removeJoint(T &A, T &B, bool oriented = false);


st_Node	 findNode  (T &target);
st_Node	 findNode  (st_Node &target);


    st_Node	 findNode  (T &from, T &to);
    st_Node	 findNode  (st_Aresta &target);


bool exist(T &from, T &to);
bool exist(st_Aresta &target);


list<st_Aresta> listaArestasFromNode(st_Node &target);


list<st_Aresta> listaArestasToNode(st_Node &target);


list<st_Aresta> listaArestasNode(st_Node &target);


list<st_Node> listaVizinhosNode(st_Node &target);
*/


