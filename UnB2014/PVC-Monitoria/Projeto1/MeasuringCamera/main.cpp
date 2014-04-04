#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

#include "JASF.h"

using namespace cv;
using namespace std;

int iTau = 3;
const int iTauMax = 100;
//teste de corretor asdf asdf Isto é um teste.
float fFluxThreshold = 0.08;
int iFluxTh = 8;
const int iFluxThMax = 100;

int waitTime = 10;
int waitTimeMax = 100;




void onTrackbar2(int, void*){
    fFluxThreshold = ((float)iFluxTh)/((float)iFluxThMax);
}



int main( int argc, char** argv )
{
    VideoCapture video;
try{
    video = JASF::initVideo();
}
    catch(string E){
        cout << E << endl;
    }

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
    const char* window3_2 = "prevFG";
    const char* window4 = "FluxoO";
    const char* window5 = "output";



    namedWindow( window1, CV_WINDOW_AUTOSIZE );
    namedWindow( window2, CV_WINDOW_AUTOSIZE );
    namedWindow( window3, CV_WINDOW_AUTOSIZE );
    namedWindow( window3_2, CV_WINDOW_AUTOSIZE );
    namedWindow( window4, CV_WINDOW_AUTOSIZE );
    namedWindow( window5, CV_WINDOW_AUTOSIZE );


    //primeira linha de janelas
    cvMoveWindow(window1, 0, 0);
    cvMoveWindow(window2, 350, 0);
    cvMoveWindow(window3, 700, 0);

    //segunda linha de janelas
    cvMoveWindow(window3_2, 0, 300);
    cvMoveWindow(window4, 350, 300);
    cvMoveWindow(window5, 700, 300);


    const char* track2 = "flux threshold";
    createTrackbar( track2, window4, &iFluxTh, iFluxThMax, onTrackbar2);

    const char* track3 = "wait Time";
    createTrackbar( track3, window1, &waitTime, waitTimeMax);






    for(int i = 0; ; i++)//LAÇO PRINCIPAL DO PROGRAMA
        {
        Mat frameCaptured, output;
        //---------------------captura e teste---------------
            video >> frameCaptured;

            Mat frame;


            imshow(window1, frameCaptured);

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
