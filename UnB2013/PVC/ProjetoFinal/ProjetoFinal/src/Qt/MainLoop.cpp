#include "UserInterface.h"
#include "ui_UserInterface.h"
//--------------------------------------------------------
//---------------PROCESSAMENTO----------------------------
//--------------------------------------------------------

void ProjetoFinal::process()
{

    if(this->run == true)
        {
        //------------------------------------------------
        //-----------ABRINDO IMAGEM-----------------------
        //------------------------------------------------

        if(!video->isOpened())
            {
            report("video não está pronto!");
            return;
            }
        *video >> currentFrame;

        if(currentFrame.empty())
            {
            report("frame nao pode ser capturado!");
            pauseVideo();
            return;
            }
        Mat frame;
        Mat outputFrame(currentFrame.rows,
                        currentFrame.cols,
                        CV_8UC3);



        currentFrame.copyTo(frame);

        //------------------------------------------------
        //-----------BORRANDO IMAGEM----------------------
        //------------------------------------------------

        if(CONTROL_FILTER_GAUSSIAN){
            medianBlur ( frame, frame, SizeGaussFilter); // <==== FILTRANDO
            auxiliarWindow->setWindow(frame, 1);
            }
        //------------------------------------------------
        //-----------BACKGROUND OPERATIONS----------------
        //------------------------------------------------
        if(CONTROL_BGSub)
            {
            Mat backG, foreG, contornoImg;
            std::vector<std::vector<cv::Point> > contours;
            this->uptdateBG();
            bg->operator ()(frame,foreG);
            bg->getBackgroundImage(backG);
            cv::findContours(foreG,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
            currentFrame.copyTo(contornoImg);
            cv::drawContours(contornoImg,contours,-1,cv::Scalar(0,0,255),2);

            auxiliarWindow->setWindow(backG, 2);
            auxiliarWindow->setWindow(foreG, 3);
            auxiliarWindow->setWindow(contornoImg, 4);
            }

        //------------------------------------------------
        //-----------DETECÇÃO DE OBJETOS POR COR----------
        //------------------------------------------------
        if(CONTROL_COLORDETECTION)
            {
              Mat frameHSV;
              cvtColor(frame, frameHSV, CV_BGR2HSV);

             outputFrame = ColorDetection::GetThresholdedImage
                        (frameHSV,minCorHSV, maxCorHSV);

             Point targetDetected = ColorDetection::FindCenter(outputFrame);

             Draw::Cross(currentFrame,targetDetected, Scalar(255, 0, 0), 10);

            }

        //------------------------------------------------
        //-----------SAÍDA FINAL--------------------------
        //------------------------------------------------

        //show Qimage using QLabel
        setInputImg(currentFrame);
        setOutputImg(outputFrame);
        }
}
