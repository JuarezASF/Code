#ifndef WIDGET_H
#define WIDGET_H



//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//QT LIBS
#include <QWidget>
#include <QTimer>
#include <QString>
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>
#include <QRubberBand>
#include <QMessageBox>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>

//MY LIBS
#include "cv2qtimage.h"
#include "Draw.h"
#include "ColorSensor.h"
#include "ColorDetection.h"
#include "ObjectToDetect.h"



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private://membros
    cv::VideoCapture *videoInput;
    cv::Mat currentFrame;
    QTimer *clock;





private:
    bool openVideo(int n);
    void initVideo();

    //acesso ao log text
    void report(const string text);
    void reportGood(const string text);
    void reportBad(const string text);

    //colors trackbars
    void errorMsg(string msg);
    void updateColorTrackBars();
    int     minCorHSV[3], maxCorHSV[3];

    //tracking
    void addColorToTracking(vector<Scalar> &range);
    vector<ObjectToDetect*> targets;


protected slots:
        void process();

        void on_ColorMinChannelSlider_valueChanged(int value);
        void on_ColorMaxChannelSlider_valueChanged(int value);

        void on_ColorMinChannelOption_currentIndexChanged(int index);
        void on_ColorMaxChannelOption_currentIndexChanged(int index);

        void on_DefinedColorOption_currentIndexChanged(int index);

        void findThresholdImg();
signals:
    void rangeChanged();

private slots:
    void on_addTotrackingButtom_clicked();
};

#endif // WIDGET_H
