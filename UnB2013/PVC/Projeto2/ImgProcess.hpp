#ifndef IMG_PROCESS_HPP_
#define IMG_PROCESS_HPP_

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

extern int lowThresholdLinear;

#ifdef HOUGH_SIMPLES
	vector<Vec2f> linearHough(Mat src){
			 Mat dst, cdst;
			 Canny(src, dst, 50, 200, 3);


			  vector<Vec2f> lines;
			  HoughLines(dst, lines, 1, CV_PI/180, lowThresholdLinear+1, 50, 10 );

			 return lines;

		}

	void drawLines(Mat src, vector<Vec2f> lines){

			for( size_t i = 0; i < lines.size(); i++ )
			  {
				 float rho = lines[i][0], theta = lines[i][1];
				 Point pt1, pt2;
				 double a = cos(theta), b = sin(theta);
				 double x0 = a*rho, y0 = b*rho;
				 pt1.x = cvRound(x0 + 1000*(-b));
				 pt1.y = cvRound(y0 + 1000*(a));
				 pt2.x = cvRound(x0 - 1000*(-b));
				 pt2.y = cvRound(y0 - 1000*(a));
				 line( src, pt1, pt2, Scalar(0,0,255), 3, CV_AA);
			  }

	}

#else

	vector<Vec4i> linearHough(Mat src){
			 Mat dst;

			 Canny(src, dst, 50, 200, 3);

			 vector<Vec4i> lines;
			 HoughLinesP(dst, lines, 1, CV_PI/180, lowThresholdLinear+1, 50, 10 );

			 return lines;
		}

	void drawLines(Mat src, vector<Vec4i> lines){
		  for( size_t i = 0; i < lines.size(); i++ )
		  {
			Vec4i l = lines[i];
			line( src, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, CV_AA);
		  }
	}

#endif
	extern int lowThresholdCircles;

	vector<Vec3f> circlesHough(Mat &src){
		 Mat src_gray, aux_src;
		 src.copyTo(aux_src);
		 cvtColor(src, src_gray, CV_BGR2GRAY);
		 GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );

		 vector<Vec3f> circles;


		 HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT,
				  1, src_gray.rows/8, lowThresholdCircles + 5, 100, 0, 0 );

		 return circles;
	}

	void drawCircles(Mat src, vector<Vec3f> circles){
		/// Draw the circles detected
		  for( size_t i = 0; i < circles.size(); i++ )
		  {
		      Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		      int radius = cvRound(circles[i][2]);
		      // circle center
		      circle( src, center, 3, Scalar(0,255,0), -1, 8, 0 );
		      // circle outline
		      circle( src, center, radius, Scalar(255,0,0), 3, 8, 0 );
		   }
	}

	#ifdef HOUGH_SIMPLES
		void getCirclesLines(Mat src,vector<Vec3f> &lines, vector<Vec3f> &circles)
			{
			lines = linearHough(src);
			circles = circlesHough(src);
			}
	#else
		void getCirclesLines(Mat src, vector<Vec4i> &lines, vector<Vec3f> &circles)
				{
				lines = linearHough(src);
				circles = circlesHough(src);
				}
	#endif

	void makeContagem(vector<Vec4i> lines, vector<Vec3f> circles,
		int &nLines, int &nCircles){
		nLines = lines.size();
		nCircles = circles.size();
	}

	double media(int array[], int n){
		double media = 0;
		for(int i = 0; i < n; i++)
			media +=(double) array[i];
		media /= (double)n;
		return media;
	}



#endif /* IMG_PROCESS_HPP_ */
