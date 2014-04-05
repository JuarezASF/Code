#ifndef JASF_H
#define JASF_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>

#include <exception>
#include <iostream>
#include <sstream>
#include <cassert>

using namespace cv;
using namespace std;

class JASF
{
public:

     static VideoCapture initVideo();
};

#endif // JASF_H
