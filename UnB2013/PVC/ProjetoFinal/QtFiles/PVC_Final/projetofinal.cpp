#include "projetofinal.h"
#include "ui_projetofinal.h"

ProjetoFinal::ProjetoFinal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjetoFinal)
{
    ui->setupUi(this);

    connect(ui->pastButtom, SIGNAL(stateChanged(int)), this, SLOT(on_pastButtom_stateChanged(int)));
    connect(ui->futureButtom, SIGNAL(stateChanged(int)), this, SLOT(on_futureButtom_stateChanged(int)));

    pastMode = false;
    futureMode = false;
}

ProjetoFinal::~ProjetoFinal()
{
    delete ui;
}

void ProjetoFinal::setInputImg(const cv::Mat &img){

    QImage myQImg = Cv2QtImage::Mat2QImage(img);
    ui->inputImg->setPixmap(QPixmap::fromImage(myQImg));
}


void ProjetoFinal::on_pastButtom_stateChanged(int arg1)
{
    pastMode = ui->pastButtom->isChecked();
}

void ProjetoFinal::on_futureButtom_stateChanged(int arg1)
{
    futureMode = ui->futureButtom->isChecked();
}
