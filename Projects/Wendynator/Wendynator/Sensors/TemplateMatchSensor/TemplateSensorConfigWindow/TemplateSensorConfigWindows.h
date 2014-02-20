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
#include <QMessageBox>

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

namespace Ui {
class TemplateSensorConfigWindows;
}

extern bool _CONTROL_SensorSetted;

class TemplateSensorConfigWindows : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateSensorConfigWindows(Mat frame, InterfaceSensor *sensor, QMainWindow *pai,
                                         QWidget *parent = 0);
    ~TemplateSensorConfigWindows();

private:
    QPoint origin;
    QMainWindow *father;
    QRubberBand *rubberBand;
    cv::Mat currentFrame;
    cv::Mat ROI;
    QPoint leftBottom, leftTop, rightTop, rightBottom;
    TemplateMatchSensor *mySensor;
public:
    void setCurrentImg(const Mat &Img);

private:
    Ui::TemplateSensorConfigWindows *ui;

private slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void on_okButtom_clicked();
};

#endif // TEMPLATESENSORCONFIGWINDOWS_H
