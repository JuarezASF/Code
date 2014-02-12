/********************************************************************************
** Form generated from reading UI file 'UserInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINTERFACE_H
#define UI_USERINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjetoFinal
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *logText;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *FuturePastLayout;
    QCheckBox *futureButtom;
    QCheckBox *pastButtom;
    QWidget *layoutWidget1;
    QHBoxLayout *speedLayout;
    QLabel *label_3;
    QSlider *speedSlider;
    QPushButton *closeButtom;
    QPushButton *runDemoKalman;
    QComboBox *videoFileOption;
    QWidget *layoutWidget2;
    QHBoxLayout *PauseRestartLayout;
    QPushButton *pauseButtom;
    QPushButton *restartButtom;
    QPushButton *clearButtom;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout;
    QLabel *inputImg;
    QLabel *outputImg;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ColorMinLabel;
    QComboBox *ColorMinChannelOption;
    QHBoxLayout *horizontalLayout;
    QLabel *ColorMinValue;
    QSlider *ColorMinChannelSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ColorMaxLabel;
    QComboBox *ColorMaxChannelOption;
    QHBoxLayout *horizontalLayout_7;
    QLabel *ColorMaxValue;
    QSlider *ColorMaxChannelSlider;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *DefineColorLabel;
    QComboBox *DefinedColorOption;
    QLabel *GlobalModeLabel;
    QComboBox *GlobalModeOption;
    QPushButton *ClearPastButtom;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ColorDetectionThresholdLabel;
    QLabel *ColorDetectionThresholdSliderValue;
    QSlider *ColorDetectionThresholdSlider;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *BackGroundSubButtom;
    QPushButton *ColorDetectionButtom;
    QPushButton *BorrarButtom;
    QComboBox *SizeOfGaussian;
    QPushButton *InitKalmanButtom;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *raioLabel;
    QLabel *raioValueLabel;
    QSlider *raioSlider;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *SaveInputLabel;
    QLineEdit *SaveInputEdit;
    QPushButton *SaveInputButtom;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_9;
    QLabel *SaveLabel;
    QLineEdit *SaveLineEdit;
    QPushButton *saveButtom;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjetoFinal)
    {
        if (ProjetoFinal->objectName().isEmpty())
            ProjetoFinal->setObjectName(QStringLiteral("ProjetoFinal"));
        ProjetoFinal->resize(1104, 605);
        centralWidget = new QWidget(ProjetoFinal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logText = new QPlainTextEdit(centralWidget);
        logText->setObjectName(QStringLiteral("logText"));
        logText->setGeometry(QRect(200, 330, 521, 101));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 290, 101, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 290, 121, 21));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(91, 341, 81, 52));
        FuturePastLayout = new QVBoxLayout(layoutWidget);
        FuturePastLayout->setSpacing(6);
        FuturePastLayout->setContentsMargins(11, 11, 11, 11);
        FuturePastLayout->setObjectName(QStringLiteral("FuturePastLayout"));
        FuturePastLayout->setContentsMargins(0, 0, 0, 0);
        futureButtom = new QCheckBox(layoutWidget);
        futureButtom->setObjectName(QStringLiteral("futureButtom"));

        FuturePastLayout->addWidget(futureButtom);

        pastButtom = new QCheckBox(layoutWidget);
        pastButtom->setObjectName(QStringLiteral("pastButtom"));
        pastButtom->setChecked(false);

        FuturePastLayout->addWidget(pastButtom);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(500, 0, 241, 31));
        speedLayout = new QHBoxLayout(layoutWidget1);
        speedLayout->setSpacing(6);
        speedLayout->setContentsMargins(11, 11, 11, 11);
        speedLayout->setObjectName(QStringLiteral("speedLayout"));
        speedLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        speedLayout->addWidget(label_3);

        speedSlider = new QSlider(layoutWidget1);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setMaximum(100);
        speedSlider->setValue(50);
        speedSlider->setOrientation(Qt::Horizontal);

        speedLayout->addWidget(speedSlider);

        closeButtom = new QPushButton(centralWidget);
        closeButtom->setObjectName(QStringLiteral("closeButtom"));
        closeButtom->setGeometry(QRect(20, 0, 80, 23));
        runDemoKalman = new QPushButton(centralWidget);
        runDemoKalman->setObjectName(QStringLiteral("runDemoKalman"));
        runDemoKalman->setGeometry(QRect(711, 72, 112, 23));
        videoFileOption = new QComboBox(centralWidget);
        videoFileOption->setObjectName(QStringLiteral("videoFileOption"));
        videoFileOption->setGeometry(QRect(300, 0, 191, 31));
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(120, 0, 178, 29));
        PauseRestartLayout = new QHBoxLayout(layoutWidget2);
        PauseRestartLayout->setSpacing(6);
        PauseRestartLayout->setContentsMargins(11, 11, 11, 11);
        PauseRestartLayout->setObjectName(QStringLiteral("PauseRestartLayout"));
        PauseRestartLayout->setContentsMargins(0, 0, 0, 0);
        pauseButtom = new QPushButton(layoutWidget2);
        pauseButtom->setObjectName(QStringLiteral("pauseButtom"));

        PauseRestartLayout->addWidget(pauseButtom);

        restartButtom = new QPushButton(layoutWidget2);
        restartButtom->setObjectName(QStringLiteral("restartButtom"));

        PauseRestartLayout->addWidget(restartButtom);

        clearButtom = new QPushButton(centralWidget);
        clearButtom->setObjectName(QStringLiteral("clearButtom"));
        clearButtom->setGeometry(QRect(730, 360, 99, 27));
        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(50, 50, 611, 241));
        gridLayout = new QGridLayout(layoutWidget3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        inputImg = new QLabel(layoutWidget3);
        inputImg->setObjectName(QStringLiteral("inputImg"));
        inputImg->setAutoFillBackground(true);

        gridLayout->addWidget(inputImg, 0, 0, 1, 1);

        outputImg = new QLabel(layoutWidget3);
        outputImg->setObjectName(QStringLiteral("outputImg"));
        outputImg->setAutoFillBackground(true);

        gridLayout->addWidget(outputImg, 0, 1, 1, 1);

        layoutWidget4 = new QWidget(centralWidget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(670, 110, 411, 58));
        verticalLayout = new QVBoxLayout(layoutWidget4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ColorMinLabel = new QLabel(layoutWidget4);
        ColorMinLabel->setObjectName(QStringLiteral("ColorMinLabel"));

        horizontalLayout_3->addWidget(ColorMinLabel);

        ColorMinChannelOption = new QComboBox(layoutWidget4);
        ColorMinChannelOption->setObjectName(QStringLiteral("ColorMinChannelOption"));

        horizontalLayout_3->addWidget(ColorMinChannelOption);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ColorMinValue = new QLabel(layoutWidget4);
        ColorMinValue->setObjectName(QStringLiteral("ColorMinValue"));

        horizontalLayout->addWidget(ColorMinValue);

        ColorMinChannelSlider = new QSlider(layoutWidget4);
        ColorMinChannelSlider->setObjectName(QStringLiteral("ColorMinChannelSlider"));
        ColorMinChannelSlider->setMaximum(100);
        ColorMinChannelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(ColorMinChannelSlider);


        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        ColorMaxLabel = new QLabel(layoutWidget4);
        ColorMaxLabel->setObjectName(QStringLiteral("ColorMaxLabel"));

        horizontalLayout_6->addWidget(ColorMaxLabel);

        ColorMaxChannelOption = new QComboBox(layoutWidget4);
        ColorMaxChannelOption->setObjectName(QStringLiteral("ColorMaxChannelOption"));

        horizontalLayout_6->addWidget(ColorMaxChannelOption);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ColorMaxValue = new QLabel(layoutWidget4);
        ColorMaxValue->setObjectName(QStringLiteral("ColorMaxValue"));

        horizontalLayout_7->addWidget(ColorMaxValue);

        ColorMaxChannelSlider = new QSlider(layoutWidget4);
        ColorMaxChannelSlider->setObjectName(QStringLiteral("ColorMaxChannelSlider"));
        ColorMaxChannelSlider->setMaximum(100);
        ColorMaxChannelSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(ColorMaxChannelSlider);


        horizontalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_6);

        layoutWidget5 = new QWidget(centralWidget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(670, 170, 252, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        DefineColorLabel = new QLabel(layoutWidget5);
        DefineColorLabel->setObjectName(QStringLiteral("DefineColorLabel"));

        horizontalLayout_8->addWidget(DefineColorLabel);

        DefinedColorOption = new QComboBox(layoutWidget5);
        DefinedColorOption->setObjectName(QStringLiteral("DefinedColorOption"));

        horizontalLayout_8->addWidget(DefinedColorOption);

        GlobalModeLabel = new QLabel(centralWidget);
        GlobalModeLabel->setObjectName(QStringLiteral("GlobalModeLabel"));
        GlobalModeLabel->setGeometry(QRect(911, 71, 39, 16));
        GlobalModeOption = new QComboBox(centralWidget);
        GlobalModeOption->setObjectName(QStringLiteral("GlobalModeOption"));
        GlobalModeOption->setGeometry(QRect(956, 71, 121, 23));
        ClearPastButtom = new QPushButton(centralWidget);
        ClearPastButtom->setObjectName(QStringLiteral("ClearPastButtom"));
        ClearPastButtom->setGeometry(QRect(90, 400, 80, 23));
        layoutWidget6 = new QWidget(centralWidget);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(690, 270, 321, 17));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ColorDetectionThresholdLabel = new QLabel(layoutWidget6);
        ColorDetectionThresholdLabel->setObjectName(QStringLiteral("ColorDetectionThresholdLabel"));

        horizontalLayout_2->addWidget(ColorDetectionThresholdLabel);

        ColorDetectionThresholdSliderValue = new QLabel(layoutWidget6);
        ColorDetectionThresholdSliderValue->setObjectName(QStringLiteral("ColorDetectionThresholdSliderValue"));

        horizontalLayout_2->addWidget(ColorDetectionThresholdSliderValue);

        ColorDetectionThresholdSlider = new QSlider(layoutWidget6);
        ColorDetectionThresholdSlider->setObjectName(QStringLiteral("ColorDetectionThresholdSlider"));
        ColorDetectionThresholdSlider->setMaximum(100);
        ColorDetectionThresholdSlider->setValue(30);
        ColorDetectionThresholdSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(ColorDetectionThresholdSlider);

        layoutWidget7 = new QWidget(centralWidget);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(32, 450, 496, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BackGroundSubButtom = new QPushButton(layoutWidget7);
        BackGroundSubButtom->setObjectName(QStringLiteral("BackGroundSubButtom"));

        horizontalLayout_4->addWidget(BackGroundSubButtom);

        ColorDetectionButtom = new QPushButton(layoutWidget7);
        ColorDetectionButtom->setObjectName(QStringLiteral("ColorDetectionButtom"));

        horizontalLayout_4->addWidget(ColorDetectionButtom);

        BorrarButtom = new QPushButton(layoutWidget7);
        BorrarButtom->setObjectName(QStringLiteral("BorrarButtom"));

        horizontalLayout_4->addWidget(BorrarButtom);

        SizeOfGaussian = new QComboBox(layoutWidget7);
        SizeOfGaussian->setObjectName(QStringLiteral("SizeOfGaussian"));

        horizontalLayout_4->addWidget(SizeOfGaussian);

        InitKalmanButtom = new QPushButton(layoutWidget7);
        InitKalmanButtom->setObjectName(QStringLiteral("InitKalmanButtom"));

        horizontalLayout_4->addWidget(InitKalmanButtom);

        layoutWidget8 = new QWidget(centralWidget);
        layoutWidget8->setObjectName(QStringLiteral("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(690, 220, 311, 17));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        raioLabel = new QLabel(layoutWidget8);
        raioLabel->setObjectName(QStringLiteral("raioLabel"));

        horizontalLayout_5->addWidget(raioLabel);

        raioValueLabel = new QLabel(layoutWidget8);
        raioValueLabel->setObjectName(QStringLiteral("raioValueLabel"));

        horizontalLayout_5->addWidget(raioValueLabel);

        raioSlider = new QSlider(layoutWidget8);
        raioSlider->setObjectName(QStringLiteral("raioSlider"));
        raioSlider->setMaximum(100);
        raioSlider->setValue(20);
        raioSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(raioSlider);

        layoutWidget_2 = new QWidget(centralWidget);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(590, 490, 491, 25));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        SaveInputLabel = new QLabel(layoutWidget_2);
        SaveInputLabel->setObjectName(QStringLiteral("SaveInputLabel"));

        horizontalLayout_10->addWidget(SaveInputLabel);

        SaveInputEdit = new QLineEdit(layoutWidget_2);
        SaveInputEdit->setObjectName(QStringLiteral("SaveInputEdit"));

        horizontalLayout_10->addWidget(SaveInputEdit);

        SaveInputButtom = new QPushButton(layoutWidget_2);
        SaveInputButtom->setObjectName(QStringLiteral("SaveInputButtom"));

        horizontalLayout_10->addWidget(SaveInputButtom);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(590, 460, 491, 25));
        horizontalLayout_9 = new QHBoxLayout(widget);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        SaveLabel = new QLabel(widget);
        SaveLabel->setObjectName(QStringLiteral("SaveLabel"));

        horizontalLayout_9->addWidget(SaveLabel);

        SaveLineEdit = new QLineEdit(widget);
        SaveLineEdit->setObjectName(QStringLiteral("SaveLineEdit"));

        horizontalLayout_9->addWidget(SaveLineEdit);

        saveButtom = new QPushButton(widget);
        saveButtom->setObjectName(QStringLiteral("saveButtom"));

        horizontalLayout_9->addWidget(saveButtom);

        ProjetoFinal->setCentralWidget(centralWidget);
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        logText->raise();
        label->raise();
        label_2->raise();
        closeButtom->raise();
        runDemoKalman->raise();
        videoFileOption->raise();
        clearButtom->raise();
        GlobalModeLabel->raise();
        GlobalModeOption->raise();
        ClearPastButtom->raise();
        SaveLineEdit->raise();
        SaveLabel->raise();
        saveButtom->raise();
        layoutWidget_2->raise();
        menuBar = new QMenuBar(ProjetoFinal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1104, 20));
        ProjetoFinal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjetoFinal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjetoFinal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjetoFinal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjetoFinal->setStatusBar(statusBar);

        retranslateUi(ProjetoFinal);

        QMetaObject::connectSlotsByName(ProjetoFinal);
    } // setupUi

    void retranslateUi(QMainWindow *ProjetoFinal)
    {
        ProjetoFinal->setWindowTitle(QApplication::translate("ProjetoFinal", "ProjetoFinal", 0));
        label->setText(QApplication::translate("ProjetoFinal", "video original", 0));
        label_2->setText(QApplication::translate("ProjetoFinal", "video processado", 0));
        futureButtom->setText(QApplication::translate("ProjetoFinal", "Future", 0));
        pastButtom->setText(QApplication::translate("ProjetoFinal", "Past", 0));
        label_3->setText(QApplication::translate("ProjetoFinal", "speed", 0));
        closeButtom->setText(QApplication::translate("ProjetoFinal", "Encerrar", 0));
        runDemoKalman->setText(QApplication::translate("ProjetoFinal", "RunDemoKalman", 0));
        pauseButtom->setText(QApplication::translate("ProjetoFinal", "Pause", 0));
        restartButtom->setText(QApplication::translate("ProjetoFinal", "Restart", 0));
        clearButtom->setText(QApplication::translate("ProjetoFinal", "Clear", 0));
        inputImg->setText(QString());
        outputImg->setText(QString());
        ColorMinLabel->setText(QApplication::translate("ProjetoFinal", "ColorMin", 0));
        ColorMinValue->setText(QApplication::translate("ProjetoFinal", "value", 0));
        ColorMaxLabel->setText(QApplication::translate("ProjetoFinal", "ColorMax", 0));
        ColorMaxValue->setText(QApplication::translate("ProjetoFinal", "value", 0));
        DefineColorLabel->setText(QApplication::translate("ProjetoFinal", "DefinedColor", 0));
        GlobalModeLabel->setText(QApplication::translate("ProjetoFinal", "mode:", 0));
        ClearPastButtom->setText(QApplication::translate("ProjetoFinal", "Clear Past", 0));
        ColorDetectionThresholdLabel->setText(QApplication::translate("ProjetoFinal", "ColorDetectionTh", 0));
        ColorDetectionThresholdSliderValue->setText(QApplication::translate("ProjetoFinal", "30", 0));
        BackGroundSubButtom->setText(QApplication::translate("ProjetoFinal", "BackGroundSubtract", 0));
        ColorDetectionButtom->setText(QApplication::translate("ProjetoFinal", "ColorDetection", 0));
        BorrarButtom->setText(QApplication::translate("ProjetoFinal", "Borrar", 0));
        InitKalmanButtom->setText(QApplication::translate("ProjetoFinal", "Init Kalman", 0));
        raioLabel->setText(QApplication::translate("ProjetoFinal", "raio", 0));
        raioValueLabel->setText(QApplication::translate("ProjetoFinal", "TextLabel", 0));
        SaveInputLabel->setText(QApplication::translate("ProjetoFinal", "input save to: ", 0));
        SaveInputButtom->setText(QApplication::translate("ProjetoFinal", "save", 0));
        SaveLabel->setText(QApplication::translate("ProjetoFinal", "output save to: ", 0));
        saveButtom->setText(QApplication::translate("ProjetoFinal", "save", 0));
    } // retranslateUi

};

namespace Ui {
    class ProjetoFinal: public Ui_ProjetoFinal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINTERFACE_H
