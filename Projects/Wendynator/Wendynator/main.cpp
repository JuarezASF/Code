#include "MainWindow/mainwindow.h"
#include <QApplication>

unsigned char _CONTROL_SensorType = 0;
bool _CONTROL_SensorSetted = false;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
