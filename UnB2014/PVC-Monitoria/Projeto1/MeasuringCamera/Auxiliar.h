#ifndef MEASURINGCAMERA_H
#define MEASURINGCAMERA_H
/*
    FUNÇÕES AUXILIARES DO PROJETO
*/

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <iostream>
#include <sstream>
#include <cassert>

using namespace cv;
using namespace std;

extern int minColor0;
extern int minColor1;
extern int minColor2;

extern int maxColor0;
extern int maxColor1;
extern int maxColor2;

extern Scalar colorMin;
extern Scalar colorMax;

extern RNG rng;

extern const char* window1;
extern const char* window2;
extern const char* window3;
extern const char* window4;

extern const char* track1;
extern const char* track2;
extern const char* track3;
extern const char* track4;
extern const char* track5;
extern const char* track6;
extern const char* track7;
extern const char* track8;

extern const char* switch0;
extern const char* switch1;
extern const char* switch2;

extern const int color0Max;
extern const int color1Max;
extern const int color2Max;

extern int definedColorIndex;

extern int SizeGaussFilter;
extern int SizeGaussFilterN;
extern const int max_SizeGaussFilter;

extern const int max_switch;
extern int CONTROL_COLOR_TRHRESHOLD;
extern int CONTROL_FIND_RECTANGLES;
extern int CONTROL_TERMINATE;
extern int CONTROL_ERODE_DILATE;

extern int definedColorIndex;
extern const int max_definedColorIndex;



void ColorDetection(Mat &rgbInputImg, Mat &thresholdedOutputImg, Scalar &colorMin, Scalar &colorMax){

    if(rgbInputImg.channels() != 3)
       throw String("ColorDetection informa: A IMAGEM DE ENTRADA DEVE TER 3 CANAIS!(RGB)");

    Mat hsvInput;
    cvtColor(rgbInputImg, hsvInput, CV_BGR2HSV);
    if(!thresholdedOutputImg.empty())
        thresholdedOutputImg.release();
    (ColorDetection::GetThresholdedImage(hsvInput, colorMin, colorMax)).copyTo(thresholdedOutputImg);
}

void colorChanged(int, void*){
    colorMin[0] = minColor0;
    colorMin[1] = minColor1;
    colorMin[2] = minColor2;

    colorMax[0] = maxColor0;
    colorMax[1] = maxColor1;
    colorMax[2] = maxColor2;
}

void onGaussSizeNChanged(int, void*){
    SizeGaussFilter = 2*SizeGaussFilterN + 1;
}

vector<Rect> FindAndDrawBoundigRects(Mat &input, Mat &outputImg){
      vector<vector<Point> > contours;
      vector<Vec4i> hierarchy;
      Mat thresholdedImg;

      input.copyTo(thresholdedImg);

    /// Find contours
      findContours( thresholdedImg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

      /// Approximate contours to polygons + get bounding rects and circles
      vector<vector<Point> > contours_poly( contours.size() );
      vector<Rect> boundRect( contours.size() );

      for( unsigned int i = 0; i < contours.size(); i++ )
         {
            approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
            boundRect[i] = boundingRect( Mat(contours_poly[i]) );
         }

      /// Draw polygonal contour + bonding rects
      cvtColor(outputImg, outputImg, CV_GRAY2BGR);
      for( unsigned int i = 0; i< contours.size(); i++ )
         {
           Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
           drawContours( outputImg, contours_poly, i, color);
           rectangle( outputImg, boundRect[i].tl(), boundRect[i].br(), color);
         }

      return boundRect;
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
            minCor = Scalar(38, 70, 154);
            maxCor = Scalar(75, 255, 255);
            //calibrado para o cartão verde de teste
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

void CreatWindowsTrackbarsSwitches(){
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
    createTrackbar( track7, window3, &SizeGaussFilterN, max_SizeGaussFilter, onGaussSizeNChanged);
    createTrackbar( track8, window3, &definedColorIndex, max_definedColorIndex, onDefinedColor);

    createTrackbar( switch0, window4, &CONTROL_TERMINATE, max_switch);
    createTrackbar( switch1, window4, &CONTROL_FIND_RECTANGLES, max_switch);
    createTrackbar( switch2, window4, &CONTROL_ERODE_DILATE, max_switch);

}

#endif // MEASURINGCAMERA_H
