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
                frame.copyTo(outputFrame);
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
                if(CONTROL_MODE_RUN)
                    {
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
                    vector<Scalar> colorsToPaintKalman;
                    if(CONTROL_KALMAN)
                    {
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

                            Mat estimated;
                            Mat prediction = KF->predict();
                            if(sucesso[i] == true)
                                {
                                estimated = KF->correct(measurement);
                                }
                            else{
                                Mat_<float> predictedMeasurement(2,1);
                                predictedMeasurement(0) = prediction.at<float>(0);
                                predictedMeasurement(1) = prediction.at<float>(1);
                                estimated = KF->correct(predictedMeasurement);
                                KF->errorCovPre.copyTo(KF->errorCovPost);
                                }
                            Point statePt(estimated.at<float>(0),estimated.at<float>(1));

                            kalmanCenters[i] = statePt;

                        }

                        //DRAWING KALMAN'S CENTERS
                        vector<Vec3f> kalmanCircles;
                        float radiusKalmanCircles = Raio;
                        for(unsigned int i = 0; i < kalmanCenters.size(); i++){
                                Vec3f currentCircle(kalmanCenters[i].x, kalmanCenters[i].y,
                                      radiusKalmanCircles);
                                kalmanCircles.push_back(currentCircle);

                                Scalar currentColor;
                                if(i == 0)
                                    currentColor = Scalar (0,255,0) + colorsToPaint[i];
                                else
                                    currentColor = Scalar (0,0,255) + colorsToPaint[i];
                                colorsToPaintKalman.push_back(currentColor);

                            }
                        Draw::Circles(outputFrame, kalmanCircles, colorsToPaint);
                    }

                        float crossSize = 10;
                        Draw::Crosses(outputFrame, centers, colorsToPaint, crossSize, sucesso);
                        //VISÃO DO FUTURO

                        if(futureMode == true && CONTROL_KALMAN == true){
                        int futureSize = 50;
                        for(int i = 0; i < 3; i++)
                            {
                                future[i].clear();
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
                        KalmanFilter DelfusOracle = myMath::copyKF(*KF);

                        for(int j = 0; j < futureSize; j++)
                            //CALCULA PONTOS DO FUTURO
                            {
                            Mat prediction = DelfusOracle.predict();
                            Point predictPt(prediction.at<float>(0),prediction.at<float>(1));
                            future[i].push_back(predictPt);

                            Mat_<float> predictedMeasurement(2,1);
                            predictedMeasurement(0) = prediction.at<float>(0);
                            predictedMeasurement(1) = prediction.at<float>(1);
                            DelfusOracle.correct(predictedMeasurement);
                            DelfusOracle.errorCovPre.copyTo(DelfusOracle.errorCovPost);

                            }

                        //DEZENHA PONTOS DO FUTURO
                        vector<Vec3f> kalmanFutureCircles;
                        vector<Scalar> ColorsToPaintFuture;
                        for(unsigned int n = 0; n < future[i].size(); n++){
                                int KalmanFutureRaio = 2;
                                Vec3f currentCircle(future[i][n].x, future[i][n].y,
                                      KalmanFutureRaio);
                                kalmanFutureCircles.push_back(currentCircle);

                                Scalar currentColor;
                                    currentColor = colorsToPaint[i];
                                ColorsToPaintFuture.push_back(currentColor);
                            }
                            Draw::Circles(outputFrame, kalmanFutureCircles, ColorsToPaintFuture);

                        }//end for each color

                        for(unsigned int n = futureSize - 15; n < futureSize; n++){
                                for(int i = 0; i < 3; i++)
                                    for(int j = 3; j > i; j--)
                                        {
                                            float distance =
                                                    pow(future[i][n].x - future[j][n].x, 2) +
                                                    pow(future[i][n].y - future[j][n].y, 2);
                                            distance = sqrt(distance);

                                            float sumRadius = 2*Raio;

                                            if(distance < sumRadius)
                                                {
                                                    float xColision =
                                                            (future[i][n].x + future[j][n].x)*0.5;
                                                    float yColision =
                                                            (future[i][n].y + future[j][n].y)*0.5;

                                                    Point colisionPoint(xColision, yColision);

                                                    Scalar xColor(0, 0, 0);

                                                    int xSize = 10;
                                                    Draw::Cross(outputFrame, colisionPoint, xColor, xSize);

                                                }

                                        }

                            }

                        }//end if futuro

                        //VISÃO DO PASSADO
                        if(pastMode == true)
                        {
                                //if(pastHistory[0].size() > 100)
                                  //  ClearPast();

                                bool AddToPast = true;
                                for(int i = 0; i < 3; i++)
                                    {
                                        if(sucesso[i] == false){
                                            AddToPast = false;
                                         }
                                    }

                                if(AddToPast == true)
                                 {
                                    for(int i = 0; i < 3; i++)
                                       {
                                            pastHistory[i].push_back(centers[i]);
                                            if(CONTROL_KALMAN)
                                                kalmanHistory[i].push_back(kalmanCenters[i]);
                                        }
                                    }


                                for(unsigned int n = 0; n < 3; n++)
                                    if(sucesso[n] == true && pastHistory[n].size() > 5)
                                        for (unsigned int i = 0; i < pastHistory[n].size()-1; i++)
                                           {
                                                Draw::Line(outputFrame, pastHistory[n][i], pastHistory[n][i+1],
                                                colorsToPaint[n]);
                                                if(CONTROL_KALMAN)
                                                Draw::Line(outputFrame, kalmanHistory[n][i], kalmanHistory[n][i+1],
                                                    colorsToPaintKalman[n], 2);
                                            }
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
