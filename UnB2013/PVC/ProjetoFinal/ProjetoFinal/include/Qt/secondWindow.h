#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QWidget>
#include <QLabel>

#include <opencv2/core/core.hpp>
#include <cv2qtimage.h>

extern int iTau;

extern Scalar minCorHSV;
extern Scalar maxCorHSV;


namespace Ui {
class secondWindow;
}

class secondWindow : public QWidget
{
    Q_OBJECT
private:
    int nWindows;

public:
    explicit secondWindow(QWidget *parent = 0);
    ~secondWindow();

    //seta imagem principal
    void setWindow(const cv::Mat &img, int n);



private slots:
    void on_shadowSlider_valueChanged(int value);


private:
    Ui::secondWindow *ui;


};

#endif // SECONDWINDOW_H
