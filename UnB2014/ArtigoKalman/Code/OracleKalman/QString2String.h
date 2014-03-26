#ifndef QSTRING2STRING_H
#define QSTRING2STRING_H
//C++ LIBS
#include <string>
#include <iostream>
#include <vector>

#include <QString>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
using namespace cv;
using namespace std;

class QString2String
{
public:
    QString2String();

    static QString Scalar2QString(Scalar &target);
};

#endif // QSTRING2STRING_H
