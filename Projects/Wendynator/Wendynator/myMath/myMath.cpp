/*
 * myMath.cpp
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#include "myMath.h"

	double myMath::mod(Point &A){
		double mod = 0;
			mod = A.x*A.x + A.y*A.y;
		return sqrt(mod);
	}

	KalmanFilter myMath::copyKF(KalmanFilter &origin){
		KalmanFilter KF;

		//na ordem em que são definifos no .h
		origin.statePre.copyTo(KF.statePre);
		origin.statePost.copyTo(KF.statePost);
		origin.transitionMatrix.copyTo(KF.transitionMatrix);
		origin.controlMatrix.copyTo(KF.controlMatrix);
		origin.measurementMatrix.copyTo(KF.measurementMatrix);
		origin.processNoiseCov.copyTo(KF.processNoiseCov);
		origin.measurementNoiseCov.copyTo(KF.measurementNoiseCov);
		origin.errorCovPre.copyTo(KF.errorCovPre);
		origin.gain.copyTo(KF.gain);
		origin.errorCovPost.copyTo(KF.errorCovPost);

		return KF;
	}
