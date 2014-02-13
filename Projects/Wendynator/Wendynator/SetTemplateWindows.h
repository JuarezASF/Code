#ifndef SETTEMPLATEWINDOWS_H
#define SETTEMPLATEWINDOWS_H
#include <QApplication>
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>

//OPENCV LIBS
#include <opencv2/core/core.hpp>

using namespace cv;

extern bool _CONTROL_SET_MATCHING_TEMPLATE_MODE;
extern bool _CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE;
extern bool _CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE;

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



            }
            if(_CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE)
            {}

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


#endif // SETTEMPLATEWINDOWS_H
