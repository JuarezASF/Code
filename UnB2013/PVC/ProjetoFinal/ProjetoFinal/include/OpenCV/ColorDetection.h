#ifndef COLORDETECTION_H
#define COLORDETECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cassert>

using namespace cv;
using namespace std;

class ColorDetection
{
private:
    ColorDetection();

public:
    static Mat GetThresholdedImage (Mat &imgHSV,
                                    Scalar colorMin,
                                    Scalar colorMax);

};

#endif // COLORDETECTION_H
