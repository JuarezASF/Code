/*
 * ProjetoFinal.cpp
 *
 *  Created on: 23/11/2013
 *      Author: juarez408
 */

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <QApplication>


#include <iostream>
#include <sstream>
#include <cassert>

#include "MyKalmanFilter.h"
#include "UserInterface.h"

using namespace std;
using namespace cv;

int iTau = 50;

Scalar minCorHSV(0, 0, 0);
Scalar maxCorHSV(179, 255, 255);


/*HSV color space is consists of 3 matrices,
 *'hue', 'saturation' and 'value'. In OpenCV,
 * value range for  'hue', 'saturation' and
 *'value'  are respectively 0-179, 0-255 and 0-255

Orange  0-22
Yellow 22- 38
Green 38-75
Blue 75-130
Violet 130-160
Red 160-179
*/

bool CONTROL_BGSub = false;
bool CONTROL_COLORDETECTION = true;
bool CONTROL_FILTER_GAUSSIAN = true;

bool CONTROL_MODE_RUN         = true;
bool CONTROL_MODE_CALIBRATION = false;

bool CONTROL_KALMAN = false;

int SizeGaussFilter = 31;

int ColorDetectionThreshold = 30;

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    ProjetoFinal mainWindow;
    mainWindow.show();


//    MyKalmanFilter::runDemo4(mainWindow);




    return prog.exec();
}
