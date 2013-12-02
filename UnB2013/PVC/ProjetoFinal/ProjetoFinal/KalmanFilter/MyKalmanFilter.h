/*
 * MyKalmanFilter.h
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#ifndef MYKALMANFILTER_H_
#define MYKALMANFILTER_H_

#include <iostream>
#include <vector>
#include <string>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

#include "Draw.h"
#include "myMath.h"
#include "myString.h"

#include "UserInterface.h"
#include "myTimer.h"

using namespace cv;
using namespace std;


class MyKalmanFilter {

public:
	static void runDemo();

	static void runDemo2();

    //static void runDemo3(ProjetoFinal &mainWindow);

    //static void runDemo4(ProjetoFinal &mainWindow);
};

#endif /* MYKALMANFILTER_H_ */
