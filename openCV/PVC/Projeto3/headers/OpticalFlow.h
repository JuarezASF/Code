/*
 * OpticalFlow.h
 *
 *  Created on: 16/11/2013
 *      Author: juarez408
 */

#ifndef OPTICALFLOW_H_
#define OPTICALFLOW_H_

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>
using namespace cv;
using namespace std;

void opticFlowCalculate(Mat &previous, Mat &current);
/**o primeiro elemento são os pontos
 * o segundo são as velcidades respectivas*/

void drawNormalizedArrows(Mat &img, vector<Point2f> &P,
		vector<Point2f> &V);

#endif /* OPTICALFLOW_H_ */
