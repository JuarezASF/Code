/*
 * Draw.cpp
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#include "Draw.h"


void Draw::drawCross(Mat &img, Point center, Scalar color, float d){
	line( img, Point( center.x - d, center.y - d),
				Point( center.x + d, center.y + d ),
				color, 2, CV_AA, 0);

	line( img, 	Point( center.x + d, center.y - d ),
				Point( center.x - d, center.y + d ),
				color, 2, CV_AA, 0);
}

