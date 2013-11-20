/*
 * DenseFlux.h
 *
 *  Created on: 18/11/2013
 *      Author: juarez408
 */

#ifndef DENSEFLUX_H_
#define DENSEFLUX_H_

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>

using namespace cv;
using namespace std;

class DenseFlux {
private:

	Mat gray, prevGray, prev, frame, flux;
	double maxFlux;
	vector<vector<Point2f> > interestData;
	int nObjects;

public:
	DenseFlux();
	virtual ~DenseFlux();

	void fluxCalculate(Mat &frame, Mat &previous);

	void drawOptFlowMap(Mat& output, unsigned int step,
			float threshold, const Scalar& color);

	void calcInterestPoints(const Mat &data,
			const int step, float threshold);

	void countObjects(const Mat& data, const int step,
					const float thresholdFlux);


	const Mat& getFlux() const;
	void setFlux(const Mat& flux);
	const Mat& getFrame() const;
	void setFrame(const Mat& frame);
	const Mat& getGray() const;
	void setGray(const Mat& gray);
	const Mat& getPrev() const;
	void setPrev(const Mat& prev);
	const Mat& getPrevGray() const;
	void setPrevGray(const Mat& prevGray);
	double getMaxFlux() const;
	void setMaxFlux(double maxFlux);
	const vector<vector<Point2f> >& getInterestData() const;
	void setInterestData(const vector<vector<Point2f> >& interestData);
	void eraseInterestData();

	int getObjects() const {
		return nObjects;
	}

	void setObjects(int objects) {
		nObjects = objects;
	}
};




#endif /* DENSEFLUX_H_ */
