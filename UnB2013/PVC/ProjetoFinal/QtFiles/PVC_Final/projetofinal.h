#ifndef PROJETOFINAL_H
#define PROJETOFINAL_H

#include <string>

#include <QMainWindow>

#include <QCursor>
#include <QMouseEvent>

#include <opencv2/core/core.hpp>

#include "cv2qtimage.h"

using namespace  cv;

namespace Ui {
class ProjetoFinal;
}

class ProjetoFinal : public QMainWindow
{
    Q_OBJECT

private:
    Ui::ProjetoFinal *ui;
    QCursor *mouseCursor;
public:
    bool futureMode, pastMode;

public:

    explicit ProjetoFinal(QWidget *parent = 0);
    ~ProjetoFinal();

    void setInputImg(const cv::Mat &img);

    QPoint getMousePos();

    void report(string text);
    void reportGood(string text);
    void reportBad(string text);
    void reportWarning(string text);

private slots:

    void on_pastButtom_stateChanged(int arg1);

    void on_futureButtom_stateChanged(int arg1);

};

#endif // PROJETOFINAL_H
