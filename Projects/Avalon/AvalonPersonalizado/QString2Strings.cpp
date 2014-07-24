#include "QString2String.h"

QString2String::QString2String()
{
}

QString QString2String::Scalar2QString(Scalar &target){

    QString qstring("(");
    int i;
    for(i = 0; i < target.channels - 2; i++)
        qstring.append(QString::number(target[i]).append(","));
    qstring.append(QString::number(target[i]).append(")"));

    return qstring;
}
