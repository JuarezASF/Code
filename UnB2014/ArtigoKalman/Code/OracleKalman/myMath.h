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
#include <unistd.h>

using namespace cv;

class myMath {
public:
	static double mod(Point &A);

	static KalmanFilter copyKF(KalmanFilter &origin);


    static void mysleep(unsigned millis) {
        ::usleep(millis * 1000);
    }
};

#endif /* MYMATH_H_ */
