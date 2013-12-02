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

    nVideos = 3;
    fileNames = new string[nVideos];
    video = NULL;
    bg = NULL;

    fileNames[0] = "../data/video1.avi";
    fileNames[1] = "../data/video2.avi";
    fileNames[2] = "../data/video3.avi";

    ui->videoFileOption->addItem("[0] : WebCam");
    ui->videoFileOption->addItem("[1] : video rodovia");
    ui->videoFileOption->addItem("[2] : video helicoptero");
    ui->videoFileOption->addItem("[3] : video bolinhas");
    connect(ui->videoFileOption,SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_videoFileOption_currentIndexChanged(int)));

    ui->videoFileOption->setCurrentIndex(1);
    videoAtual = 0;
    initVideo(fileNames[videoAtual].c_str());

    connect(ui->speedSlider, SIGNAL(sliderMoved(int)), this, SLOT(on_speedSlider_sliderMoved(int)));

    //janela auxiliar
    auxiliarWindow = new secondWindow();
    auxiliarWindow->show();
    initSecondWindow();

    initBG();
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
    delete []fileNames;
}

void ProjetoFinal::initVideo(const char *fileName){
    if(video != NULL)
        video->release();
    video = new VideoCapture(fileName);

    if(!video->isOpened())
        reportBad("video nao pode ser aberto");

    pauseVideo();

}

void ProjetoFinal::initVideo(){
    if(video != NULL)
        video->release();
    video = new VideoCapture(0);

    if(!video->isOpened())
        reportBad("webcam 0 nao pode ser aberta");

    pauseVideo();
}

void ProjetoFinal::initBG(){

    if(bg != NULL)
        delete bg;

    bg = new cv::BackgroundSubtractorMOG2();

    static int iTauMax = 100;
    bg->nmixtures = 20;
    bg->bShadowDetection = true;
    bg->nShadowDetection = 0;
    bg->fTau = ((float)iTau)/((float)iTauMax);
}

void ProjetoFinal::uptdateBG(){
    static int iTauMax = 100;
    bg->nmixtures = 20;
    bg->fTau = ((float)iTau)/((float)iTauMax);
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
    initBG();
}

void ProjetoFinal::on_speedSlider_sliderMoved(int position)
{
    report("timer set to " + ToString(position) + "\n");
    timer->start(position);
}

void ProjetoFinal::on_videoFileOption_currentIndexChanged(int index)
{
    report("mudando de vídeo");

    if(index == 0)
        initVideo();
    else
        {
        videoAtual = index - 1;
        //subtraimos 1 pq o 0 e a webcam
        initVideo(fileNames[videoAtual].c_str());
        }
    initBG();
    runVideo();
}

//--------------------------------------------------------
//---------------PROCESSAMENTO----------------------------
//--------------------------------------------------------

void ProjetoFinal::process()
{

    if(this->run == true)
        {
        *video >> currentFrame;

        if(currentFrame.empty())
            {
            report("frame nao pode ser capturado!");
            pauseVideo();
            return;
            }
        Mat frame;
        Mat backG, foreG;

        Mat outputFrame(currentFrame.rows,
                        currentFrame.cols,
                        CV_8UC3);

        std::vector<std::vector<cv::Point> > contours;

        currentFrame.copyTo(frame);

        medianBlur ( frame, frame, 9);

        auxiliarWindow->setWindow(frame, 1);

        this->uptdateBG();
        bg->operator ()(frame,foreG);
        bg->getBackgroundImage(backG);

        auxiliarWindow->setWindow(backG, 2);
        auxiliarWindow->setWindow(foreG, 3);

        cv::findContours(foreG,contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);

        currentFrame.copyTo(outputFrame);
        cv::drawContours(outputFrame,contours,-1,cv::Scalar(0,0,255),2);

        //show Qimage using QLabel
        setInputImg(currentFrame);
        setOutputImg(outputFrame);
        }
}

void ProjetoFinal::on_closeButtom_clicked()
{
    auxiliarWindow->close();
    exit(0);
}


void ProjetoFinal::on_runDemoKalman_clicked()
{
    pauseVideo();
    MyKalmanFilter::runDemo2();
}


void ProjetoFinal::on_clearButtom_clicked()
{
    ui->logText->clear();
}
