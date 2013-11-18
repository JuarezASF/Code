/*
 * DenseFlux.cpp
 *
 *  Created on: 18/11/2013
 *      Author: juarez408
 */

#include "../headers/DenseFlux.h"


DenseFlux::DenseFlux() {
	// TODO Auto-generated constructor stub

}

DenseFlux::~DenseFlux() {
	// TODO Auto-generated destructor stub
}

const Mat& DenseFlux::getFlux() const {
	return flux;
}

void DenseFlux::setFlux(const Mat& flux) {
	this->flux = flux;
}

const Mat& DenseFlux::getFrame() const {
	return frame;
}

void DenseFlux::setFrame(const Mat& frame) {
	this->frame = frame;
}

const Mat& DenseFlux::getGray() const {
	return gray;
}

void DenseFlux::setGray(const Mat& gray) {
	this->gray = gray;
}

const Mat& DenseFlux::getPrev() const {
	return prev;
}

void DenseFlux::setPrev(const Mat& prev) {
	this->prev = prev;
}

const Mat& DenseFlux::getPrevGray() const {
	return prevGray;
}

void DenseFlux::setPrevGray(const Mat& prevGray) {
	this->prevGray = prevGray;
}


void DenseFlux::fluxCalculate(Mat &frame, Mat &previous){

	Mat temp;


	this->setFrame(frame);
	cvtColor(frame, this->gray, CV_BGR2GRAY);

	this->setPrev(previous);
	cvtColor(previous, this->prevGray, CV_BGR2GRAY);


    if( prevGray.data )
			calcOpticalFlowFarneback(prevGray, gray, flux,
					0.5, 3, 15, 3, 5, 1.2, 0);
}

void DenseFlux::drawOptFlowMap(Mat& output, int step,
                    double, const Scalar& color)
{
	const Mat &flow = getFlux();

	float l_max = -10;
	for(int y = 0; y < output.rows; y += step)
	{//descobre maior modulo
        for(int x = 0; x < output.cols; x += step)
        	{
        		const Point2f& fxy = flow.at<Point2f>(y, x);
        		float fx = fxy.x;
        		float fy = fxy.y;
        		float l = sqrt(fx*fx + fy*fy);                                                            // This function sets a basic threshold for drawing on the image

	            if(l>l_max) l_max = l;
	        }
	    }

	for(int y = 0; y < output.rows; y += step)
        for(int x = 0; x < output.cols; x += step)
        {
            const Point2f& fxy = flow.at<Point2f>(y, x);
            float fx = fxy.x;
            float fy = fxy.y;
            float l = sqrt(fx*fx + fy*fy);
            if(l > 1)
				{

            	line(output, Point(x,y), Point(cvRound(x+fxy.x),
						cvRound(y+fxy.y)),color);
				circle(output, Point(x,y), 2, color, -1);

				}
           }
}

