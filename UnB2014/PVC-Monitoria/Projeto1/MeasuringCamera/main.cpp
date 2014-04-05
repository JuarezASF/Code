#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

#include "JASF.h"
#include "ColorDetection.h"
#include "Auxiliar.h"

using namespace cv;
using namespace std;

const char* window1 = "Vídeo de Entrada";
const char* window2 = "Vídeo de Saída";
const char* window3 = "Parâmetros de Configuração";
const char* window4 = "Switches";

const char* track1 = "HSV minColor[0]";
const char* track2 = "HSV minColor[1]";
const char* track3 = "HSV minColor[2]";
const char* track4 = "HSV maxColor[0]";
const char* track5 = "HSV maxColor[1]";
const char* track6 = "HSV maxColor[2]";

int minColor0 = 0;
int minColor1 = 0;
int minColor2 = 0;

int maxColor0 = 179;
int maxColor1 = 255;
int maxColor2 = 255;

const int color0Max = 179;
const int color1Max = 255;
const int color2Max = 255;

Scalar colorMin(0,0,0);
Scalar colorMax(179, 255, 255);

int waitTime = 50;

int SizeGaussFilter = 3;
int SizeGaussFilterN = 1;
const int max_SizeGaussFilter = 10;

const int max_switch = 1;
int CONTROL_COLOR_TRHRESHOLD = 0;
int CONTROL_FIND_RECTANGLES = 0;
int CONTROL_TERMINATE = 0;

int definedColorIndex = 0;
const int max_definedColorIndex = 6;


// para agerar números pseudo-aleatórios
RNG rng(12345);


Mat inputImg, outputImg, toProcess;

//veja implementação em MeasuringCamera.h
void ColorDetection(Mat &rgbInputImg, Mat &thresholdedOutputImg, Scalar &colorMin, Scalar &colorMax);
void colorChanged(int, void*);
void onGaussSizeNChanged(int, void*){
    SizeGaussFilter = 2*SizeGaussFilterN + 1;
}

void onDefinedColor(int, void*){
    Scalar &minCor = colorMin;
    Scalar &maxCor = colorMax;

    switch(definedColorIndex){
        case 1://laranja 0-22
            minCor = Scalar(0, 70, 0);
            maxCor = Scalar(22, 255, 255);
            break;

        case 2://amarelo 22-38
            minCor = Scalar(22, 70, 0);
            maxCor = Scalar(38, 255, 255);
            break;

        case 3: // verde 38-75
            minCor = Scalar(38, 70, 0);
            maxCor = Scalar(75, 255, 255);
            break;

        case 4://azul 75-130
            minCor = Scalar(75, 70, 0);
            maxCor = Scalar(130, 255, 255);
            break;

        case 5:// violeta 130-160
            minCor = Scalar(130, 70, 0);
            maxCor = Scalar(160, 255, 255);
            break;

        case 6:// vermelho 160-179
            minCor = Scalar(160, 70, 0);
            maxCor = Scalar(179, 255, 255);
            break;

        default:
            minCor = Scalar(0, 0, 0);
            maxCor = Scalar(179, 255, 255);
            break;
        }

    minColor0 = colorMin[0];
    minColor1 = colorMin[1];
    minColor2 = colorMin[2];

    maxColor0 = colorMax[0];
    maxColor1 = colorMax[1];
    maxColor2 = colorMax[2];

    setTrackbarPos(track1, window3, minColor0);
    setTrackbarPos( track2,window3, minColor1);
    setTrackbarPos( track3,window3, minColor2);

    setTrackbarPos( track4,window3, maxColor0);
    setTrackbarPos( track5,window3, maxColor1);
    setTrackbarPos( track6,window3, maxColor2);
}

int main( )
{

    try{
    VideoCapture video;
    video = JASF::initVideo();
    video >> inputImg;

    //------------------------------------------------------------------
    //--------------------CRIA E DEFINE JANELAS-------------------------
    //------------------------------------------------------------------



    namedWindow( window1, CV_WINDOW_AUTOSIZE);
    namedWindow( window2, CV_WINDOW_AUTOSIZE );
    namedWindow( window3, CV_WINDOW_AUTOSIZE );
    namedWindow( window4, CV_WINDOW_AUTOSIZE );


    cvMoveWindow(window1, 0, 0);
    cvMoveWindow(window2, 700, 0);
    cvMoveWindow(window3, 0, 350);
    cvMoveWindow(window4, 700, 350);


    createTrackbar( track1, window3, &minColor0, color0Max, colorChanged);
    createTrackbar( track2, window3, &minColor1, color1Max, colorChanged);
    createTrackbar( track3, window3, &minColor2, color2Max, colorChanged);
    createTrackbar( track4, window3, &maxColor0, color0Max, colorChanged);
    createTrackbar( track5, window3, &maxColor1, color1Max, colorChanged);
    createTrackbar( track6, window3, &maxColor2, color2Max, colorChanged);

    const char* track7 = "SizeGaussFilter (2n+1)";
    createTrackbar( track7, window3, &SizeGaussFilterN, max_SizeGaussFilter, onGaussSizeNChanged);

    const char* track8 = "Cor Definida: \n [1] laranja  [2] amarelo \n [3]verde [4] azul \n [5]violeta [6] vermelho";
    createTrackbar( track8, window3, &definedColorIndex, max_definedColorIndex, onDefinedColor);


    const char* switch0 = "Terminar Programa";
    createTrackbar( switch0, window4, &CONTROL_TERMINATE, max_switch);

    const char* switch1 = "Encontrar Contornor?";
    createTrackbar( switch1, window4, &CONTROL_FIND_RECTANGLES, max_switch);


    while(1)//LAÇO PRINCIPAL DO PROGRAMA
        {
        if(CONTROL_TERMINATE == 1){
            throw string("O Programa irá encerrar! Aperte para termianar.");
            break;
        }
        //------------------------------------------------------
        //--------------------CAPTURA---------------------------
        //------------------------------------------------------
            video >> inputImg;
                if(inputImg.empty()){
                    cout << "Imagem ainda não foi aberta!" << endl;
                    continue;
                }
            inputImg.copyTo(toProcess);


        //------------------------------------------------------
        //--------------------PROCESSA--------------------------
        //------------------------------------------------------
            medianBlur ( toProcess, toProcess, SizeGaussFilter);
            ColorDetection(toProcess, outputImg, colorMin, colorMax);
            if(CONTROL_FIND_RECTANGLES == 1)
                FindAndDrawBoundigRects(outputImg, outputImg);


        //------------------------------------------------------------------
        //--------------------EXIBE RESULTADOS------------------
        //------------------------------------------------------------------

            imshow(window1, inputImg);
            imshow(window2, outputImg);

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
    }// FIM DO TRY
    catch(string E){
        cout << E << endl;
    }
    //waitKey(0);
    destroyAllWindows();



    return 0;
}
