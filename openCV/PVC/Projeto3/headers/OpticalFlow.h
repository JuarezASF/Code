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


int opticFlowCalculate(cv::Mat &previous, cv::Mat &current);


#endif /* OPTICALFLOW_H_ */
