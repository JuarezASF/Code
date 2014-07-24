#ifndef MASKOPERATION_H
#define MASKOPERATION_H

#include <algorithm>
#include <iostream>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

class MaskOperation
{
public:
        MaskOperation();

        /***
         Se A(i,j) != cor => C(i,j) = A(i,j)
         Se B(i,j) != cor => C(i,j) = B(i,j)
        */
        static Mat mergeEspecial(Mat &A, Mat &B, Scalar cor);

};

#endif // MASKOPERATION_H
