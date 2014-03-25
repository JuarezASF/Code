
#include "widget.h"
#include "ui_widget.h"

void Widget::process()
{

    VideoCapture *video = videoInput;

    if(!video->isOpened())
        {
        reportBad("video não está pronto!");
        return;
        }
    *video >> currentFrame;

    Cv2QtImage::setLabelImage(ui->InputImg, currentFrame);



}

