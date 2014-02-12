#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//C++ LIBS
#include <string>
#include <iostream>

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


using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private://membros
    cv::VideoCapture *videoInput;
    cv::Mat currentFrame;

private:
    Ui::MainWindow *ui;
    QTimer *clock;
    void initVideo();
    void report(const string text);

private slots:
        void process();
};

#endif // MAINWINDOW_H
