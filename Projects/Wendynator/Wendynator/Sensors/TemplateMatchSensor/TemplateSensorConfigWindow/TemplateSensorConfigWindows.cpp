#include "TemplateSensorConfigWindows.h"
#include "ui_TemplateSensorConfigWindows.h"

TemplateSensorConfigWindows::TemplateSensorConfigWindows(Mat frame, InterfaceSensor *sensor, QMainWindow *pai,
                                                         QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateSensorConfigWindows)
{
    ui->setupUi(this);

    father = pai;

    rubberBand = NULL;

    ui->inputImg->setGeometry(50, 40, frame.cols, frame.rows);
    Cv2QtImage::setLabelImage(ui->inputImg, frame);

    frame.copyTo(currentFrame);

    mySensor = (TemplateMatchSensor *) sensor;

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
     origin = event->pos() - ui->inputImg->pos();
     if (!rubberBand)
         rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->inputImg);
     rubberBand->setGeometry(QRect(origin, QSize()));
     rubberBand->show();
 }

 void TemplateSensorConfigWindows::mouseMoveEvent(QMouseEvent *event)
 {

     QPoint end = event->pos() - ui->inputImg->pos();
     QRect  rect(origin, end);
     rubberBand->setGeometry(rect);
     ui->widthValue->setText(QString::number(rubberBand->size().width()));
     ui->highValue->setText(QString::number(rubberBand->size().height()));

     leftBottom  = rect.bottomLeft();
     leftTop     = rect.topLeft();
     rightTop    = rect.topRight();
     rightBottom = rect.bottomRight();

     ui->leftTopValueLabel->setText(QString("(") +
                                    QString::number(leftTop.x()) +
                                    QString(",") +
                                    QString::number(leftTop.y()) +
                                    QString(")"));

     ui->rightBottomValueLabel->setText(QString("(") +
                                    QString::number(rightBottom.x()) +
                                    QString(",") +
                                    QString::number(rightBottom.y()) +
                                    QString(")"));



 }

 void TemplateSensorConfigWindows::mouseReleaseEvent(QMouseEvent *event)
 {
     rubberBand->hide();

     ROI = currentFrame(Range(leftTop.y(), rightBottom.y()), Range(leftTop.x(), rightBottom.x()));
     ui->templateImg->setGeometry(710, 380, ROI.cols, ROI.rows);
     Cv2QtImage::setLabelImage(ui->templateImg, ROI);

 }

void TemplateSensorConfigWindows::on_okButtom_clicked()
{
    if(ROI.cols * ROI.rows != 0)
    {
    this->close();
    mySensor->setTemplateMat(ROI);
    _CONTROL_SensorSetted = true;
    }
    else{
        QMessageBox msg;
        msg.setText("Escolha uma ROI de tamanho não nulo!");
        msg.exec();
    }
}
