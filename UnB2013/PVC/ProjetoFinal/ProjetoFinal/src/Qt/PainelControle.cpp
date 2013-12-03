#include "include/Qt/PainelControle.h"
#include "ui_PainelControle.h"

PainelControle::PainelControle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PainelControle)
{
    ui->setupUi(this);
}

PainelControle::~PainelControle()
{
    delete ui;
}
