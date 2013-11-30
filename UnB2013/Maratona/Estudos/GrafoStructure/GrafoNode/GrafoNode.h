#ifndef GRAFONODE_H
#define GRAFONODE_H

#include <list>

#include "../GrafoAresta/GrafoAresta.h"

using namespace std;

template <typename T>
class GrafoNode
{
private:
    T data;
public:
    GrafoNode(T newData){
    	data = newData;
    }

	T getData() const {
		return data;
	}

	void setData(T data) {
		this->data = data;
	}
};

#endif // GRAFONODE_H
