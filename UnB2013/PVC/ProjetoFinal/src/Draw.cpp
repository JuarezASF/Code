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

void Draw::dashedLine(Mat &img, Point &start, Point & end,
					Scalar color, int dashSize)
{
	// grabs pixels along the line (pt1, pt2)
	// from 8-bit 3-channel image to the buffer
	LineIterator it(img, start, end, 8);
	vector<Vec3b> buf(it.count);
	bool state = false;




	for(int i = 0; i < it.count; i++, ++it)
	{
		if(i%dashSize == 0)
			state = !state;
		if(state == true)
		{
			(*it)[0] = color[0];
			(*it)[1] = color[1];
			(*it)[2] = color[2];
		}
	}
}

