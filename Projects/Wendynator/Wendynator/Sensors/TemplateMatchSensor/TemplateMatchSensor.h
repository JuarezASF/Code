#ifndef TEMPLATEMATCHSENSOR_H
#define TEMPLATEMATCHSENSOR_H


//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

//CLIBS
#include <iostream>
#include <stdio.h>

//MYLIBS
#include "InterfaceSensor.h"

using namespace cv;
using namespace std;

namespace MatchSensorTechnique{
  enum{
        SQDIFF,
        SQDIFF_NORMED,
        TM_CCORR,
        TM_CCORR_NORMED,
        TM_COEFF,
        TM_COEFF_NORMED
        };
       }


class TemplateMatchSensor : public InterfaceSensor
{
private:
    Mat templateMat, matchingMat;
    bool initialized;
    Point position;
    int     matchingAlgorithm;

public:
    TemplateMatchSensor();
    Point currentPosition(Mat frame);
    Point currentPosition();
    void setTemplateMat(Mat &tpl);
    void setMatchAlgorithm(int type);
};

#endif // TEMPLATEMATCHSENSOR_H
