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
                if(CONTROL_MODE_CALIBRATION){
                    Mat frameHSV;
                    cvtColor(frame, frameHSV, CV_BGR2HSV);

                    outputFrame = ColorDetection::GetThresholdedImage
                                  (frameHSV,minCorHSV, maxCorHSV);

                    bool sucesso;

                    Point targetDetected = ColorDetection::FindCenter(outputFrame,
                                                                      ColorDetectionThreshold,
                                                                      sucesso);

                    if(sucesso)
                        Draw::Cross(currentFrame,targetDetected, Scalar(255, 0, 0), 10);

                    }
                if(CONTROL_MODE_RUN){
                        //as cores para pintar e a serem trackeadas
                        //estão definidas na função setColor (ou algo assim)
                        //é uma função da interface

                        vector<bool> sucesso;
                        sucesso.resize(3, false);
                        vector<Point> centers =
                            this->DetectColoredObjects(frame,rangesToDetect, sucesso);

                        frame.copyTo(outputFrame);

                        float crossSize = 10;
                        Draw::Crosses(outputFrame, centers, colorsToPaint, crossSize, sucesso);

                        bool AddToPast = true;
                        for(int i = 0; i < 3; i++)
                            {
                                if(sucesso[i] == false)
                                    AddToPast = false;
                             }

                        if(AddToPast == true)
                         {
                            for(int i = 0; i < 3; i++)
                               pastHistory[i].push_back(centers[i]);
                         }

                        //for(int i = 0; i < 3; i++)
                          //  pastHistory[i].push_back(centers[i]);

                        if(pastMode == true)
                        {
                                for(unsigned int n = 0; n < 3; n++)
                                    if(sucesso[n] == true && pastHistory[n].size() > 5)
                                        for (unsigned int i = 0; i < pastHistory[n].size()-1; i++)
                                            Draw::dashedLine(outputFrame, pastHistory[n][i], pastHistory[n][i+1],
                                                colorsToPaint[n]);
                        }
                    }

            }

        //------------------------------------------------
        //-----------SAÍDA FINAL--------------------------
        //------------------------------------------------

        //show Qimage using QLabel
        setInputImg(currentFrame);
        setOutputImg(outputFrame);
        }
}
