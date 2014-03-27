#include "widget.h"
#include <QApplication>

bool CONTROL_FILTER_GAUSSIAN = false;
bool CONTROL_SEE_FUTURE = false;
bool CONTROL_SEE_PAST = false;
bool CONTROL_GNUPLOT = false;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
