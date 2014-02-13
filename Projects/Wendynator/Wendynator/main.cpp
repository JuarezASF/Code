#include "mainwindow.h"
#include <QApplication>

unsigned char _CONTOTROL_SensorType = 0;
bool _CONTROL_SET_MATCHING_TEMPLATE_MODE = false;
bool _CONTROL_SET_MATCHING_TEMPLATE_FIRST_POINT_MODE = false;
bool _CONTROL_SET_MATCHING_TEMPLATE_SECOND_POINT_MODE = false;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
