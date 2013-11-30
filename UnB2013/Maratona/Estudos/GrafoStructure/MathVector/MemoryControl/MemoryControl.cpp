/*
 * MemoryControl.cpp
 *
 *  Created on: 06/11/2013
 *      Author: juarez
 */
//#include "../headers/MemoryControl.h"
	void MemoryControl::pedeMemoria(){
		memoriaPedida++;
	}

	void MemoryControl::liberaMemoria(){
		memoriaLiberada++;
	}

	int MemoryControl::getMemoriaPedida(){
		return memoriaPedida;
	}

	int MemoryControl::getMemoriaLiberada(){
		return memoriaLiberada;
	}

	void MemoryControl::printMemoryState(){
		std::cout << "memória pedida: " << MemoryControl::getMemoriaPedida() << std::endl;
		std::cout << "memória liberada: " << MemoryControl::getMemoriaLiberada() << std::endl;
	}

	int MemoryControl::memoriaPedida = 0;
	int MemoryControl::memoriaLiberada = 0;



