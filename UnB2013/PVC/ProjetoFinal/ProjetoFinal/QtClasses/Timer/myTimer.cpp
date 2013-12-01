#include "myTimer.h"



void myTimer::wait(int  milisecondTime){
    QTimer myClock;

    myClock.setInterval(milisecondTime);
    myClock.start();

    while(myClock.isActive())
        {}
    return;
}
