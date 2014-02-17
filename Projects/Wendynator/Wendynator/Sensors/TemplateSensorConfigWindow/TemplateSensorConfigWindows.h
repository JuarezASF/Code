#ifndef TEMPLATESENSORCONFIGWINDOWS_H
#define TEMPLATESENSORCONFIGWINDOWS_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>
#include <QRubberBand>
#include <QRect>

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

namespace Ui {
class TemplateSensorConfigWindows;
}

class TemplateSensorConfigWindows : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateSensorConfigWindows(Mat frame, InterfaceSensor *sensor,
                                         QWidget *parent = 0);
    ~TemplateSensorConfigWindows();

private:
    QPoint origin;
    QRubberBand *rubberBand;
    cv::Mat currentFrame;


private:
    Ui::TemplateSensorConfigWindows *ui;

private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void on_okButtom_clicked();
};

#endif // TEMPLATESENSORCONFIGWINDOWS_H
