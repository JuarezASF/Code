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
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>
#include <QRubberBand>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>

//MY LIBS
#include "cv2qtimage/cv2qtimage.h"
#include "Sensors/InterfaceSensor.h"
#include "Sensors/ColorSensor/ColorSensor.h"
#include "Draw/Draw.h"
#include "Sensors/TemplateMatchSensor/TemplateMatchSensor.h"

//MYQLIBS
#include "Sensors/TemplateSensorConfigWindow/TemplateSensorConfigWindows.h"


using namespace cv;

namespace Ui {
class MainWindow;
}

namespace SensorType{
    enum{
        NONE,
        ColorSensor,
        MatchingSensor
    };
}

extern unsigned char _CONTROL_SensorType;
extern bool _CONTROL_SensorSetted;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private://membros
    cv::VideoCapture *videoInput;
    cv::Mat currentFrame;
    cv::Mat RGB_Output;
    InterfaceSensor *mySensor;
    vector<Mat> masks;

    TemplateSensorConfigWindows *templateConfigWindow;

private:
    Ui::MainWindow *ui;
    QTimer *clock;
    void initVideo();
    void report(const string text);
    void reportGood(const string text);
    void reportBad(const string text);
    void setWindow1(Mat &img);
    void setSensorType(unsigned char type);
    void drawDetectedObject(Point &center);

protected slots:
        void process();
        void on_SensorTypeSetButton_clicked();

private slots:
        void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
