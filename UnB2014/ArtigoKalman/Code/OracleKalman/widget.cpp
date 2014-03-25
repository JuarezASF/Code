#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //SET CLOCK
    this->clock = new QTimer(this);
    connect(this->clock, SIGNAL(timeout()), this, SLOT(process()));

    //INITIATE CAMERA
    videoInput = NULL;
    initVideo();

    //START CLOCK (PÓS CÂMERA SER INICIALIZADA)
    this->clock->start(50);
    //lança evento timeout() a cada 500 milisegundos

    //COLOTS TRACKBARS

    connect(this, SIGNAL(rangeChanged()), this, SLOT(findThresholdImg()));

    ui->ColorMinChannelOption->addItem("hue");
    ui->ColorMinChannelOption->addItem("saturation");
    ui->ColorMinChannelOption->addItem("value");

    ui->ColorMaxChannelOption->addItem("hue");
    ui->ColorMaxChannelOption->addItem("saturation");
    ui->ColorMaxChannelOption->addItem("value");

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

    minCorHSV[0] = 100;
    minCorHSV[1] = 0;
    minCorHSV[2] = 0;

    maxCorHSV[0] = 179;
    maxCorHSV[1] = 255;
    maxCorHSV[2] = 255;

    this->updateColorTrackBars();
    emit rangeChanged();



}

Widget::~Widget()
{
    delete ui;
}

bool Widget::openVideo(int n){
    if(videoInput == NULL)
        videoInput = new VideoCapture(n);
    else
    {
        videoInput->release();
        videoInput->open(n);
    }

    if(!videoInput->isOpened()){
       stringstream msg;
       msg << "webcam " << n << " não pode ser aberta";
       reportBad(msg.str());
       return false;
    }

    if(videoInput->isOpened())
        return true;
   }

void Widget::initVideo(){
    bool sucesso;
    for(int i = 0; i < 10; i++)
    {
        sucesso = openVideo(i);
        if(sucesso)
            break;
    }
    if(sucesso == false)
    {
        reportBad("Nenhum vídeo de 0 à 10 pode ser inicializado!");
        this->clock->stop();
    }
}


void Widget::report(const string text){
    ui->logText->setTextColor(QColor("blue"));
    ui->logText->append(QString(text.c_str()));
}



void Widget::reportGood(const string text){
    ui->logText->setTextColor(QColor("green"));
    ui->logText->append(QString(text.c_str()));
}
void Widget::reportBad(const string text){
    ui->logText->setTextColor(QColor("red"));
    ui->logText->append(QString(text.c_str()));
}

void Widget::on_ColorMinChannelSlider_valueChanged(int value)
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
                errorMsg("Opção para cor não definida");
                break;
    }

     emit rangeChanged();

}

void Widget::on_ColorMaxChannelSlider_valueChanged(int value)
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
                errorMsg("Opção para cor não definida");
                break;
    }

    emit rangeChanged();

}

void Widget::on_ColorMinChannelOption_currentIndexChanged(int index)
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
            errorMsg("Caso não definido!");
            break;
        }

    target->setValue(valueToChangeTo);
}

void Widget::on_ColorMaxChannelOption_currentIndexChanged(int index)
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
                errorMsg("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);

}

void Widget::on_DefinedColorOption_currentIndexChanged(int index)
{
        switch(index){
            case 0://laranja 0-22
                minCorHSV[0] = 0;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 22;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 1://amarelo 22-38
                minCorHSV[0] = 22;
                minCorHSV[1] = 70;
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
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 130;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 4:// violeta 130-160
                minCorHSV[0] = 130;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 160;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;
            case 5:// vermelho 160-179
                minCorHSV[0] = 160;
                minCorHSV[1] = 70;
                minCorHSV[2] = 0;

                maxCorHSV[0] = 179;
                maxCorHSV[1] = 255;
                maxCorHSV[1] = 255;

                break;

            case 6:
                errorMsg("Opção Indefinida!");
                break;

            }

        this->updateColorTrackBars();
        emit rangeChanged();

}

void Widget::updateColorTrackBars()
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
                errorMsg("Caso não definido!");
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
                errorMsg("Caso não definido!");
                break;
            }

        target->setValue(valueToChangeTo);


    }

void Widget::errorMsg(string msg){
    QMessageBox msgBox;
    msgBox.setText(QString(msg.c_str()));
    msgBox.exec();
}

void Widget::findThresholdImg(){

    if(!currentFrame.empty())
    {
    Mat HSV_Input;
    cvtColor(currentFrame, HSV_Input, CV_BGR2HSV);

    Scalar colorMin(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar colorMax(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);


    Mat BinaryImg =
                ColorDetection::GetThresholdedImage(
                     HSV_Input, colorMin,colorMax);

    Cv2QtImage::setLabelImage(ui->currentSegmentationImg, BinaryImg);
    }
}

void Widget::addColorToTracking(vector<Scalar> &range){

    Mat HSV_Input;
    cvtColor(currentFrame, HSV_Input, CV_BGR2HSV);

    Mat BinaryImg =
                ColorDetection::GetThresholdedImage(
                HSV_Input, range[0],range[1]);
    bool inutil;
    Point initialPos = ColorDetection::FindCenter(BinaryImg, 0, inutil);


    Scalar color = (range[0] + range[1])*0.5;

    ObjectToDetect *newTarget = new ObjectToDetect(range, color, initialPos);

    report("Objeto Criado!");

    targets.push_back(newTarget);

   QString targetName = QString("Objeto ") + QString::number(newTarget->name);

    ui->trackedColorsList->addItem(targetName);
}

void Widget::on_addTotrackingButtom_clicked()
{
    Scalar minColor(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar maxColor(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);

    if( maxColor[0] < minColor[0] || maxColor[1] < minColor[1] || maxColor[2] < minColor[2] )
    {
        errorMsg(string("Range inválido! Escolha novamente"));
    }
    else{
    vector<Scalar> range;
    range.push_back(minColor);
    range.push_back(maxColor);

    addColorToTracking(range);
    }

}
