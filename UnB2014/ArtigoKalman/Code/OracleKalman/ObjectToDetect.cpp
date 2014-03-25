#include "ObjectToDetect.h"

ObjectToDetect::ObjectToDetect(vector<Scalar> &range, Scalar &color, Point &initialPosition)
    : colorRange(range), colorPaint(color)
{
    name = getId();
    initKalmanFilter(initialPosition);
}

ObjectToDetect::~ObjectToDetect(){
    delete KF;
    colorRange.clear();
}

unsigned int ObjectToDetect::getId(){
    static unsigned int lastId = 0;
    return lastId++;
}

void ObjectToDetect::initKalmanFilter(Point &initialPosition){
    KF   = new KalmanFilter(6, 2, 0);
    //kalman filter com 4 variáveis de estado e 2 de medida

        //condições iniciais de posição
        KF->statePre.at<float>(0) = initialPosition.x;
        KF->statePre.at<float>(1) = initialPosition.y;
        //condições iniciais de velocidade
        KF->statePre.at<float>(2) = 0;
        KF->statePre.at<float>(3) = 0;
        //condições iniciais de aceleração
        KF->statePre.at<float>(4) = 0;
        KF->statePre.at<float>(5) = 0;

        KF->transitionMatrix =
            *(
                Mat_<float>(6, 6) <</*                Sx        Sy        Vx        Vy        Ax                Ay        */
                                    /*Sx*/         1,        0,        1,        0,        0.5,        0,
                                    /*Sy*/         0,        1,        0,        1,        0,                0.5,
                                    /*Vx*/         0,        0,        1,        0,        1,                0,
                                    /*Vy*/         0,        0,        0,        1,        0,                1,
                                    /*Ax*/         0,        0,        0,        0,        1,                0,
                                    /*Ay*/         0,        0,        0,        0,        0,                1
                            );
        KF->measurementMatrix =
                *(
                Mat_<float>(2,6) <<
                            1, 0, 1, 0, 0.5, 0,
                            0, 1, 0, 1, 0, 0.5
                    );

        //erro no processo de medida??
        setIdentity(KF->processNoiseCov, Scalar::all(1e-4));

        //erro nas pedidas?
        setIdentity(KF->measurementNoiseCov, Scalar::all(1e-1));

        //erro a posteriori?
        setIdentity(KF->errorCovPost, Scalar::all(.1));

    }

