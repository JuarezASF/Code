#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//QT LIBS
#include <QMainWindow>
#include <QTimer>
#include <QString>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>

//MY LIBS
#include "cv2qtimage.h"
#include "InterfaceSensor.h"
#include "ColorSensor.h"
#include "Draw.h"


using namespace cv;

namespace Ui {
class MainWindow;
}

namespace SensorType{
    enum{
        ColorSensor
    };
}

extern unsigned char _CONTOTROL_SensorType;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private://membros
    cv::VideoCapture *videoInput;
    cv::Mat currentFrame;
    InterfaceSensor *mySensor;

private:
    Ui::MainWindow *ui;
    QTimer *clock;
    void initVideo();
    void report(const string text);
    void reportGood(const string text);
    void reportBad(const string text);
    void setWindow1(Mat &img);
    void setSensorType(unsigned char type);

private slots:
        void process();
};

#endif // MAINWINDOW_H
