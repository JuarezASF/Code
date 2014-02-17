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

//    mySensor = (ColorSensor *)sensor;
  //  inputImg.copyTo(input);

    //Cv2QtImage::setLabelImage(ui->inputImgLabel, inputImg);
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
