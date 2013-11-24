/*
 * Draw.h
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#ifndef DRAW_H_
#define DRAW_H_

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "myMath.h"

using namespace cv;

class Draw {
public:
	static void drawCross(Mat &img, Point center, Scalar color, float d);

	static void dashedLine(Mat &img, Point &start,
			Point & end, Scalar color, int dashSize = 2);
};

#endif /* DRAW_H_ */
