#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;

  int lowThreshold = 100 ;
  int const max_lowThreshold = 250;
  Mat src, src_gray;
  Mat show;


void myHoughCircle(int, void*)
{
  src.copyTo(show);

/// Apply the Hough Transform to find the circles
  vector<Vec3f> circles;
  HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, lowThreshold+1, 100, 0, 0 );
  

  /// Draw the circles detected
  for( size_t i = 0; i < circles.size(); i++ )
  {
      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
      int radius = cvRound(circles[i][2]);
      // circle center
      circle( show, center, 3, Scalar(0,255,0), -1, 8, 0 );
      // circle outline
      circle( show, center, radius, Scalar(0,0,255), 3, 8, 0 );
   }

  /// Show your results

  imshow( "Hough Circle Transform Demo", show ); 
}

/** @function main */
int main(int argc, char** argv)
{
  /// Read the image
  src = imread( argv[1], 1 );

  if( !src.data )
    { return -1; }

  /// Convert it to gray
  cvtColor( src, src_gray, CV_BGR2GRAY );

  namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
  
  /// Reduce the noise so we avoid false circle detection
  GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );

    /// Create a Trackbar for user to enter threshold
  createTrackbar( "Min Threshold:", "Hough Circle Transform Demo", &lowThreshold, max_lowThreshold, myHoughCircle );

  myHoughCircle(0,0);

  waitKey(0);
  imwrite( "./result.jpg", show);
  return 0;
}