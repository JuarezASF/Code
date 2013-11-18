/*
 * myMath.h
 *
 *  Created on: 18/11/2013
 *      Author: juarez408
 */

#ifndef MYMATH_H_
#define MYMATH_H_

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>

using namespace std;
using namespace cv;

long sumMat(Mat target);

Mat ScanImageMultiply(Mat& I, const uchar* const table);
	//similar ao LUT mas multiplica em vez de atribuir o valor
    // accept only char type matrices

void makeShadowGreen(Mat &I, Mat &mask);
  /*pinta a máscara PB sobre a imagem colorida RGB de verde
	não realiza verificação, CUIDADO!*/

void makeCarBlue(Mat &I, Mat &mask);
  //recebe imagem colorda e máscara, pinta a máscara sobre a imagem de azul
	//não realiza verificação de formato: CUIDADO COM A ORDEM DOS ARGUMENTOS

Mat MySubstract(Mat &A, Mat &B);
/*fazemos a subtração A-B de modo peculiar
	-se a mudança não for significativa pintamos de branco
	-se a mudança for positica(ficar mais claro), pintamos de claro
	-se a mudança for negativa(escurecer) pintamos de escuro

	o caso de interesse é o segundo;
		-a sombra(e infelizmente os parabrisas) escurem os pixels
		ao caminharem*/


void Erosion( Mat src, Mat dst, int size);

void Dilation( Mat src, Mat dst, int size);
//função de dilatação retirada dos tutoriais do OpenCn
//quando maior o size, maior a dilatação

void myFilter(Mat &I);
			//elimina ruídos
			//explicação dos parâmetros: 200000 de testes feitos
			//esse foi o que ficou mais maneiro

void shadowSubtract(Mat &I, Mat &mask);


#endif /* MYMATH_H_ */
