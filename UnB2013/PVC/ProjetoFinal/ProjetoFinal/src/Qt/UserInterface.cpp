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
    //initVideo();
    runVideo();
    connect(ui->speedSlider, SIGNAL(sliderMoved(int)), this, SLOT(on_speedSlider_sliderMoved(int)));

    //janela auxiliar
    auxiliarWindow = new secondWindow();
    auxiliarWindow->show();
    initSecondWindow();

    initBG();


    //COLOTS TRACKBARS
    ui->ColorMinChannelOption->addItem("Canal 1");
    ui->ColorMinChannelOption->addItem("Canal 2");
    ui->ColorMinChannelOption->addItem("Canal 3");

    ui->ColorMaxChannelOption->addItem("Canal 1");
    ui->ColorMaxChannelOption->addItem("Canal 2");
    ui->ColorMaxChannelOption->addItem("Canal 3");

    //DEFINE COLOR BUTTOM
    /*
    Orange  0-22
    Yellow 22- 38
    Green 38-75
    Blue 75-130
    Violet 130-160
    Red 160-179*/
    ui->DefinedColorOption->addItem("Laranja");
    ui->DefinedColorOption->addItem("Amarelo");
    ui->DefinedColorOption->addItem("Verde");
    ui->DefinedColorOption->addItem("Azul");
    ui->DefinedColorOption->addItem("Roxo");
    ui->DefinedColorOption->addItem("Vermelho");

    //BUTÃO PARA BORRA IMAGEM
    //orem : 3 5 7 9 11 13 21 31
    ui->SizeOfGaussian->addItem("3");//0
    ui->SizeOfGaussian->addItem("5");//1
    ui->SizeOfGaussian->addItem("7");
    ui->SizeOfGaussian->addItem("9");//3
    ui->SizeOfGaussian->addItem("11");
    ui->SizeOfGaussian->addItem("13");//5
    ui->SizeOfGaussian->addItem("21");
    ui->SizeOfGaussian->addItem("31");//7
    ui->SizeOfGaussian->addItem("51");
    ui->SizeOfGaussian->addItem("61");//9
    ui->SizeOfGaussian->addItem("71");
    ui->SizeOfGaussian->setCurrentIndex(7);


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
    if(video == NULL)
        video = new VideoCapture(fileName);
    else
    {
    video->release();
    video->open(fileName);

    if(!video->isOpened())
        reportBad("video nao pode ser aberto");
    }
    pauseVideo();

}

void ProjetoFinal::initVideo(){
    if(video == NULL)
        video = new VideoCapture(0);
    else
    {
        video->release();
        video->open(0);

    if(!video->isOpened())
        reportBad("webcam 0 nao pode ser aberta");
    }
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

void ProjetoFinal::on_ColorMinChannelSlider_valueChanged(int value)
{
    ui->ColorMinValue->setText(QString::number(value));
    switch(ui->ColorMinChannelOption->currentIndex()){

        case 0:
                minCorHSV[0] = value;
                break;
        case 1:
                minCorHSV[1] = value;
                break;
        case 2:
                minCorHSV[2] = value;
                break;
        default:
                reportBad("Opção para cor não definida");
                break;
    }
}

void ProjetoFinal::on_ColorMaxChannelSlider_valueChanged(int value)
{
    ui->ColorMaxValue->setText(QString::number(value));

    switch(ui->ColorMaxChannelOption->currentIndex()){

        case 0:
                maxCorHSV[0] = value;
                break;
        case 1:
                maxCorHSV[1] = value;
                break;
        case 2:
                maxCorHSV[2] = value;
                break;
        default:
                reportBad("Opção para cor não definida");
                break;
    }

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
        //-----------BACKGROUND OPERATIONS----------------
        //------------------------------------------------
        if(CONTROL_COLORDETECTION)
            {
              Mat frameHSV;
              cvtColor(frame, frameHSV, CV_BGR2HSV);

             outputFrame = ColorDetection::GetThresholdedImage
                        (frameHSV,minCorHSV, maxCorHSV);
            }

        //------------------------------------------------
        //-----------SAÍDA FINAL--------------------------
        //------------------------------------------------

        //show Qimage using QLabel
        setInputImg(currentFrame);
        setOutputImg(outputFrame);
        }
}





void ProjetoFinal::on_ColorMinChannelOption_currentIndexChanged(int index)
{
    QSlider *target = ui->ColorMinChannelSlider;
    int valueToChangeTo;

    switch(index){
        case 0:
            valueToChangeTo = minCorHSV[0];
            target->setRange(0, 179);
            break;
        case 1:
            valueToChangeTo = minCorHSV[1];
            target->setRange(0, 255);
            break;
        case 2:
            valueToChangeTo = minCorHSV[2];
            target->setRange(0, 255);
            break;
        default:
            reportBad("Caso não definido!");
            break;
        }

    target->setValue(valueToChangeTo);
}

void ProjetoFinal::on_ColorMaxChannelOption_currentIndexChanged(int index)
{
        QSlider *target = ui->ColorMaxChannelSlider;
        int valueToChangeTo;

        switch(index){
            case 0:
                valueToChangeTo = maxCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = maxCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = maxCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                reportBad("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);

}

void ProjetoFinal::on_DefinedColorOption_currentIndexChanged(int index)
{
        switch(index){
            case 0://laranja 0-22
                minCorHSV[0] = 0;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 22;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 1://amarelo 22-38
                minCorHSV[0] = 22;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 38;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 2: // verde 38-75
                minCorHSV[0] = 38;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 75;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 3://azul 75-130
                minCorHSV[0] = 75;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 130;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 4:// violeta 130-160
                minCorHSV[0] = 130;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 160;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 5:// vermelho 160-179
                minCorHSV[0] = 160;
                minCorHSV[1] = 0;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 179;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 6:
                reportBad("Opção Indefinida!");
                break;

            }

        this->updateColorTrackBars();

}

void ProjetoFinal::updateColorTrackBars()
    {
        QSlider *target = ui->ColorMaxChannelSlider;
        int index = ui->ColorMaxChannelOption->currentIndex();
        int valueToChangeTo;

        switch(index){
            case 0:
                valueToChangeTo = maxCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = maxCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = maxCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                reportBad("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);

        target = ui->ColorMinChannelSlider;
        index = ui->ColorMinChannelOption->currentIndex();

        switch(index){
            case 0:
                valueToChangeTo = minCorHSV[0];
                target->setRange(0, 179);
                break;
            case 1:
                valueToChangeTo = minCorHSV[1];
                target->setRange(0, 255);
                break;
            case 2:
                valueToChangeTo = minCorHSV[2];
                target->setRange(0, 255);
                break;
            default:
                reportBad("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);


    }



void ProjetoFinal::on_BackGroundSubButtom_clicked()
{
        if(CONTROL_BGSub == true)
            CONTROL_BGSub = false;
        else
            CONTROL_BGSub = true;
}

void ProjetoFinal::on_ColorDetectionButtom_clicked()
{
        if(CONTROL_COLORDETECTION == true)
            CONTROL_COLORDETECTION = false;
        else
            CONTROL_COLORDETECTION = true;
}

void ProjetoFinal::on_BorrarButtom_clicked()
{
        if(CONTROL_FILTER_GAUSSIAN == true)
            CONTROL_FILTER_GAUSSIAN =false;
        else
            CONTROL_FILTER_GAUSSIAN = true;
}

void ProjetoFinal::on_SizeOfGaussian_currentIndexChanged(int index)
{
        //ordem : 3 5 7 9 11 13 21 31
        SizeGaussFilter = ui->SizeOfGaussian->currentText().toInt();
}
