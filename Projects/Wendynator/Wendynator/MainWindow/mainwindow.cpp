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

    //START CLOCK (PÓS CÂMERA SER INICIALIZADA)
    this->clock->start(50);
    //lança evento timeout() a cada 500 milisegundos

    //set opções de sensor
    ui->SensorTypeComboBox->addItem("[0] : NONE");
    ui->SensorTypeComboBox->addItem("[1] : Color Sensor");
    ui->SensorTypeComboBox->addItem("[2] : TemplateMatching Sensor");

    mySensor = NULL;
    setSensorType(SensorType::NONE);
    report("Por favor, escolha e configure um tipo de sensor");
    colorConfigWindow = NULL;
    templateConfigWindow = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete colorConfigWindow;
    delete templateConfigWindow;
}


bool MainWindow::openVideo(int n){
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

void MainWindow::initVideo(){
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
    case(SensorType::NONE):
        if(mySensor) delete mySensor;
             mySensor = NULL;
        _CONTROL_SensorType = SensorType::NONE;
        _CONTROL_SensorSetted = false;
        reportBad("Sensor setado para NULO!");
        break;
    case(SensorType::ColorSensor):
        if(mySensor)
           {
            if(_CONTROL_SensorType != SensorType::ColorSensor)
                {
                delete mySensor;
                report("Antigo sensor destruído");

                mySensor = new ColorSensor;
                reportGood("Novo sensor de cor criado!");
                }
            else
                {
                report("Basta configurar o sensor de cor!");
                this->colorConfigWindow->setCurrentImg(currentFrame);
                }
            }
        else
            {
            mySensor = new ColorSensor();
            reportGood("Sensor de cor criado!");
            }

        _CONTROL_SensorType = SensorType::ColorSensor;

        break;
    case(SensorType::MatchingSensor):
        if(mySensor)
        {
            if(_CONTROL_SensorType != SensorType::MatchingSensor)
                {
                delete mySensor;
                report("Antigo sensor destruído!");

                mySensor = new TemplateMatchSensor();
                reportGood("Sensor de matching criado!");
                }
            else
                {
                report("basta configurar");
                this->templateConfigWindow->setCurrentImg(currentFrame);
                }
        }
        else
            {
            mySensor = new TemplateMatchSensor();
            reportGood("Sensor de matching criado!");
            }

        _CONTROL_SensorType = SensorType::MatchingSensor;

        break;
    }
}

void MainWindow::on_SensorTypeSetButton_clicked()
{
    _CONTROL_SensorSetted = false;

    int option = ui->SensorTypeComboBox->currentIndex();

    switch(option){
    case(SensorType::NONE):
        setSensorType(option);
        break;
    case(SensorType::ColorSensor):
        setSensorType(option);
        if(!colorConfigWindow)
            colorConfigWindow = new ColorSensorConfig(currentFrame, mySensor);
        colorConfigWindow->setSensor(mySensor);
        colorConfigWindow->setWindowTitle("Configuração do Sensor de Cor");
        colorConfigWindow->show();
        break;
    case(SensorType::MatchingSensor):
        setSensorType(option);
        report("lançando janela de congifuração do sensor de matching");
        if(!templateConfigWindow)
            templateConfigWindow = new TemplateSensorConfigWindows(currentFrame, mySensor, this);
        templateConfigWindow->setWindowTitle("Configuração do Sensor de Template Matching");
        templateConfigWindow->show();
        break;
    default:
        throw "Tipo de sensor inválido!";
        setSensorType(SensorType::NONE);
        break;
    }

}

void MainWindow::on_pushButton_clicked()
{
    ui->logText->clear();
}

void MainWindow::drawDetectedObject(Point &center){

    Mat mask(RGB_Output.rows,
                   RGB_Output.cols,
                   RGB_Output.type(),
                   Scalar(0,0,0));

    switch(_CONTROL_SensorType){
    case(SensorType::ColorSensor):
        Draw::Cross(mask,center, Scalar(255,255,255), 25);
        break;
    case(SensorType::MatchingSensor):
        int w = ((TemplateMatchSensor *)mySensor)->getTplWidth();
        int h = ((TemplateMatchSensor *)mySensor)->getTplHeigh();

        Point leftTop(center.x - w/2, center.y - h/2);
        Point rightBottom(center.x + w/2, center.y + h/2);

        rectangle( mask, leftTop, rightBottom, Scalar::all(255), 2, 8, 0 );
        break;
    }

    masks.push_back(mask);
}
