
#include "widget.h"
#include "ui_widget.h"

void Widget::process()
{

    VideoCapture *video = videoInput;

    if(!video->isOpened())
        {
        reportBad("video não está pronto!");
        numberOfFailure++;
        if(numberOfFailure > 10){
            reportBad("Numero de falhas excedido! \n O programa sera pausado");
            clock->stop();
            }
        return;
        }
    *video >> currentFrame;

    if(currentFrame.empty())
        {
        report("frame nao pode ser capturado!");
        pauseVideo();
        return;
        }

    Cv2QtImage::setLabelImage(ui->InputImg, currentFrame);

    Mat frame;
    Mat outputFrame(currentFrame.rows,
                    currentFrame.cols,
                    CV_8UC3);
    currentFrame.copyTo(frame);

    //------------------------------------------------
    //-----------BORRANDO IMAGEM----------------------
    //------------------------------------------------

    if(CONTROL_FILTER_GAUSSIAN){
        medianBlur ( frame, frame, SizeGaussFilter);
        }

    //------------------------------------------------
    //-----------DETECÇÃO DE OBJETOS POR COR----------
    //------------------------------------------------

    if(!targets.empty())
        {
        frame.copyTo(outputFrame);

        //acha centro dos objetos
        vector<Point> centers =
            this->findTargets(frame);
        vector<Point> kalmanCenters = this->findKalmanCenters(centers);

        drawDetectionResult(outputFrame, centers);
        drawKalmanResult(outputFrame, kalmanCenters);


        }//end if(!targents.empty())

}

