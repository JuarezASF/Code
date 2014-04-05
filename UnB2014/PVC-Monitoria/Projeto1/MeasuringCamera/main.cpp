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
#include "Filtros.h"

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

const char* track7 = "SizeGaussFilter (2n+1)";
const char* track8 = "Cor Definida: \n [1] laranja  [2] amarelo \n [3]verde [4] azul \n [5]violeta [6] vermelho";

const char* switch0 = "Terminar Programa";
const char* switch1 = "Encontrar Contornor?";
const char* switch2 = "Erode and Dilate?";


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

int SizeGaussFilter = 13;
int SizeGaussFilterN = 6;
const int max_SizeGaussFilter = 10;

const int max_switch = 1;
int CONTROL_COLOR_TRHRESHOLD = 0;
int CONTROL_FIND_RECTANGLES = 0;
int CONTROL_TERMINATE = 0;
int CONTROL_ERODE_DILATE = 0;

int definedColorIndex = 3;
const int max_definedColorIndex = 6;


// para agerar números pseudo-aleatórios
RNG rng(12345);


Mat inputImg, outputImg, toProcess;

//veja implementação em MeasuringCamera.h
void ColorDetection(Mat &rgbInputImg, Mat &thresholdedOutputImg, Scalar &colorMin, Scalar &colorMax);
void colorChanged(int, void*);
void onGaussSizeNChanged(int, void*);
void onDefinedColor(int, void*);

int main( )
{

    try{
    VideoCapture video;
    video = JASF::initVideo();
    video >> inputImg;

    //------------------------------------------------------------------
    //--------------------CRIA E DEFINE JANELAS-------------------------
    //------------------------------------------------------------------

    CreatWindowsTrackbarsSwitches();

    //seta condição inicial
    onDefinedColor(0,0);


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
            if(CONTROL_ERODE_DILATE){
                //Filtros::Erosion(outputImg, outputImg, 3);
                Filtros::Dilation(outputImg, outputImg, 3);
            }

            vector<Rect> objetos;
            if(CONTROL_FIND_RECTANGLES == 1)
                objetos = FindAndDrawBoundigRects(outputImg, outputImg);


        //------------------------------------------------------------------
        //--------------------EXIBE RESULTADOS------------------
        //------------------------------------------------------------------

            imshow(window1, inputImg);
            imshow(window2, outputImg);
            if(CONTROL_FIND_RECTANGLES == 1)
            {
                for(unsigned int n = 0; n < 30; n++)
                    cout << "\n";
                for(unsigned int n = 0; n < objetos.size(); n++){
                    Rect &objeto = objetos[n];
                    cout << "Tamanho do objeto "<< n+1 << ":" << endl;
                    cout << "\t width :"<< objeto.width << "\n \t height: " << objeto.height << endl;
                       }

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
    }// FIM DO TRY
    catch(string E){
        cout << E << endl;
    }
    //waitKey(0);
    destroyAllWindows();



    return 0;
}
