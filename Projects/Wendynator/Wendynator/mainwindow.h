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
#include "TemplateMatchSensor.h"


using namespace cv;

namespace Ui {
class MainWindow;
}

namespace SensorType{
    enum{
        ColorSensor,
        MatchingSensor
    };
}

extern unsigned char _CONTOTROL_SensorType;
extern bool _CONTROL_SET_MATCHING_TEMPLATE_MODE;
extern bool _CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE;
extern bool _CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE;

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
    cv::Point template_left_bottom, template_right_top;
    vector<Mat> masks;

private:
    Ui::MainWindow *ui;
    QTimer *clock;
    void initVideo();
    void report(const string text);
    void report(QString text);
    void reportGood(const string text);
    void reportBad(const string text);
    void setWindow1(Mat &img);
    void setSensorType(unsigned char type);
    vector<Point> getTemplate();

private slots:
        void process();
        void on_SensorTypeSetButton_clicked();

public:
        class SetTemplateWindow : public QLabel {

        public:
            QPoint &first, &second;

        public:
            SetTemplateWindow(QPoint &Fir, QPoint &Sec, QWidget *parent = 0, Qt::WindowFlags f = 0)
                        : first(Fir), second(Sec), QLabel(parent, f){
                setMouseTracking(true);
                setMinimumSize(480, 400);
            }

            void mouseMoveEvent(QMouseEvent *ev) {
                if(_CONTROL_SET_MATCHING_TEMPLATE_MODE)
                {
                    if(_CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE)
                    {
                    QPoint pos = ev->pos();
                    report(QString("%1, %2").arg(pos.x()).arg(pos.y()));
                    }
                    if(_CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE)
                    {
                        QPoint pos = ev->pos();
                        report((QString("%1, %2").arg(pos.x()).arg(pos.y())));

                    }

                }
               }//end mouseMoveEvent

            void mousePressEvent(QMouseEvent *eventPress){
                if(_CONTROL_SET_MATCHING_TEMPLATE_MODE){
                    if(_CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE)
                    {
                        first = eventPress->pos();
                        _CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE = false;
                        _CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE = true;
                    }
                    if(_CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE)
                    {
                        second = eventPress->pos();
                        _CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE = false;
                        _CONTROL_SET_MATCHING_TEMPLATE_MODE = false;
                    }

                }
            }//end mousePressevent
        };


};

#endif // MAINWINDOW_H
