/*
 * kMeans.cpp
 *
 *  Created on: 18/11/2013
 *      Author: juarez408
double kmeans(const Mat& samples,
              int clusterCount,
              Mat& labels,
              TermCriteria termcrit,
              int attempts,
              int flags,
              Mat* centers)

samples: (input) The actual data points that you need to cluster. It should contain exactly one point per row. That is, if you have 50 points in a 2D plane, then you should have a matrix with 50 rows and 2 columns.
clusterCount: (input) The number of clusters in the data points.
labels: (output) Returns the cluster each point belongs to. It can also be used to indicate the initial guess for each point.
termcrit: (input) This is an iterative algorithm. So you need to specify the termination criteria (number of iterations & desired accuracy)
attempts: (input) The number of times the algorithm is run with different center placements
flags: (input) Possible values include:
KMEANS_RANDOM_CENTER: Centers are generated randomly
KMEANS_PP_CENTER: Uses the kmeans++ center initialization
KMEANS_USE_INITIAL_LABELS: The first iteration uses the supplied labels to calculate centers. Later iterations use random or semi-random centers (use the above two flags for that).
centers: (output) This matrix holds the center of each cluster.

-Os ponstos a serem clusterizados são 4d: duas dimensões para o espaco e 2 para
a velocidade
-o número de clusters é um problema, já que o número de carros varia na imagem


 */
#include "../headers/kMeans.h"

using namespace cv;
using namespace std;

#define BLACK CV_RGB(0,0,0)
RNG rng(12345);
int colorSize = 13;
Scalar colors[] = {
		Scalar( 0, 0, 0),
		Scalar( 255, 0, 0),
		Scalar( 0, 255, 255),
		Scalar( 255,255, 0),
		Scalar( 255, 0, 255),
		Scalar( 0, 255, 255),
		Scalar( 127, 0, 0),
		Scalar( 0, 127, 0),
		Scalar( 0, 0, 127),
		Scalar( 127, 127, 0),
		Scalar( 127, 0, 127),
		Scalar( 0, 127, 127),
		Scalar( 127, 127, 127)
};

void drawRetang(Mat &frame, vector<vector<Point> > contours){
		vector<vector<Point> > contours_poly( contours.size() );
		vector<Rect> boundRect( contours.size() );

		  for( unsigned int i = 0; i < contours.size(); i++ )
			 {
			  approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
			   boundRect[i] = boundingRect( Mat(contours_poly[i]) );

			 }
		for(unsigned  int i = 0; i< contours.size(); i++ )
			 {
			   Scalar color = colors[i%colorSize];
			   rectangle( frame, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
			 }
}

void drawCirc(Mat &frame, vector<vector<Point> > contours, bool bRadiusOp = false){
		vector<Point2f>center( contours.size() );
		vector<float>radius( contours.size() );
		vector<vector<Point> > contours_poly( contours.size() );

		for( unsigned int i = 0; i < contours.size(); i++ )
			 {
				approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
				minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
			}
		int fixedSizeRadius = 5;
		for( unsigned int i = 0; i< contours.size(); i++ )
			 {
			   Scalar color = colors[i%colorSize];
			   if(bRadiusOp)
				   circle( frame, center[i], (int)radius[i], color, 2, 8, 0 );
			   else
				   circle( frame, center[i], fixedSizeRadius, color, 2, 8, 0 );
			 }
}

void myK_Means(Mat &frame, vector<vector<Point2f> > &dataPoints,
		int nObjects){

	if(nObjects == 0)
		return;

	vector<Point2f> P = dataPoints[0];
	vector<Point2f> V = dataPoints[1];

	vector<Point> *groups = new vector<Point>[nObjects];
	vector<vector<Point> > sortedData;

	if(P.empty() || V.empty())
		return;

//	Mat data((int)P.size(), 4, CV_32FC1);
	Mat data((int)P.size(), 2, CV_32FC1);
	int clusterCount = nObjects;
	//numero de carros a procurar.

    int sampleCount = P.size();
    //numero de amostras a utilizar

    Mat labels;
    //aqui serão salvos os resutlados

    clusterCount = MIN(clusterCount, sampleCount);
	//se tivermos menos pontos do que clusters, o n de clusters é reduzido
    Mat centers(clusterCount, 2, CV_32FC2);
/*
    for(int i = 0; i < (int)P.size(); i++)
    {
            data.at<float>(i,0) = P[i].x;
            data.at<float>(i,1) = P[i].y;
            data.at<float>(i,2) = V[i].x;
            data.at<float>(i,3) = V[i].y;
    }
*/
    for(int i = 0; i < (int)P.size(); i++)
      {
              data.at<float>(i,0) = P[i].x;
              data.at<float>(i,1) = P[i].y;

      }

    kmeans(data, clusterCount, labels,
                   TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0),
                   1, KMEANS_PP_CENTERS, centers);


    for(unsigned int i = 0; i < P.size(); i++ )
        {
    		(groups[labels.at<int>(i)]).push_back(Point(P[i].x, P[i].y));
        }

    for(int i = 0; i < nObjects; i++)
    	sortedData.push_back(groups[i]);

    drawRetang(frame, sortedData);
    drawCirc(frame, sortedData);

    delete[] groups;


}



