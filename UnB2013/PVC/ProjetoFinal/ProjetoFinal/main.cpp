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

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);
    ProjetoFinal mainWindow;
    mainWindow.show();


//    MyKalmanFilter::runDemo4(mainWindow);




    return prog.exec();
}
