#ifndef COLORSENSOR_H
#define COLORSENSOR_H

//OPENCV LIBS
#include <opencv2/core/core.hpp>

//My LIBS
#include "Sensors/InterfaceSensor.h"
#include "Sensors/ColorDetection/ColorDetection.h"


using namespace cv;
using namespace std;

class ColorSensor : public InterfaceSensor
{
    /*  detecta posição do objeto baseado em sua cor característica.
        a técnica consiste em obter uma imagem com os pixels no intervalo desejado
        então calculamos o centro geométrico dessa imagem threshold obtida
        !trabalhamos com hsv!!
    */
private:
    Scalar colorMin, colorMax;
    Point  position;
    bool   initialized;

public:
    ColorSensor();
    Point currentPosition(Mat RGB_Input);
    Point currentPosition();
    void setRange(Scalar setColorMin, Scalar setColorMax);
};

#endif // COLORSENSOR_H
