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

Point ColorDetection::FindCenter(Mat &imgBin)
    /*calcula o centro do objeto com técnicas de momento:
(from OpenCV documentation)
Moments moments(InputArray array, bool binaryImage=false )
Parameters:
array – Raster image (
binaryImage – If it is true, all non-zero image pixels are treated as
1’s.

The function computes moments, up to the 3rd order, of a vector shape
or a rasterized shape. The results are returned in the structure
Moments

usage(from AiShack):
And then using the moments structure, you calculate the two first
order moments (moment10 and moment01) and the zeroth order moment
(area).

Dividing moment10 by area gives the X coordinate of the yellow ball,
 and similarly, dividing moment01 by area gives the Y coordinate.


*/
    {
        bool bBinImgMode = true;
        Moments myMoment = moments(imgBin, bBinImgMode);

        int iPosX = myMoment.m10/myMoment.m00;
        int iPosY = myMoment.m01/myMoment.m00;

        Point result(iPosX, iPosY);

        return result;

    }
