#ifndef COLORSENSORCONFIG_H
#define COLORSENSORCONFIG_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>
#include <QRubberBand>
#include <QRect>
#include <QMessageBox>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>

//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//MY LIBS
#include "cv2qtimage/cv2qtimage.h"
#include "Sensors/InterfaceSensor.h"
#include "Sensors/ColorSensor/ColorSensor.h"
#include "Draw/Draw.h"
#include "Sensors/TemplateMatchSensor/TemplateMatchSensor.h"
namespace Ui {
class ColorSensorConfig;
}

extern bool _CONTROL_SensorSetted;


class ColorSensorConfig : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSensorConfig(Mat &inputImg, InterfaceSensor *sensor,
                               QWidget *parent = 0);
    ~ColorSensorConfig();

private:
    Ui::ColorSensorConfig *ui;
    void errorMsg(string msg);
    void updateColorTrackBars();
    int     minCorHSV[3], maxCorHSV[3];
    cv::Mat inputImg;
    cv::Mat outputImg;
    ColorSensor *mySensor;

public:
    void setCurrentImg(Mat &inputImg);
    void setSensor(InterfaceSensor *sensor);

private:
    void setOutputImg(Mat &frame);


private slots:

    void on_ColorMinChannelSlider_valueChanged(int value);
    void on_ColorMaxChannelSlider_valueChanged(int value);

    void on_ColorMinChannelOption_currentIndexChanged(int index);
    void on_ColorMaxChannelOption_currentIndexChanged(int index);

    void on_DefinedColorOption_currentIndexChanged(int index);
    void on_okButtom_clicked();
    void findThresholdImg();


signals:
    void rangeChanged();
};

#endif // COLORSENSORCONFIG_H
