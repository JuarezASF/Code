#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;


Mat src; Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

void drawContoursRetang(Mat &frame, vector<vector<Point> > contours){
		vector<vector<Point> > contours_poly( contours.size() );
		vector<Rect> boundRect( contours.size() );
		
		  for( int i = 0; i < contours.size(); i++ )
			 {
				 approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
			   boundRect[i] = boundingRect( Mat(contours_poly[i]) );

			 }
		for( int i = 0; i< contours.size(); i++ )
			 {
			   Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
			   drawContours( frame, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
			   rectangle( frame, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );			  
			 }
}

void drawContoursCirc(Mat &frame, vector<vector<Point> > contours){
		 vector<Point2f>center( contours.size() );
		  vector<float>radius( contours.size() );
		vector<vector<Point> > contours_poly( contours.size() );
		vector<Rect> boundRect( contours.size() );
		  for( int i = 0; i < contours.size(); i++ )
			 {

				 approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
			   boundRect[i] = boundingRect( Mat(contours_poly[i]) );
			    minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
			 }
		for( int i = 0; i< contours.size(); i++ )
			 {
			   Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
			   circle( frame, center[i], (int)radius[i], color, 2, 8, 0 );			  
			 }
}

 
int main(int argc, char *argv[])
{
    cv::Mat frame;
    cv::Mat back;
    cv::Mat fore;
    cv::VideoCapture cap("/home/juarez408/Copy/UnB/2-2013/PVC/Projeto3/data/video.avi");
    cv::BackgroundSubtractorMOG2 bg;
    bg.nmixtures = 20;
    bg.bShadowDetection = false;
 
    std::vector<std::vector<cv::Point> > contours;
 
    cv::namedWindow("Frame");
    cv::namedWindow("BG");

 		cvMoveWindow("BG", 300, 0);
    for(;;)
    {
        cap >> frame;
        bg.operator ()(frame,fore);
        bg.getBackgroundImage(back);
        for(int i = 0; i < 1; i++){
			cv::erode(fore,fore,cv::Mat());
			cv::dilate(fore,fore,cv::Mat());
						cv::dilate(fore,fore,cv::Mat());
									cv::dilate(fore,fore,cv::Mat());
			}
        cv::findContours(fore,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
        cv::drawContours(frame,contours,-1,cv::Scalar(0,0,255),2);

		drawContoursRetang(frame, contours);
		drawContoursCirc(frame, contours);


        cv::imshow("Frame",frame);
        cv::imshow("BG",back);
        if(cv::waitKey(30) >= 0) break;
    }
    return 0;
}
