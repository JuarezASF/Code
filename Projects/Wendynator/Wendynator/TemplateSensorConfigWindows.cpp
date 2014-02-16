#include "TemplateSensorConfigWindows.h"
#include "ui_TemplateSensorConfigWindows.h"

TemplateSensorConfigWindows::TemplateSensorConfigWindows(Mat frame, InterfaceSensor *sensor,
                                                         QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateSensorConfigWindows)
{
    ui->setupUi(this);

    rubberBand = NULL;

    Cv2QtImage::setLabelImage(ui->inputImg, frame);
}

TemplateSensorConfigWindows::~TemplateSensorConfigWindows()
{
    delete ui;
}

void TemplateSensorConfigWindows::mousePressEvent(QMouseEvent *event)
 {
    /*todo QWidget possui eventos de mouse definidos,
        ao fazermos isso estamos redefinindo o método!
        problema: temos que criar uma classe para fazer isso,
        não podemos setar para um objeto em particular*/
     origin = event->pos();
     if (!rubberBand)
         rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->inputImg);
     rubberBand->setGeometry(QRect(origin, QSize()));
     rubberBand->show();
 }

 void TemplateSensorConfigWindows::mouseMoveEvent(QMouseEvent *event)
 {
     rubberBand->setGeometry(QRect(origin, event->pos()));
     ui->widthValue->setText(QString::number(rubberBand->size().width()));
     ui->highValue->setText(QString::number(rubberBand->size().height()));

 }

 void TemplateSensorConfigWindows::mouseReleaseEvent(QMouseEvent *event)
 {
     rubberBand->hide();


 }

void TemplateSensorConfigWindows::on_okButtom_clicked()
{
    this->close();
}
