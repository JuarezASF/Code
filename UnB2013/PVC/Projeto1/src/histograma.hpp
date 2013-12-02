#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>

#ifndef HISTOGRAMA_HPP
#define HISTOGRAMA_HPP

using namespace std;
using namespace cv;

int getColoredHist(Mat &src, Mat &dst)
{
  if( !src.data )
    { return -1; }

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  /// Establish the number of bins
  int histSize = 256;

  /// Set the ranges ( for B,G,R) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };

  bool uniform = true; bool accumulate = false;

  Mat b_hist, g_hist, r_hist;

  /// Compute the histograms:
  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

  // Draw the histograms for B, G and R
  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );

  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /// Normalize the result to [ 0, histImage.rows ]
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /// Draw for each channel
  for( int i = 1; i < histSize; i++ )
  {
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                       Scalar( 0, 255, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
  }

	histImage.copyTo(dst);

}

void segmentaHistograma(Mat &src, int hist_size, int nPartes = 12)
	{
		float *group = new float[(int) hist_size/nPartes];
		int n = 0;
		int membersInN = 0;
		
		for( int i = 1; i < hist_size; i++ )
		  {
			membersInN++;
			group[n] +=	src.at<float>(i);
			if(membersInN == nPartes)
				{
				group[n] /= membersInN;
				n++;	
				membersInN = 0;
				}
		  }
		if(hist_size%nPartes != 0 && membersInN != 0)
			group[n] /= membersInN;
	
	//	for( int i = 0; i < nPartes; i++ )
		//	cout << group[i] << "\t";
		//cout << endl << endl;
	}

int getGrayHist(Mat &src, Mat &dst, Mat &hist)
{
	//coloca em 'dst' a imagem com histograma e em
	// 'hist' o histograma em si(vetor com números)
  if( !src.data )
    { return -1; }
  /// Establish the number of bins

  int histSize = 256;
  /// Set the ranges ( for Gray) )
  float range[] = { 0, 256 } ;
  const float* histRange = { range };
  bool uniform = true; bool accumulate = false;
  Mat grayScaleHist;

  int hist_w = 512; int hist_h = 400;
  int bin_w = cvRound( (double) hist_w/histSize );
/*
 * 					CÁLCULO DO HISTOGRAMA
 * */
			Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0));
			calcHist( &src, 1, 0, Mat(), grayScaleHist, 1, &histSize, &histRange, uniform, accumulate );
			//calcula o histograma e salva em grayScaleHist
			normalize(grayScaleHist, grayScaleHist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
			//normaliza o histograma e salva em grayScaleHist

			segmentaHistograma(grayScaleHist, histSize);
						  /// Draw for each channel
			  for( int i = 1; i < histSize; i++ )
			  {
				  line( histImage, Point( bin_w*(i-1), hist_h - cvRound(grayScaleHist.at<float>(i-1)) ) ,
								   Point( bin_w*(i), hist_h - cvRound(grayScaleHist.at<float>(i)) ),
								   Scalar( 255, 0, 0), 2, 8, 0);
			  }


	histImage.copyTo(dst);
	grayScaleHist.copyTo(hist);

}
#endif
