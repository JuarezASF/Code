#ifndef GRAFO_H
#define GRAFO_H

#include <list>

#include "../GrafoAresta/GrafoAresta.h"
#include "../GrafoNode/GrafoNode.h"

#define listArestas list<GrafoAresta<GrafoNode<T> > >
#define listNodes 	list<GrafoNode<T> >

#define st_Aresta 	GrafoAresta<GrafoNode<T> >
#define st_Node		GrafoNode<T>
//st_:stands for structure

template <typename T>
class Grafo
{
private:
	listNodes 	nodeList;
	listArestas arestaList;

public:

	Grafo<T>()
		{
		}

    virtual ~Grafo<T>()
    {
    	list<int> A;
    	nodeList.erase(nodeList.begin(), nodeList.end());
    	arestaList.erase(arestaList.begin(), arestaList.end());
    }

    /*adiciona e remove nós*/
    void nodeAdd(T newNode);
    void removeNode(T target);

    /*adiciona e remove arestas
     * oriented indica:
     *  	se false: a ligação A,B implica B,A
     *  	se true	: a ligaçao A,B é independente de B,A
     **/
    void join(T A, T B, double peso, bool oriented = false);
    void removeJoint(T A, T B, bool oriented = false);

    /*procura nó no grafo. pesquisa feita por chave ou por nó*/
    st_Node	 findNode  (T target);
    st_Node	 findNode  (st_Node target);

    /*procura aresta no grafo. pesquisa feita por chave ou por aresta*/
        st_Node	 findNode  (T from, T to);
        st_Node	 findNode  (st_Aresta target);

    /*pergunta se nó existe no grafo. pesquisa feita por chave ou por nó*/
    bool exist(T target);
    bool exist(st_Node target);

    /*pergunta se nó existe no grafo. pesquisa feita por chave ou por aresta*/
    bool exist(T from, T to);
    bool exist(st_Aresta target);

    /*retorna lista com todas as arestas que saem de um no*/
    list<st_Aresta> listaArestasFromNode(st_Node target);

    /*retorna lista com todas as arestas que entram no no*/
    list<st_Aresta> listaArestasToNode(st_Node target);

    /*retorna lista com todas as arestas possuem um dado nó*/
    list<st_Aresta> listaArestasNode(st_Node target);

    /*retorna lista de nós para qual target pode andar*/
    list<st_Node> listaVizinhosNode(st_Node target);


};

#include "Grafo.cpp"
#endif // GRAFO_H
