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

void MainWindow::process(){

    VideoCapture *video = videoInput;

    if(!video->isOpened())
        {
        report("video não está pronto!");
        return;
        }
    *video >> currentFrame;

    Mat img(currentFrame);

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
        report("webcam 0 nao pode ser aberta");

}

void MainWindow::report(const string text){
    ui->logText->append(QString(text.c_str()));
}
