/*
 * SaveData.h
 *
 *  Created on: 24/10/2013
 *      Author: juarez
 */

#ifndef SAVEDATA_H_
#define SAVEDATA_H_

#include <stdio.h>
#include <stdlib.h>

#include "matrix-class.h"

void MatrixPrint2File(Matrix *A, const char *filename);
/**imprime a matriz A recebida para o arquivo em filename
 * -trabalhos com o arquivo como se ele fosse um .txt(não
 * sei usar .bin)
 *
 * -o arquivo será aberto com 'w+', portanto apaga o que quer
 * que estivesse no arquivo anteriormente. tomar cuidado!
 *
 * - os dados serão salvos com 6 casas decimais de precisão!
 *
 * -teste se a matriz existe, mas não estou certo se esse teste
 * é bem feito. watch out!!!
 * */

#endif /* SAVEDATA_H_ */
