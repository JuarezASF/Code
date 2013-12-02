/*
 * main.cpp
 *
 *  Created on: 14/09/2013
 *      Author: juarez
 */
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>
#include "myMath.hpp"

using namespace std;
using namespace cv;


/// Global Variables
//para serem usadas pelso filtros
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
int optionFilter = 1;
//		1:median 2:gaussian 3:blur 4:bilateral




int main()
{
	VideoCapture video("./../videos/video2.avi"); //abre captura do arquivo
	//VideoCapture video(0); //abre captura da câmera
	Mat frame, colorFrame; 
	Mat current, previous, show;
	Mat m, mPrevious, Dk;
	Mat backGround;
    int cvWaitValue = 0;
	/*
	frame captura o vídeo
	current e previous 
	show: é mostrado na tela como resultado final
	back: define o que é o background
	*/
	if(!video.isOpened())
		{
			cout << "Video não pode ser aberto!" << endl;
			return -1;
		}

//------------------------------------------------------------------
//--------------------CRIA E DEFINE JANELAS-------------------------
//------------------------------------------------------------------

	namedWindow("video",CV_WINDOW_AUTOSIZE);
	namedWindow("subtractBackgound",CV_WINDOW_AUTOSIZE);
	namedWindow("backgroundMinusShadow",CV_WINDOW_AUTOSIZE);
	namedWindow("myShadow", WINDOW_AUTOSIZE );
	namedWindow("myCar", WINDOW_AUTOSIZE );

	cvMoveWindow("video", 0, 0);
	cvMoveWindow("subtractBackgound", 300, 0);
	cvMoveWindow("backgroundMinusShadow", 600, 0);
	cvMoveWindow("myShadow",0, 300);
	cvMoveWindow("myCar",300, 300);
		

//------------------------------------------------------------------
//--------------------DEFINE LOOK-UP-TABLE--------------------------
//------------------------------------------------------------------
	 int Th = 100;//valor de trashold inferior
	 int Th2 = 220;//limite superior do que é sombra
	 //os valores funcuionam para esse vídeo mas uma código mas genérico
	 //deve calcular esses valores para cada iteração baseado no histograma
	 Mat lookUpTable(1, 256, CV_8U);
	 uchar* table = lookUpTable.data;
    for (int i = 0; i < 256; ++i)
       {
    	if(i > Th && i < Th2)
    		table[i] = 0;
    	else
    		table[i] = 255;
       }

	 Mat lookUpTable2(1, 256, CV_8U);
	 uchar* table2 = lookUpTable2.data;
	 Th = 110;
	 Th2 = 254;
    for (int i = 0; i < 256; ++i)
       {
    	if(i > Th && i < Th2)
    		table2[i] = 0;
    	else
    		table2[i] = 255;
       }

	while(1)//LAÇO PRINCIPAL DO PROGRAMA
		{
//------------------------------------------------------------------
//------------------CAPTURA E CÓPIA DE IMAGENS----------------------
//------------------------------------------------------------------
			current.copyTo(previous);
			video >> colorFrame;
			if(colorFrame.empty())
				{
				break;
				cout << "frame não pôde ser capturado"<<endl;
				}

			cvtColor(colorFrame, frame, CV_RGB2GRAY);
			frame.copyTo(current);
			previous.copyTo(backGround);

//------------------------------------------------------------------
//--------------------BACKGROUND SUBTRACT---------------------------
//--subtração 'especial' de plano de fundo--------------------------
			if(!current.empty() && !backGround.empty()) 
				show = MySubstract(current, backGround);
			else
				show = current - backGround;
//------------------------------------------------------------------
//-------------------SOMBRA BASEADA EM SUBTRACT E FILTRAGEM---------
//------------------------------------------------------------------
			Mat myShadow;

			LUT(show, lookUpTable, myShadow);
			/*Fazemos uma segmentação no background subtraído
			basicamente mantemos as cores claras*/
         	myFilter(myShadow);
			/*
			Os filtros aplicados tem a função de eliminar o ruído.
			Vários testes levaram a escolha dessa ordem de aplicação
			e dos parâmetros utilizados. Não estou certo se isso vale
			somente para o vídeo em questão ou se genericamente. Muito
			provavlmente da certo para esse vído em particular.

			Ao final dessa etapa temos todas as sombras bem pintadas
			mas pegamos bastante os parabrizas dos carros
			*/
//------------------------------------------------------------------
//--------------------DEFINE MÁSCARA DE SOMBRA----------------------
//------------------------------------------------------------------
			Mat mask;
			myShadow.copyTo(mask);
//------------------------------------------------------------------
//----------E REMOVE SOMBRA DO BACKGROUND---------------------------
//------------------------------------------------------------------
			Mat minusShadow;
			show.copyTo(minusShadow);
			shadowSubtract(minusShadow, mask);
//------------------------------------------------------------------
//-------------------O QUE FOR CLARO E NÃO FOR SOMBREA É CARRO------
//---------------------------(ESPERO)-------------------------------
			Mat myCar;
			LUT(minusShadow, lookUpTable2, myCar);
			//Dilation(myCar, myCar, 2);
			//Erosion(myCar, myCar, 3);
			//Erosion(myCar, myCar, 3);


//------------------------------------------------------------------
//----------PINTA DE VERDE E AZUL O RESULTADO-----------------------
//------------------------------------------------------------------			
			makeCarBlue(colorFrame, myCar);
			makeShadowGreen(colorFrame, mask);
//------------------------------------------------------------------
//--------------------MOSTRA IMAGENS--------------------------------
//------------------------------------------------------------------
			
			if(!colorFrame.empty())
				imshow("video", colorFrame);
			if(!show.empty())
				imshow("subtractBackgound", show);
			if(!minusShadow.empty())
				imshow("backgroundMinusShadow", minusShadow);
			if(!myShadow.empty())
				imshow("myShadow", myShadow);
			if(!myCar.empty())
				imshow("myCar", myCar);
//------------------------------------------------------------------
//--------------------ESPERA OU TERMINA A EXECUÇÃO------------------
//------------------------------------------------------------------
            int wait_c = cvWaitKey(cvWaitValue);
			if((char)wait_c == 27 )
				{// char == 27 : ESC key
				cout << "\n\n execução será encerrada!"<<endl;
				break;
				}
			if((char)wait_c == 112)
				{
					imwrite( "../images/result.jpg", colorFrame);
					imwrite( "../images/myBackground.jpg", show);
					imwrite( "../images/minusShadow.jpg", minusShadow);
					imwrite( "../images/sombra.jpg", myShadow);
					imwrite( "../images/carro.jpg", myCar);
				}
		}//FIM DO LAÇO PRINCIPAL

	video.release();

	return 0;
}//FIM DA ROTINA



