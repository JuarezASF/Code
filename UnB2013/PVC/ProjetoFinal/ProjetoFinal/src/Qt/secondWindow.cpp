#include "secondWindow.h"
#include "ui_secondWindow.h"

secondWindow::secondWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}

secondWindow::~secondWindow()
{
    delete ui;
}

void secondWindow::setWindow(const cv::Mat &img, int n)
{
    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    QPixmap myQpix = QPixmap::fromImage(myQImg);

    QLabel *target;

    switch (n%nWindows)
    {
        case 1:
            target = ui->window1;
            break;
        case 2:
            target = ui->window2;
            break;
        case 3:
            target = ui->window3;
            break;
        case 4:
            target = ui->window4;
            break;
        case 5:
            target = ui->window5;
            break;
        case 6:
            target = ui->window6;
            break;
        case 7:
            target = ui->window7;
            break;
        case 8:
            target = ui->window8;
            break;
        default:
            target = ui->window8;
            break;
    }

    myQpix =  myQpix.scaled(target->size());
    //myQpix =  myQpix.scaled(target->size(),  Qt::IgnoreAspectRatio);

    target->setPixmap(myQpix);
}

void secondWindow::on_shadowSlider_valueChanged(int value)
{
    iTau = value;
    ui->shadowValue->setText(QString::number(value));
}


