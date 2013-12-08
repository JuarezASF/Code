#ifndef FILTROS_H
#define FILTROS_H

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace cv;
using namespace std;


class Filtros
    {
    private:
        Filtros();

    public:
       static void Erosion( Mat src, Mat dst, int size);

       static void Dilation( Mat src, Mat dst, int size);
    };

#endif // FILTROS_H
