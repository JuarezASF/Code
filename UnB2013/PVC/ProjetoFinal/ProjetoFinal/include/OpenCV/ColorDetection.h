#ifndef COLORDETECTION_H
#define COLORDETECTION_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
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

    static Point FindCenter(Mat &imgBin, int threshold, bool &sucesso);

    static vector<Point> DetectColoredObjects(Mat &rgbImg,
                    vector<vector<Scalar> > rangesTodetect,
                        int colorThreshold,vector<bool> &sucesso);

};

#endif // COLORDETECTION_H
