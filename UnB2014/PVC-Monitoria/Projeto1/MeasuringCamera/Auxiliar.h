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

void FindAndDrawBoundigRects(Mat &input, Mat &outputImg){
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
}

#endif // MEASURINGCAMERA_H
