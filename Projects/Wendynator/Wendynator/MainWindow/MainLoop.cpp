#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::process()
{

    VideoCapture *video = videoInput;

    if(!video->isOpened())
        {
        reportBad("video não está pronto!");
        return;
        }
    *video >> currentFrame;



    Mat RGB_Input(currentFrame);
    currentFrame.copyTo(RGB_Output);
    if(_CONTROL_SensorSetted)
        {
        try{
            Point center = mySensor->currentPosition(RGB_Input);
            drawDetectedObject(center);
            }
        catch(const char *strException){
            string errorMsg(strException);
            reportBad(errorMsg);
            }
        }
    Draw::addAll(RGB_Output, masks);
    masks.clear();
    setWindow1(RGB_Output);
}

void MainWindow::setWindow1(Mat &img){
    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    QPixmap myQpix = QPixmap::fromImage(myQImg);
    myQpix =  myQpix.scaled(ui->InputImg->size(),  Qt::IgnoreAspectRatio);

    ui->InputImg->setPixmap(myQpix);

}
