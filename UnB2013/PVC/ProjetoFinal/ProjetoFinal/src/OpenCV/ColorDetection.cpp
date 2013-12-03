#include "include/OpenCV/ColorDetection.h"

ColorDetection::ColorDetection()
{
}

//This function threshold the HSV image and create a binary image
Mat ColorDetection::GetThresholdedImage(Mat &imgHSV,
                                               Scalar colorMin,
                                               Scalar colorMax)
{
//       assert(colorMin.depth == 3 && colorMax.depth == 3);
       Mat imgThresh(imgHSV.rows, imgHSV.cols, CV_8U);
       inRange(imgHSV, colorMin, colorMax, imgThresh);

       return imgThresh;
}
