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
	static void Cross(Mat &img, const Point center,
			const Scalar &color, float d);

	static void Crosses(Mat &img, vector<Point> points,
						vector<Scalar> colors ,float d,
						vector<bool> toPaint);

	static void dashedLine(Mat &img, const Point &start,
			const Point & end, const Scalar &color, int dashSize = 2);

	static void Line(Mat &img, const Point &start,
			const Point & end, const Scalar &color);

	static void Text(Mat &img, Point origin, string text,
			Scalar color, double fontScale);

	static void Text_in_a_Box(Mat &img, Point origin, string text,
			Scalar color, double fontScale);
};

#endif /* DRAW_H_ */
