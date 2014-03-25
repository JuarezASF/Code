#ifndef OBJECTTODETECT_H
#define OBJECTTODETECT_H


//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/video/tracking.hpp>

using namespace std;
using namespace cv;


class ObjectToDetect
{
public:
    ObjectToDetect(vector<Scalar> &(range), Scalar &color,
                   Point &initialPosition);
    ~ObjectToDetect();

    vector<Scalar> colorRange;
    Scalar colorPaint;
    KalmanFilter *KF;
    unsigned int name;


private:
    static unsigned int getId();
    void initKalmanFilter(Point &initialPosition);

};

#endif // OBJECTTODETECT_H
