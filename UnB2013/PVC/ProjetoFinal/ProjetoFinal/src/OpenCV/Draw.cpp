/*
 * Draw.cpp
 *
 *  Created on: 24/11/2013
 *      Author: juarez408
 */

#include "Draw.h"

void Draw::Cross(Mat &img, const Point center,
					const Scalar &color, float d)
{
	line( img, Point( center.x - d, center.y - d),
				Point( center.x + d, center.y + d ),
				color, 2, CV_AA, 0);

	line( img, 	Point( center.x + d, center.y - d ),
				Point( center.x - d, center.y + d ),
				color, 2, CV_AA, 0);
}

void Draw::Crosses(Mat &img, vector<Point> points,
					vector<Scalar> colors ,float d, vector<bool> toPaint)
	{

		bool MODE_SINGLE_COLOR = false;

		if(points.size() != colors.size())
			MODE_SINGLE_COLOR = true;

		for(unsigned int i = 0; i < points.size(); i++){
				if(toPaint[i])
				{
					Scalar *currentColor;
					if(MODE_SINGLE_COLOR)
						currentColor =
								new Scalar(255, 255, 255);
					else
						currentColor =
								new Scalar(colors[i]);
					Draw::Cross(img, points[i],												*currentColor,d);

					delete currentColor;
				}
			}
	}


void Draw::dashedLine(Mat &img, const Point &start, const Point &end,
					const Scalar &color, int dashSize)
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

void Draw::Line(Mat &img, const Point &start, const Point & end,
					const Scalar &color)
{
	line(img, start, end, color, 1);
}

void Draw::Text(Mat &img, Point origin, string text,
		Scalar color, double fontScale){


	Scalar boxColor(255, 255, 255);
	int fontFace = FONT_HERSHEY_SIMPLEX;
	int thickness = 1;
	int lineType = 8;
	bool bottomLeftOrigin = false;

	putText(img, text, origin, fontFace, fontScale,
			color, thickness,lineType, bottomLeftOrigin);

}

void Draw::Text_in_a_Box(Mat &img, Point origin, string text,
										Scalar color, double fontScale)
{

	Scalar boxColor(255, 255, 255);
	int fontFace = FONT_HERSHEY_SIMPLEX;
	int thickness = 1;
	int lineType = 8;
	bool bottomLeftOrigin = false;
	int baseline = 0;

	Size textSize = getTextSize(text, fontFace,
	                            fontScale, thickness, &baseline);


	// draw the box
	rectangle(img, origin + Point(0, baseline),
	          origin + Point(textSize.width, -textSize.height),
	          boxColor);


	putText(img, text, origin, fontFace, fontScale,
			color, thickness,lineType, bottomLeftOrigin);

}

void Draw::Circles(Mat &src, vector<Vec3f> circles,
							vector<Scalar> colors){
	/// Draw the circles detected
	  for( size_t i = 0; i < circles.size(); i++ )
	  {
		  Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		  int radius = cvRound(circles[i][2]);
		  // circle center
		  circle( src, center, 3, colors[i], -1, 8, 0 );
		  // circle outline
		  circle( src, center, radius, colors[i], 3, 8, 0 );
	   }
}

