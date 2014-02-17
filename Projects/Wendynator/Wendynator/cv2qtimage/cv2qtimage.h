#ifndef CV2QTIMAGE_H
#define CV2QTIMAGE_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QLabel>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;



class Cv2QtImage
{
public:
    Cv2QtImage();

public:
    static QImage Mat2QImage(const Mat &img);

    static void setLabelImage(QLabel *target, const Mat &img);
};

#endif // CV2QTIMAGE_H
