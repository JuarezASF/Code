/*
 * MemoryControl.h
 *
 *  Created on: 06/11/2013
 *      Author: juarez
 */

#ifndef MEMORYCONTROL_H_
#define MEMORYCONTROL_H_

#include <iostream>

class MemoryControl{
private:
	static int memoriaPedida;
	static int memoriaLiberada;

public:
	static void pedeMemoria();

	static void liberaMemoria();

	static int getMemoriaPedida();

	static int getMemoriaLiberada();

	static void printMemoryState();
};

#include "MemoryControl.cpp"


#endif /* MEMORYCONTROL_H_ */
