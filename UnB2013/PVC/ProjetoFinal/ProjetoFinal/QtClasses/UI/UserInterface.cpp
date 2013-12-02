#include "UserInterface.h"
#include "ui_UserInterface.h"


//--------------------------------------------------------
//---------------CONTROLE DE INICIALIZAÇÃO----------------
//--------------------------------------------------------

ProjetoFinal::ProjetoFinal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjetoFinal)
{
    ui->setupUi(this);

    //botões de passado e futuro
    connect(ui->pastButtom, SIGNAL(stateChanged(int)), this, SLOT(on_pastButtom_stateChanged(int)));
    connect(ui->futureButtom, SIGNAL(stateChanged(int)), this, SLOT(on_futureButtom_stateChanged(int)));
    pastMode = false;
    futureMode = false;

    //set cursor
    mouseCursor = new QCursor();
    mouseCursor->setShape(Qt::CrossCursor);

    ui->inputImg->setCursor(*mouseCursor);
    ui->inputImg->setMouseTracking(true);


    //timer : define tempo entre leitura de um frame e outro!
    timer = new QTimer(this);
    /*======>*/timer->start(20);
    connect(timer, SIGNAL(timeout()), this, SLOT(process()));

    video = NULL;

    nVideos = 2;
    fileNames = new string[nVideos];
    fileNames[0] = "/home/juarez408/Copy/UnB/2-2013/PVC/Projeto3/data/video.avi";
    fileNames[1] = "/home/juarez408/Copy/UnB/2-2013/PVC/projetoFinal/data/video.avi";

    videoAtual = 0;

    /*init video ===>*/initVideo(fileNames[videoAtual].c_str());

    connect(ui->speedSlider, SIGNAL(sliderMoved(int)), this, SLOT(on_speedSlider_sliderMoved(int)));

    //janela auxiliar
    auxiliarWindow = new secondWindow();
    auxiliarWindow->show();
    initSecondWindow();
}

void ProjetoFinal::initSecondWindow(){
    Mat outputFrame(350, 350, CV_8UC3);

    for( int i = 1; i <=8; i++)
        {
        outputFrame = Scalar::all((255/8.0)*i);
        auxiliarWindow->setWindow(outputFrame, i);
        }
}

ProjetoFinal::~ProjetoFinal()
{
    delete ui;
}

void ProjetoFinal::initVideo(const char *fileName){
    if(video != NULL)
        video->release();
    video = new VideoCapture(fileName);
}

//--------------------------------------------------------
//---------------CONTROLE DE JANELAS----------------------
//--------------------------------------------------------
void ProjetoFinal::setInputImg(const cv::Mat &img){

    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    QPixmap myQpix = QPixmap::fromImage(myQImg);
    myQpix =  myQpix.scaled(ui->inputImg->size(),  Qt::IgnoreAspectRatio);

    ui->inputImg->setPixmap(myQpix);
}

void ProjetoFinal::setOutputImg(const cv::Mat &img){

    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    QPixmap myQpix = QPixmap::fromImage(myQImg);
    myQpix =  myQpix.scaled(ui->inputImg->size(),  Qt::IgnoreAspectRatio);

    ui->outputImg->setPixmap(myQpix);
}

//--------------------------------------------------------
//---------------CONTROLE DE FUNCIONALIDADE---------------
//--------------------------------------------------------
void ProjetoFinal::on_pastButtom_stateChanged(int arg1)
{
    pastMode = ui->pastButtom->isChecked();
}

void ProjetoFinal::on_futureButtom_stateChanged(int arg1)
{
    futureMode = ui->futureButtom->isChecked();
}


QPoint ProjetoFinal::getMousePos(){
    return mouseCursor->pos();
}

//--------------------------------------------------------
//---------------INTERFACE TEXTUAL------------------------
//--------------------------------------------------------

void ProjetoFinal::report(string text)
{
    ui->logText->appendPlainText(QString(text.c_str()));
}

void ProjetoFinal::reportGood(string text)
{
    ui->logText->appendPlainText(QString(text.c_str()));
}

void ProjetoFinal::reportBad(string text)
{
    ui->logText->appendPlainText(QString(text.c_str()));
}

void ProjetoFinal::reportWarning(string text){
    ui->logText->appendPlainText(QString(text.c_str()));
}

//--------------------------------------------------------
//---------------CONTROLE DE VIDEO------------------------
//--------------------------------------------------------

void ProjetoFinal::on_pauseButtom_clicked()
{
    if(this->run == true)
        {
        pauseVideo();
        report("pausando o vídeo");
        }
    else
    {
        runVideo();
        report("running video");
    }
}

void ProjetoFinal::pauseVideo(){
    this->run = false;
    ui->pauseButtom->setText("Resume");

}

void ProjetoFinal::runVideo(){
    this->run = true;
    ui->pauseButtom->setText("Pause");
}

void ProjetoFinal::on_restartButtom_clicked()
{
    video->set(CV_CAP_PROP_POS_AVI_RATIO, 0);
    runVideo();
    report("Reiniciando o vídeo\n");
}

void ProjetoFinal::on_speedSlider_sliderMoved(int position)
{
    report("timer set to " + ToString(position) + "\n");
    timer->start(position);
}


void ProjetoFinal::on_pushButton_clicked()
{
    report("mudando de vídeo");
    videoAtual = (videoAtual + 1)%nVideos;
    initVideo(fileNames[videoAtual].c_str());
}

//--------------------------------------------------------
//---------------PROCESSAMENTO----------------------------
//--------------------------------------------------------

void ProjetoFinal::process()
{
    if(this->run == true)
        {
        *video >> currentFrame;
        Mat outputFrame(currentFrame.rows, currentFrame.cols, CV_8UC3);

        if(currentFrame.empty())
            {
            report("O video chegou ao fim! \n");
            pauseVideo();
            return;
            }
        outputFrame = Scalar::all(0);
        //show Qimage using QLabel
        setInputImg(currentFrame);
        setOutputImg(outputFrame);
        }
}


