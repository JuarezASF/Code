#include "ColorSensorConfig.h"
#include "ui_ColorSensorConfig.h"

ColorSensorConfig::ColorSensorConfig(Mat &inputImg, InterfaceSensor *sensor, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSensorConfig)
{
    ui->setupUi(this);

    //COLOTS TRACKBARS
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


    //não sei porque não estava funcionando sem definir explicitamente o tamanho
    ui->inputImg->setGeometry(1, 1, 220, 220);
    ui->outputImgLabel->setGeometry(1, 221, 220, 220);

    setCurrentImg(inputImg);

    mySensor = (ColorSensor *) sensor;

    connect(this, SIGNAL(rangeChanged()), this, SLOT(findThresholdImg()));

    minCorHSV[0] = 100;
    minCorHSV[1] = 0;
    minCorHSV[2] = 0;

    maxCorHSV[0] = 179;
    maxCorHSV[1] = 255;
    maxCorHSV[2] = 255;

    this->updateColorTrackBars();
    emit rangeChanged();

}

ColorSensorConfig::~ColorSensorConfig()
{
    delete ui;
}

void ColorSensorConfig::on_ColorMinChannelSlider_valueChanged(int value)
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

void ColorSensorConfig::on_ColorMaxChannelSlider_valueChanged(int value)
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




void ColorSensorConfig::on_ColorMinChannelOption_currentIndexChanged(int index)
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

void ColorSensorConfig::on_ColorMaxChannelOption_currentIndexChanged(int index)
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

void ColorSensorConfig::on_DefinedColorOption_currentIndexChanged(int index)
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

void ColorSensorConfig::updateColorTrackBars()
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

void ColorSensorConfig::errorMsg(string msg){
    QMessageBox msgBox;
    msgBox.setText(QString(msg.c_str()));
    msgBox.exec();
}

    void ColorSensorConfig::setCurrentImg(Mat &frame){
        Cv2QtImage::setLabelImage(ui->inputImg, frame);
        frame.copyTo(this->inputImg);
    }

    void ColorSensorConfig::setOutputImg(Mat &frame){
        Cv2QtImage::setLabelImage(ui->outputImgLabel, frame);
        frame.copyTo(this->outputImg);
    }

void ColorSensorConfig::on_okButtom_clicked()
{
    Scalar minColor(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar maxColor(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);

    if( maxColor[0] < minColor[0] || maxColor[1] < minColor[1] || maxColor[2] < minColor[2] )
    {
        errorMsg(string("Range inválido! Escolha novamente"));
    }

    else{
    mySensor->setRange(minColor, maxColor);
    _CONTROL_SensorSetted = true;
    this->close();
    }
}

void ColorSensorConfig::findThresholdImg(){
    Mat HSV_Input;
    cvtColor(inputImg, HSV_Input, CV_BGR2HSV);

    Scalar colorMin(minCorHSV[0], minCorHSV[1], minCorHSV[2]);
    Scalar colorMax(maxCorHSV[0], maxCorHSV[1], maxCorHSV[2]);


    Mat BinaryImg =
                ColorDetection::GetThresholdedImage(
                     HSV_Input, colorMin,colorMax);

    setOutputImg(BinaryImg);

}

void ColorSensorConfig::setSensor(InterfaceSensor *sensor){
    this->mySensor = (ColorSensor *)sensor;
}

