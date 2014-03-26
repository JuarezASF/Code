#ifndef WIDGET_H
#define WIDGET_H



//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

//QT LIBS
#include <QWidget>
#include <QTimer>
#include <QString>
#include <QMouseEvent>
#include <QTransform>
#include <QLabel>
#include <QRubberBand>
#include <QMessageBox>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/background_segm.hpp>
#include <opencv2/video/tracking.hpp>

//MY LIBS
#include "cv2qtimage.h"
#include "Draw.h"
#include "ColorSensor.h"
#include "ColorDetection.h"
#include "ObjectToDetect.h"
#include "QString2String.h"
#include "Filtros.h"

extern bool CONTROL_FILTER_GAUSSIAN;
extern bool CONTROL_SEE_FUTURE;
extern bool CONTROL_SEE_PAST;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private://membros
    cv::VideoCapture *videoInput;
    cv::Mat currentFrame;

    //controla o numero de falhas ao acessar camera
    int numberOfFailure;

    //controla o tempo de leitura da camera
    QTimer *clock;

    //controla raio com que objetos sao desenhados
    float Raio;


private:
    //inicializacao de video
    bool openVideo(int n);
    void initVideo();
    void pauseVideo();

    //acesso ao log text
    void report(const string text);
    void reportGood(const string text);
    void reportBad(const string text);

    //colors trackbars
    void errorMsg(string msg);
    void updateColorTrackBars();
    int     minCorHSV[3], maxCorHSV[3];

    //tracking
    void addColorToTracking(vector<Scalar> &range);
    vector<ObjectToDetect*> targets;
    vector<Point> objectsCenter;
    vector<bool> detectionSucess;
    vector<Point> findTargets(Mat &RGB_Input);
    vector<Point> findKalmanCenters(vector<Point> dataInput);

    //desenhando resultados
    void drawDetectionResult(Mat &outputFrame, vector<Point> &centers);
    void drawKalmanResult(Mat &outputFrame, vector<Point>    &kalmanCenters);



    //borrar imagem
    int SizeGaussFilter;

signals:
    //controla alteracoes nas trackbats de cores
    void rangeChanged();

protected slots:
    //esse e o loop principal do programa
    void process();

    //proura a imagem de threshold toda vez que altera-se a cor definida
    void findThresholdImg();

    void on_ColorMinChannelSlider_valueChanged(int value);
    void on_ColorMaxChannelSlider_valueChanged(int value);
    void on_ColorMinChannelOption_currentIndexChanged(int index);
    void on_ColorMaxChannelOption_currentIndexChanged(int index);
    void on_DefinedColorOption_currentIndexChanged(int index);
    void on_addTotrackingButtom_clicked();
    void on_trackedColorsList_currentIndexChanged(int index);
    void on_deleteButtom_clicked();


private slots:
    void on_BorrarButtom_clicked();
    void on_SizeOfGaussian_currentIndexChanged(int index);
    void on_futureButtom_stateChanged(int arg1);
    void on_pastButtom_stateChanged(int arg1);
};

#endif // WIDGET_H
