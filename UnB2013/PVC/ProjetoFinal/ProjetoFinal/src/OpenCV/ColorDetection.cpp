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

Point ColorDetection::FindCenter(Mat &imgBin, int threshold, bool &sucesso)
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

        sucesso = (myMoment.m00 > threshold)? true : false;

        return result;
    }

vector<Point> ColorDetection::DetectColoredObjects(Mat &RGB_Input,
                vector<vector<Scalar> > rangesToDetect, int colorThreshold,
                                                   vector<bool> &sucesso)
    {
        vector<Point> centers;
        Mat HSV_Input;
        cvtColor(RGB_Input, HSV_Input, CV_BGR2HSV);

        for(unsigned int i = 0; i < rangesToDetect.size(); i++){
                Scalar colorMin = rangesToDetect[i][0];
                Scalar colorMax = rangesToDetect[i][1];

                Mat BinaryImg =
                        ColorDetection::GetThresholdedImage(
                            HSV_Input, colorMin,colorMax);

                bool currentSucess;

                Point currentCenter =
                        ColorDetection::FindCenter(BinaryImg, colorThreshold,
                                                   currentSucess);
                sucesso[i] = currentSucess;

                centers.push_back(currentCenter);
            }

        return centers;

    }

