#ifndef INTERFACESENSOR_H
#define INTERFACESENSOR_H
//OPENCV LIBS
#include <opencv2/core/core.hpp>

using namespace cv;

class InterfaceSensor{
public:
    Point virtual currentPosition(Mat frame) = 0;
    Point virtual currentPosition() = 0;
};

#endif // INTERFACESENSOR_H
