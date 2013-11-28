#ifndef PROJETOFINAL_H
#define PROJETOFINAL_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include "cv2qtimage.h"

using namespace  cv;

namespace Ui {
class ProjetoFinal;
}

class ProjetoFinal : public QMainWindow
{
    Q_OBJECT

public:
    explicit ProjetoFinal(QWidget *parent = 0);
    ~ProjetoFinal();

private slots:

    void on_pastButtom_stateChanged(int arg1);

    void on_futureButtom_stateChanged(int arg1);

private:
    Ui::ProjetoFinal *ui;
public:
    bool futureMode, pastMode;

public:
    void setInputImg(const cv::Mat &img);

};

#endif // PROJETOFINAL_H
