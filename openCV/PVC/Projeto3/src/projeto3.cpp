#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

#include "../headers/OpticalFlow.h"
#include "../headers/kMeans.h"
#include "../headers/myMath.h"
#include "../headers/DenseFlux.h"

using namespace cv;
using namespace std;


int main( int argc, char** argv )
{
	VideoCapture video("/home/juarez408/Copy/UnB/2-2013/PVC/Projeto3/data/video.avi");
	Mat frameCaptured, previous, prevPrev, output;
	Mat process ,processP;
	if(!video.isOpened())
		{
			cout << "Video não pode ser aberto!" << endl;
			return -1;
		}

	//------------------------------------------------------------------
	//--------------------CRIA E DEFINE JANELAS-------------------------
	//------------------------------------------------------------------

	namedWindow( "Original Video", CV_WINDOW_AUTOSIZE );
	namedWindow( "BG", CV_WINDOW_AUTOSIZE );
	namedWindow( "FG", CV_WINDOW_AUTOSIZE );
	namedWindow( "fluxoO", CV_WINDOW_AUTOSIZE );
	namedWindow( "output", CV_WINDOW_AUTOSIZE );


	cvMoveWindow("Original Video", 0, 0);
	cvMoveWindow("BG", 300, 0);
	cvMoveWindow("FG", 600, 0);
	cvMoveWindow("fluxoO", 900, 0);

	cvMoveWindow("output", 0, 300);

	DenseFlux flux;

	cv::BackgroundSubtractorMOG2 bg;
    bg.nmixtures = 20;
    bg.bShadowDetection = true;
    bg.nShadowDetection = 127;
    bg.fTau = 0.4;

    Mat backG, foreG;
    Mat fluxImg;

	for(int i = 0; ; i++)//LAÇO PRINCIPAL DO PROGRAMA
  		{
		//---------------------captura e teste---------------
			video >> frameCaptured;

			Mat frame;

			frameCaptured.copyTo(frame);

			medianBlur ( frame, frame, 7);

			if(frame.empty())
					{
					cout << "frame não pôde ser capturado"<<endl;
					break;
					}

			//---------------------background---------------
			bg.operator ()(frame,foreG);
	        bg.getBackgroundImage(backG);

			cv::erode(foreG,foreG,cv::Mat());
			cv::dilate(foreG,foreG,cv::Mat());

			//--------------------fluxo---------------
			frame.copyTo(output);
			if(i > 4)
			{
				 process = frame - previous;
				 processP = previous - prevPrev;

				 frameCaptured.copyTo(fluxImg);

				 flux.fluxCalculate(process, processP);
				 flux.drawOptFlowMap(fluxImg, 8, 1.5, CV_RGB(0, 255, 0));
			}
			previous.copyTo(prevPrev);
			frame.copyTo(previous);

  			imshow("Original Video", frameCaptured);
			imshow("BG", backG);
			imshow("FG", foreG);
  			if(i > 4){
  				imshow("fluxoO", fluxImg);
  			}

  //------------------------------------------------------------------
  //--------------------ESPERA OU TERMINA A EXECUÇÃO------------------
  //------------------------------------------------------------------
            int wait_c = cvWaitKey(50);
  			if((char)wait_c == 27 )
  				{// char == 27 : ESC key
  				cout << "\n\n execução será encerrada!"<<endl;
  				break;
  				}
  		}//FIM DO LAÇO PRINCIPAL


	cout << "fim" <<endl;

	waitKey(0);



	return 0;
}
