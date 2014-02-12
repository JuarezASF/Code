#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //SET CLOCK
    this->clock = new QTimer(this);
    connect(this->clock, SIGNAL(timeout()), this, SLOT(process()));

    //SET TEXT EDIT
    //ui->logText->setDisabled(true);
    //read only

    //INITIATE CAMERA
    videoInput = NULL;
    initVideo();

    //START CLOCK (APÓS CÂMERA SER INICIALIZADA)
    this->clock->start(50);
    //lança evento timeout() a cada 500 milisegundos
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::process()
{

    VideoCapture *video = videoInput;

    if(!video->isOpened())
        {
        reportBad("video não está pronto!");
        return;
        }
    *video >> currentFrame;

    setSensorType(SensorType::ColorSensor);

    Mat RGB_Input(currentFrame);
    Mat RGB_Output(currentFrame);

    if(_CONTOTROL_SensorType == SensorType::ColorSensor)
        {
        Scalar colorMin(38,0,0);
        Scalar colorMax(75, 255, 255);
        ((ColorSensor*) mySensor)->setRange(colorMin, colorMax);
        }
    try{
        Point center = mySensor->currentPosition(RGB_Input);
        Draw::Cross(RGB_Output,center, Scalar(255,0,0), 5);
        //string msg = "(" + center.x + ", " + center.y + ")";
        //report(msg)
        }
    catch(const char *strException){
        string errorMsg(strException);
        reportBad(errorMsg);
        }

    setWindow1(RGB_Output);
}

void MainWindow::setWindow1(Mat &img){
    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    QPixmap myQpix = QPixmap::fromImage(myQImg);
    myQpix =  myQpix.scaled(ui->InputImg->size(),  Qt::IgnoreAspectRatio);

    ui->InputImg->setPixmap(myQpix);
}

void MainWindow::initVideo(){
    if(videoInput == NULL)
        videoInput = new VideoCapture(0);
    else
    {
        videoInput->release();
        videoInput->open(0);
    }

    if(!videoInput->isOpened())
        reportBad("webcam 0 nao pode ser aberta");

}

void MainWindow::report(const string text){
    ui->logText->setTextColor(QColor("blue"));
    ui->logText->append(QString(text.c_str()));
}

void MainWindow::reportGood(const string text){
    ui->logText->setTextColor(QColor("green"));
    ui->logText->append(QString(text.c_str()));
}
void MainWindow::reportBad(const string text){
    ui->logText->setTextColor(QColor("red"));
    ui->logText->append(QString(text.c_str()));
}



void MainWindow::setSensorType(unsigned char type){
    switch(type){
    case(SensorType::ColorSensor):
        mySensor = new ColorSensor();
        _CONTOTROL_SensorType = SensorType::ColorSensor;
    break;
    }
}
