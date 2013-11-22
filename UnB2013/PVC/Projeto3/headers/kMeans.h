/*
 * kMeans.h
 *
 *  Created on: 18/11/2013
 *      Author: juarez408
 */

#ifndef KMEANS_H_
#define KMEANS_H_

#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <ctype.h>
using namespace cv;
using namespace std;

void myK_Means(Mat &frame, vector<vector<Point2f> > &dataPoints,
		int nObjects);



#endif /* KMEANS_H_ */
