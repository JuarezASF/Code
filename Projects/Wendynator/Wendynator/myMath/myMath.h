/*
 * myMath.h
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#ifndef MYMATH_H_
#define MYMATH_H_

#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <cmath>

using namespace cv;

class myMath {
public:
	static double mod(Point &A);

	static KalmanFilter copyKF(KalmanFilter &origin);
};

#endif /* MYMATH_H_ */
