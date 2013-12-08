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

                        //MEDIDA DA DETECÇÃO DE MOVIMENTO
                        vector<bool> sucesso;
                        sucesso.resize(3, false);
                        vector<Point> centers =
                            this->DetectColoredObjects(frame,rangesToDetect, sucesso);

                //FILTRAGEM COM KALMAN

                vector<Point> kalmanCenters;
                kalmanCenters.resize(centers.size());
                for(int i = 0; i < 3; i++)
                    {
                        KalmanFilter *KF;
                        switch(i){//determina qual KF processar
                            case 0:
                                KF = redKF;
                                break;
                            case 1:
                                KF = greenKF;
                                break;
                            case 2:
                                KF = blueKF;
                                break;
                            default:
                                reportBad("Opção Inválida ao inicial KF's");
                                break;
                            }
                        Mat_<float> measurement(2,1);
                        measurement(0) = centers[i].x;
                        measurement(1) = centers[i].y;

                        KF->predict();
                        //corrige com o novo ponto medido

                        Mat estimated = KF->correct(measurement);
                        Point statePt(estimated.at<float>(0),estimated.at<float>(1));

                        kalmanCenters[i] = statePt;

                        }
                        frame.copyTo(outputFrame);

                        float crossSize = 10;
                        Draw::Crosses(outputFrame, centers, colorsToPaint, crossSize, sucesso);
                        //VISÃO DO FUTURO

                        //VISÃO DO PASSADO
                        if(pastMode == true)
                        {
                                if(pastHistory[0].size() > 100)
                                    ClearPast();

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
