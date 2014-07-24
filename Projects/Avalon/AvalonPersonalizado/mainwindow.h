#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

//OPENCV LIBS
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "AvalonCustomizer.h"
#include "cv2qtimage.h"

#include <iostream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    AvalonCustomizer *customizador;
    unsigned int currentType;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_nomeLineEdit_returnPressed();

    void on_botaoCarregar_clicked();

private:
    Ui::MainWindow *ui;

private:
    void update();
};

#endif // MAINWINDOW_H
