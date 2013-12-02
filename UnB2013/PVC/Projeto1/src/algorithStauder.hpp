#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <sstream>

#ifndef STAUDER_HPP
#define STAUDER_HPP

using namespace std;
using namespace cv;
Mat getTrinarySignal(Mat current, Mat previous)
{
	Mat Dk;
	if(current.empty() || previous.empty())
		return Dk;

	int rows = current.rows;
	int cols = current.cols;

	Dk.create(rows, cols, CV_8SC1);

	schar *pC, *pP;
	    for(int  i = 0; i < rows; ++i)
			{
				pC = current.ptr<schar>(i);
				pP = previous.ptr<schar>(i);
				for (int j = 0; j < cols; ++j)
					{
					schar change = pC[j] - pP[j];
					if(change == 0)
						Dk.at<schar>(i,j) = 0;
					if(change > 0)
						Dk.at<uchar>(i,j) = -1;
					if(change < 0)
						Dk.at<uchar>(i,j) = 1;
					//nesse último caso o pixel está escurecendo
					}
			}

	    return Dk;
}

Mat getIntegralMatrix(Mat mPrevious, Mat Dk)
	{
	Mat m;
	if(Dk.empty())
		{
			cout << "getIntegralMatrix: Dk não existe!" <<endl;
			return m;
		}
	int rows = Dk.rows;
	int cols = Dk.cols;
	m = Mat::zeros(rows,cols, CV_8UC1);

	if(mPrevious.empty())
		{
			cout << "getIntegralMatrix: mPrevious não existe!" <<endl;
			return m;
		}


	m.create(rows, cols, CV_8UC1);
	int aux;
    for(int  i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				aux = (int)Dk.at<schar>(i,j) + (int)mPrevious.at<uchar>(i,j);
				if(aux <= 0)
					m.at<uchar>(i,j) = 0;
				if(aux >= 1)
					m.at<uchar>(i,j) = 1;
			}
    return m;
	}

//------------------------------------------------------------------
//--------------------ALGORITMO DE STAUDER--------------------------
//------------------------------------------------------------------
/*
	//EXEMPLO DE UTILIZAÇÃO
			Dk = getTrinarySignal(current, previous);
			m.copyTo(mPrevious);
			m = getIntegralMatrix(mPrevious, Dk);
			//m marca com 1 o pixels que estão escurecendo
			Mat mShow;
			mShow = m*255;
			mShow = 255*Mat::ones(mShow.rows, mShow.cols, CV_8UC1) - mShow; 
			//inverte o algoritmo; i.e.: pinta de preto(0) o que tiver escurecendo

*/
#endif
