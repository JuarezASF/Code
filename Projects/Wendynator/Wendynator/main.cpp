#include "mainwindow.h"
#include <QApplication>

unsigned char _CONTOTROL_SensorType = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
