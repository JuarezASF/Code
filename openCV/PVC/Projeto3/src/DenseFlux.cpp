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

double DenseFlux::getMaxFlux() const {
	return maxFlux;
}

const vector<vector<Point2f> >& DenseFlux::getInterestData() const {
	return interestData;
}

void DenseFlux::setInterestData(const vector<vector<Point2f> >& interestData) {
	this->interestData = interestData;
}

void DenseFlux::setMaxFlux(double maxFlux) {
	this->maxFlux = maxFlux;
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

void DenseFlux::drawOptFlowMap(Mat& output, unsigned int step,
                    float threshold, const Scalar& color)
{
		calcInterestPoints(output, step, threshold);
		vector< vector<Point2f> > filteredData = getInterestData();

		vector<Point2f> point = filteredData[0];
		vector<Point2f> flux = filteredData[1];

		if(point.empty())
			return;

        for(unsigned int i = 0; i < point.size(); i += 1)
        {
            	line(output, point[i], Point(cvRound(point[i].x+flux[i].x),
            							cvRound(point[i].y+flux[i].y)),color);

				circle(output, point[i], 2, color, -1);


           }
}
void DenseFlux::eraseInterestData(){
	interestData.erase(interestData.end());
}

void DenseFlux::calcInterestPoints(const Mat &data,
		const int step, float threshold)
{
	/**
	 * retorna um vetor Data com os pontos de interesse
	 * 		Data[0] = pontos de interesse
	 * 		Data[1] = fluxo nos pontos de interesse
	 * */
	const Mat &flow = getFlux();
	float l_max = -10;
	vector<Point2f> filteredPoints;
	vector<Point2f> filteredFlux;
	vector<vector<Point2f> > filteredData;

	for(int y = 0; y < data.rows; y += step)
	{//descobre maior modulo
        for(int x = 0; x < data.cols; x += step)
        	{
        		const Point2f& fxy = flow.at<Point2f>(y, x);
        		float fx = fxy.x;
        		float fy = fxy.y;
        		float l = sqrt(fx*fx + fy*fy);                                                            // This function sets a basic threshold for drawing on the image

	            if(l>l_max) l_max = l;
	        }
	  }

	setMaxFlux(l_max);

	for(int y = 0; y < data.rows; y += step)
        for(int x = 0; x < data.cols; x += step)
        {
            const Point2f& fxy = flow.at<Point2f>(y, x);
            float fx = fxy.x;
            float fy = fxy.y;
            float l = sqrt(fx*fx + fy*fy);
            if(l >= threshold*l_max)
				{
            	filteredFlux.push_back(fxy);
            	filteredPoints.push_back(Point2f(x,y));
				}
        }

	filteredData.push_back(filteredPoints);
	filteredData.push_back(filteredFlux);

	if(!getInterestData().empty())
		eraseInterestData();
	setInterestData(filteredData);

}

void DenseFlux::countObjects(const Mat& data, const int step,
				const float thresholdFlux)
{
	int count = 0;
	float l_max = getMaxFlux();
	const Mat &flow = getFlux();
	bool inside = false;
	bool insidePrev = false;

	int maxLine = 0;
	for(int y = 0; y < data.rows; y += step)
	{
		count = 0;
        for(int x = 0; x < data.cols; x += step)
        {

            const Point2f& fxy = flow.at<Point2f>(y, x);
            float fx = fxy.x;
            float fy = fxy.y;
            float l = sqrt(fx*fx + fy*fy);

            insidePrev = inside;
            inside = false;
            if(l >= thresholdFlux*l_max)
				{
            		inside = true;
            		if(inside != insidePrev)
            			count ++;
            	}
        }
       if(count > maxLine)
    	   maxLine = count;
	}

	int maxCol = 0;
    for(int x = 0; x < data.cols; x += step)
	{
		count = 0;
		for(int y = 0; y < data.rows; y += step)
        {

            const Point2f& fxy = flow.at<Point2f>(y, x);
            float fx = fxy.x;
            float fy = fxy.y;
            float l = sqrt(fx*fx + fy*fy);

            insidePrev = inside;
            inside = false;
            if(l >= thresholdFlux*l_max)
				{
            		inside = true;
            		if(inside == false && insidePrev == true)
            			count ++;
            	}
        }
       if(count > maxCol)
    	   maxCol = count;
	}

    int MaxGlobal = (maxCol > maxLine)? maxCol : maxLine;

	setObjects((int)((float)MaxGlobal + 0.5));

}


