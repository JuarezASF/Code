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

int iTau = 50;
const int iTauMax = 100;

float fFluxThreshold = 0.08;
int iFluxTh = 8;
const int iFluxThMax = 100;

int waitTime = 10;
int waitTimeMax = 100;


cv::BackgroundSubtractorMOG2 bg;

void onTrackbar1(int, void*){
    bg.fTau = ((float)iTau)/((float)iTauMax);
}

void onTrackbar2(int, void*){
    fFluxThreshold = ((float)iFluxTh)/((float)iFluxThMax);
}



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

	const char* window1 = "Original Video";
	const char* window2 = "BG";
	const char* window3 = "FG";
	const char* window4 = "FluxoO";
	const char* window5 = "output";


	namedWindow( window1, CV_WINDOW_AUTOSIZE );
	namedWindow( window2, CV_WINDOW_AUTOSIZE );
	namedWindow( window3, CV_WINDOW_AUTOSIZE );
	namedWindow( window4, CV_WINDOW_AUTOSIZE );
	namedWindow( window5, CV_WINDOW_AUTOSIZE );


	//primeira linha de janelas
	cvMoveWindow(window1, 0, 0);
	cvMoveWindow(window2, 300, 0);
	cvMoveWindow(window3, 600, 0);
	cvMoveWindow(window4, 900, 0);
	//segunda linha de janelas
	cvMoveWindow(window5, 0, 300);

	const char* track1 = "shadow finder Tau";
	createTrackbar( track1, window3, &iTau, iTauMax, onTrackbar1);

	const char* track2 = "flux threshold";
	createTrackbar( track2, window4, &iFluxTh, iFluxThMax, onTrackbar2);

	const char* track3 = "wait Time";
	createTrackbar( track3, window1, &waitTime, waitTimeMax);
	DenseFlux flux;


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
			vector<vector<Point2f> > interestPoints;
			int nObjects;

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
				int step = 8;

				 process = frame - previous;
				 processP = previous - prevPrev;

				 frameCaptured.copyTo(fluxImg);

				 flux.fluxCalculate(process, processP);
				 flux.drawOptFlowMap(fluxImg, step, fFluxThreshold,
						 	 	 	 	 CV_RGB(0, 255, 0));

				 flux.countObjects(frameCaptured, step,fFluxThreshold);
				 flux.getObjects();

				interestPoints = flux.getInterestData();
				nObjects = flux.getObjects();

				frameCaptured.copyTo(output);

				myK_Means(output, interestPoints ,nObjects);
			}




			previous.copyTo(prevPrev);
			frame.copyTo(previous);

  			imshow(window1, frameCaptured);
			imshow(window2, backG);
			imshow(window3, foreG);
  			if(i > 4){
  				imshow(window4, fluxImg);
  				imshow(window5, output);

  			}

  //------------------------------------------------------------------
  //--------------------ESPERA OU TERMINA A EXECUÇÃO------------------
  //------------------------------------------------------------------
            int wait_c = cvWaitKey(waitTime);
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
