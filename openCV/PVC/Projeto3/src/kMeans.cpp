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

void myK_Means(Mat &frame, vector<Point2f> &P,vector<Point2f> &V){



	if(P.empty() || V.empty())
		return;

	Mat data((int)P.size(), 4, CV_32FC1);

	int clusterCount = 10;
	//numero de carros a procurar. 10 é um bom número?

    int sampleCount = P.size();
    //numero de amostras a utilizar

    Mat labels;
    //aqui serão salvos os resutlados

    clusterCount = MIN(clusterCount, sampleCount);
	//se tivermos menos pontos do que clusters, o n de clusters é reduzido
    Mat centers(clusterCount, 2, CV_32FC2);

    for(int i = 0; i < (int)P.size(); i++)
    {
            data.at<float>(i,0) = P[i].x;
            data.at<float>(i,1) = P[i].y;
            data.at<float>(i,2) = V[i].x;
            data.at<float>(i,3) = V[i].y;
    }


    kmeans(data, clusterCount, labels,
                   TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0),
                   1, KMEANS_PP_CENTERS, centers);


    for(int i = 0; i < centers.rows; i++ )
    {
        Point ipt = centers.at<Point2f>(i);
        circle( frame, ipt, 10, BLACK, 3, 8, 0 );
    }

}



