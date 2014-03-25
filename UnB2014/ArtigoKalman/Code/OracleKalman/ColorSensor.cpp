#include "ColorSensor.h"

ColorSensor::ColorSensor()
{
    initialized = false;
    position = Point(0,0);
    colorMin = Scalar(0,0,0);
    colorMax = Scalar(0,0,0);
}

Point ColorSensor::currentPosition(Mat RGB_Input){

    if(initialized == false)
        throw "Sensor deve ser primeiramente Inicializado!";

    vector<Scalar> rangeToDetect;
    rangeToDetect.push_back(colorMin);
    rangeToDetect.push_back(colorMax);

    int colorThreshold = 50;
    bool sucesso;

    Point detectedCenter = ColorDetection::DetectColoredObject(RGB_Input,
                                rangeToDetect,colorThreshold,sucesso);

    this->position = (sucesso)? detectedCenter:this->position;

    return this->position;
}

Point ColorSensor::currentPosition(){
    return this->position;
}

void ColorSensor::setRange(Scalar setColorMin, Scalar setColorMax){
    for(int i =0; i < colorMin.channels; i++){
        colorMin[i] = setColorMin[i];
        colorMax[i] = setColorMax[i];
    }
    initialized = true;
}


