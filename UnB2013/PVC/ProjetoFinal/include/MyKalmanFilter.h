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

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>

#include "Draw.h"

using namespace cv;
using namespace std;


class MyKalmanFilter {

public:
	static void runDemo();

	static void runDemo2();
};

#endif /* MYKALMANFILTER_H_ */
